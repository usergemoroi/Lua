#pragma once
#include <cstdint>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <cstring>
#include <cstdlib>
#include <initializer_list>

class memory_utils
{
public:
    static void initialize(int pid);
    static bool read_memory(void *address, void *buffer, size_t size);
    static bool write_memory(void *address, void *buffer, size_t size);
    static bool is_address_valid(uint64_t addr);

    template <typename T>
    static T read(uint64_t addr)
    {
        T data{};
        if (addr == 0) return data;
        read_memory(reinterpret_cast<void *>(addr), &data, sizeof(T));
        return data;
    }
    
    template <typename T>
    static T read_safe(uint64_t addr)
    {
        T data{};
        if (!is_address_valid(addr)) return data;
        read_memory(reinterpret_cast<void *>(addr), &data, sizeof(T));
        return data;
    }
    
    template <typename T, size_t N>
    static void read_batch(uint64_t base_addr, const uint32_t (&offsets)[N], T (&out)[N])
    {
        if (base_addr == 0) {
            for (size_t i = 0; i < N; i++) out[i] = T{};
            return;
        }
        for (size_t i = 0; i < N; i++) {
            out[i] = read<T>(base_addr + offsets[i]);
        }
    }
    
    template <typename T>
    static T read_chain(uint64_t base, std::initializer_list<uint32_t> offsets)
    {
        uint64_t addr = base;
        auto it = offsets.begin();
        auto end = offsets.end();
        
        while (it != end) {
            uint32_t off = *it++;
            if (it == end) {
                return read<T>(addr + off);
            }
            addr = read<uint32_t>(addr + off);
            if (addr == 0) return T{};
        }
        return T{};
    }

    static int open_proccess_memory(const pid_t pid)
    {
        char name[255] = {0};
        sprintf(name, "/proc/%d/mem", pid);
        return open(name, O_RDWR);
    }

    template <typename T>
    static ssize_t write(uint64_t address, T value)
    {
        if (address == 0) return -1;
        if (write_memory(reinterpret_cast<void*>(address), &value, sizeof(T)))
            return sizeof(T);
        return -1;
    }
    
    template <typename T>
    static ssize_t write_safe(uint64_t address, T value)
    {
        if (!is_address_valid(address))
            return -1;
        if (write_memory(reinterpret_cast<void*>(address), &value, sizeof(T)))
            return sizeof(T);
        return -1;
    }

    static pid_t findProcess(const char* name)
    {
        DIR* dir = opendir("/proc");
        if (!dir) return 0;

        struct dirent* entry;
        while ((entry = readdir(dir)))
        {
            if (entry->d_type != DT_DIR) continue;
            
            long pid = strtol(entry->d_name, nullptr, 10);
            if (pid <= 0) continue;

            char path[64], cmdline[256] = {0};
            snprintf(path, sizeof(path), "/proc/%ld/cmdline", pid);
            
            FILE* f = fopen(path, "r");
            if (!f) continue;
            fread(cmdline, 1, 255, f);
            fclose(f);

            if (strstr(cmdline, name))
            {
                closedir(dir);
                return (pid_t)pid;
            }
        }
        closedir(dir);
        return 0;
    }

    static uintptr_t findModule(pid_t pid, const char* name)
    {
        char path[64];
        snprintf(path, sizeof(path), "/proc/%d/maps", pid);
        
        FILE* f = fopen(path, "r");
        if (!f) return 0;

        char line[512];
        while (fgets(line, sizeof(line), f))
        {
            if (strstr(line, name))
            {
                uintptr_t base = 0;
                sscanf(line, "%x", (unsigned int*)&base);
                fclose(f);
                return base;
            }
        }
        fclose(f);
        return 0;
    }

private:
    static int pid_;
    static bool process_vm(void *address, void *buffer, size_t size, bool is_write);
    static bool virtual_to_physical(uint64_t vaddr);
    static int get_fd();
};

class MemoryHelper
{
public:
    template <typename T>
    T read(uintptr_t address) { return memory_utils::read<T>(address); }

    template <typename T>
    ssize_t write(uintptr_t address, T val) { return memory_utils::write<T>(address, val); }
};

inline MemoryHelper c_memory_utils;
