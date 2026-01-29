#include "memory/memory.h"
#include "network/socket_server.h"
#include "esp/esp.h"
#include <unistd.h>
#include <cstdio>

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);

    g_socket_server.start();

    pid_t processID = memory_utils::findProcess("com.axlebolt.standoff2");
    while (!processID)
    {
        usleep(1000000);
        processID = memory_utils::findProcess("com.axlebolt.standoff2");
    }

    memory_utils::initialize(processID);

    uint32_t libUnityBase = 0;
    while (!libUnityBase)
    {
        usleep(1000000);
        libUnityBase = memory_utils::findModule(processID, "libunity.so");
    }

    ESP esp(libUnityBase);

    while (true)
    {
        esp.Render();
        usleep(10000);
    }

    g_socket_server.stop();
    return 0;
}
