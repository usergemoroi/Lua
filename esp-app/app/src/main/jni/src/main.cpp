#include "memory/memory.h"
#include "network/socket_server.h"
#include "esp/esp.h"
#include <unistd.h>
#include <cstdio>
#include <pthread.h>
#include <jni.h>
#include <android/log.h>

#define LOG_TAG "ESP_NATIVE"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

static bool g_running = false;
static pthread_t g_esp_thread;

void* espMainLoop(void* arg)
{
    LOGD("ESP main loop started");
    setbuf(stdout, NULL);

    g_socket_server.start();
    LOGD("Socket server started on port 9557");

    pid_t processID = memory_utils::findProcess("com.axlebolt.standoff2");
    while (!processID && g_running)
    {
        LOGD("Waiting for Standoff 2 process...");
        usleep(1000000);
        processID = memory_utils::findProcess("com.axlebolt.standoff2");
    }

    if (!g_running)
    {
        LOGD("ESP stopped before finding process");
        g_socket_server.stop();
        return nullptr;
    }

    LOGD("Found Standoff 2 process with PID: %d", processID);
    memory_utils::initialize(processID);

    uint32_t libUnityBase = 0;
    while (!libUnityBase && g_running)
    {
        LOGD("Searching for libunity.so...");
        usleep(1000000);
        libUnityBase = memory_utils::findModule(processID, "libunity.so");
    }

    if (!g_running)
    {
        LOGD("ESP stopped before finding libunity.so");
        g_socket_server.stop();
        return nullptr;
    }

    LOGD("Found libunity.so at base: 0x%X", libUnityBase);
    ESP esp(libUnityBase);

    while (g_running)
    {
        esp.Render();
        usleep(10000);
    }

    LOGD("ESP main loop stopped");
    g_socket_server.stop();
    return nullptr;
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_espapp_EspService_startNativeEspServer(JNIEnv* env, jobject thiz)
{
    LOGD("startNativeEspServer called");
    
    if (g_running)
    {
        LOGD("ESP server already running");
        return;
    }

    g_running = true;
    
    int result = pthread_create(&g_esp_thread, nullptr, espMainLoop, nullptr);
    if (result != 0)
    {
        LOGE("Failed to create ESP thread: %d", result);
        g_running = false;
        return;
    }

    LOGD("ESP thread created successfully");
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_espapp_EspService_stopNativeEspServer(JNIEnv* env, jobject thiz)
{
    LOGD("stopNativeEspServer called");
    
    if (!g_running)
    {
        LOGD("ESP server not running");
        return;
    }

    g_running = false;
    
    pthread_join(g_esp_thread, nullptr);
    
    LOGD("ESP thread stopped");
}
