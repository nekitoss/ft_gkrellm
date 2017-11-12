
#include "CPU.hpp"

CPU::CPU() {
    _index = 3;
}

void CPU::upData() {
    size_t siz = sizeof(int);
    size_t size = sizeof(int64_t);
    int64_t cpy;
    int64_t fam = {0};
    sysctlbyname("hw.cpufrequency_max", &fam, &siz, NULL, 0);
    sysctlbyname("hw.ncpu", &cpy, &size, NULL, 0);
    std::ostringstream stream;
    stream << fam;
    _nc = "frequency: ";
    _nc += stream.str();
    std::ostringstream strea;
    strea << cpy;
    _nc += " number of cores: ";
    _nc += strea.str();
}

std::string CPU::getCPU() {
    return _nc;
}

std::string CPU::getCPULoad() {
    return _cl;
}

void CPU::CPULoad( )
{
    float sysLoadPercentage;
    _cl = "CPU Load: ";
    host_cpu_load_info_data_t cpuinfo;
    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
    {
        unsigned long long totalTicks = 0;
        for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
        sysLoadPercentage = CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
        int l = sysLoadPercentage * 100;
        std::ostringstream stream;
        stream << l;
        _cl += stream.str();
    }
    else
    {
        int l = -1.0f * 100;
        std::ostringstream stream;
        stream << l;
        _cl += stream.str();
    }
}