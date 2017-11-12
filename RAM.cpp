
#include "RAM.hpp"
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

RAM::RAM() {
    _index = 4;
    _exist = true;
}

void RAM::upData() {
    size_t siz = sizeof(int64_t);
    int64_t ram;
    sysctlbyname("hw.memsize", &ram, &siz, NULL, 0);
    std::ostringstream stream;
    stream << ram / (1024 * 1024);
    _ram = "RAM: ";
    _ram += stream.str();
    _ram += " Mb";

    vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;
    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                          (host_info64_t)&vm_stats, &count))
    {
        long long used_memory = ((int64_t)vm_stats.active_count +
                                 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
        used_memory /= (1024 * 1024);
        _usr = static_cast<int>(used_memory);
    }
}

int RAM::getUseram() const {
    return _usr;
}

RAM::RAM(const RAM &obj) {
    *this = obj;
}

int RAM::getIndex() const {
    return (_index);
}

RAM & RAM::operator=(const RAM &obj) {
    _index = obj.getIndex();
    _exist = obj.getExist();
    return (*this);
}

std::string RAM::getRam(void) const {
    return _ram;
}

bool RAM::getExist(void) const {
    return (_exist);
}

void RAM::setExist(void) {
    _exist = !_exist;
}

RAM::~RAM() {
    return;
}