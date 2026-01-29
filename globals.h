#pragma once
#include <cstdint>
#include <atomic>

extern std::atomic<bool> g_running;
extern int g_server_socket;
extern int g_client_socket;

extern uintptr_t g_base;
extern uintptr_t g_il2cpp;

extern uintptr_t g_cached_ptr1;
extern uintptr_t g_cached_ptr2;
extern uintptr_t g_cached_ptr3;
