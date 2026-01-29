#include "globals.h"

std::atomic<bool> g_running{true};
int g_server_socket = -1;
int g_client_socket = -1;

uintptr_t g_base = 0;
uintptr_t g_il2cpp = 0;

uintptr_t g_cached_ptr1 = 0;
uintptr_t g_cached_ptr2 = 0;
uintptr_t g_cached_ptr3 = 0;
