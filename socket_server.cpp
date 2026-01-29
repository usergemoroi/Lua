#include "socket_server.h"
#include <cstring>
#include <netinet/tcp.h>
#include <arpa/inet.h>

socket_server g_socket_server(9557);

socket_server::socket_server(int port) : m_port(port) {}

socket_server::~socket_server()
{
    stop();
}

bool socket_server::start()
{
    if (m_running) return true;

    m_server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_server_socket < 0) return false;

    int opt = 1;
    setsockopt(m_server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    setsockopt(m_server_socket, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(m_port);

    if (bind(m_server_socket, (sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        close(m_server_socket);
        return false;
    }

    if (listen(m_server_socket, 5) < 0)
    {
        close(m_server_socket);
        return false;
    }

    m_running = true;
    m_thread = std::thread(&socket_server::server_thread, this);
    return true;
}

void socket_server::stop()
{
    m_running = false;

    if (m_server_socket >= 0)
    {
        close(m_server_socket);
        m_server_socket = -1;
    }

    if (m_thread.joinable())
        m_thread.join();
}

void socket_server::set_player_data(const uint8_t* data, size_t size)
{
    std::lock_guard<std::mutex> lock(m_data_mutex);
    m_binary_data.assign(data, data + size);
}

void socket_server::server_thread()
{
    while (m_running)
    {
        sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);

        int client_socket = accept(m_server_socket, (sockaddr *)&client_addr, &client_len);
        if (client_socket < 0)
        {
            if (!m_running)
                break;
            continue;
        }

        int nodelay = 1;
        setsockopt(client_socket, IPPROTO_TCP, TCP_NODELAY, &nodelay, sizeof(nodelay));
        
        int rcvbuf = 65536;
        setsockopt(client_socket, SOL_SOCKET, SO_RCVBUF, &rcvbuf, sizeof(rcvbuf));
        
        std::thread([this, client_socket]() {
            handle_client(client_socket);
            close(client_socket);
        }).detach();
    }
}

void socket_server::handle_client(int client_socket)
{
    char buffer[512];

    while (m_running)
    {
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(client_socket, &readfds);
        
        struct timeval tv;
        tv.tv_sec = 0;
        tv.tv_usec = 2000;
        
        int sel = select(client_socket + 1, &readfds, NULL, NULL, &tv);
        if (sel <= 0) continue;
        
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

        if (bytes_received <= 0) break;

        {
            std::lock_guard<std::mutex> lock(m_data_mutex);
            if (!m_binary_data.empty()) {
                send(client_socket, (const char*)m_binary_data.data(), m_binary_data.size(), 0);
                continue;
            }
        }
        
        std::string response = "OK\n";
        send(client_socket, response.c_str(), response.length(), 0);
    }
}
