#pragma once
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class socket_server
{
public:
    socket_server(int port);
    ~socket_server();

    bool start();
    void stop();
    void set_player_data(const uint8_t* data, size_t size);
    bool is_running() const { return m_running; }

private:
    void server_thread();
    void handle_client(int client_socket);

    int m_port;
    int m_server_socket = -1;
    std::atomic<bool> m_running{false};
    std::thread m_thread;
    std::mutex m_data_mutex;
    std::vector<uint8_t> m_binary_data;
};

extern socket_server g_socket_server;
