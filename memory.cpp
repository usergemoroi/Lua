#include "memory.h"

int memory_utils::pid_ = -1;

void memory_utils::initialize(int pid)
{
    pid_ = pid;
}

bool memory_utils::read_memory(void *address, void *buffer, size_t size)
{
    return process_vm(address, buffer, size, false);
}

bool memory_utils::write_memory(void *address, void *buffer, size_t size)
{
    return process_vm(address, buffer, size, true);
}

bool memory_utils::is_address_valid(uint64_t addr)
{
    if (addr == 0 || addr <= 0x1000)
    {
        return false;
    }
    return virtual_to_physical(addr);
}

bool memory_utils::process_vm(void *address, void *buffer, size_t size, bool is_write)
{
    struct iovec local[1];
    struct iovec remote[1];

    local[0].iov_base = buffer;
    local[0].iov_len = size;
    remote[0].iov_base = address;
    remote[0].iov_len = size;

    if (pid_ < 0)
    {
        return false;
    }

    int syscall_num = is_write ? 348 : 347;
    ssize_t bytes = syscall(syscall_num, pid_, local, 1, remote, 1, 0);
    return bytes == static_cast<ssize_t>(size);
}

bool memory_utils::virtual_to_physical(uint64_t vaddr)
{
    static int page_size = getpagesize();
    int fd = get_fd();
    if (fd < 0)
    {
        return false;
    }

    unsigned long v_page_index = vaddr / page_size;
    off_t pfn_item_offset = static_cast<off_t>(v_page_index * sizeof(uint64_t));

    uint64_t item;
    if (lseek(fd, pfn_item_offset, SEEK_SET) < 0)
    {
        return false;
    }

    if (::read(fd, &item, sizeof(uint64_t)) != sizeof(uint64_t))
    {
        return false;
    }

    return (item & (1ULL << 63)) != 0;
}

int memory_utils::get_fd()
{
    static int fd = -1;
    if (fd < 0)
    {
        char filename[32];
        snprintf(filename, sizeof(filename), "/proc/%d/pagemap", pid_);
        fd = open(filename, O_RDONLY);
    }
    return fd;
}
