
#include "CPU.hpp"

#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

CPU::CPU() {
    _index = 3;
    _exist = true;
}

void CPU::upData() {
    size_t siz = 255;
    size_t size = sizeof(int);
    int cpy;
    char fam[255];
    sysctlbyname("machdep.cpu.brand_string", &fam, &siz, NULL, 0);
    sysctlbyname("hw.ncpu", &cpy, &size, NULL, 0);
    std::ostringstream stream;
    stream << fam;
    _nc = "CPU: ";
    _nc += stream.str();
    std::ostringstream strea;
    strea << cpy;
    _n = "Number of cores: ";
    _n += strea.str();
    _cl = GetCPULoad() * 100.0f;
}

std::string CPU::getCPU() const {
    return _nc;
}

std::string CPU::getNumber() const {
    return _n;
}

float CPU::getCPULoad() const {
    return _cl;
}

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

float CPU::GetCPULoad()
{
    host_cpu_load_info_data_t cpuinfo;
    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
    {
        unsigned long long totalTicks = 0;
        for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
        return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
    }
    else return -1.0f;
}

float CPU::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
    unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
    unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
    float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
    _previousTotalTicks = totalTicks;
    _previousIdleTicks  = idleTicks;
    return ret;
}


CPU::CPU(const CPU &obj) {
    *this = obj;
}

int CPU::getIndex() const {
    return (_index);
}

CPU & CPU::operator=(const CPU &obj) {
    _index = obj.getIndex();
    _exist = obj.getExist();
    _nc = obj.getCPU();
    _cl = obj.getCPULoad();
    return (*this);
}

bool CPU::getExist(void) const {
    return (_exist);
}

void CPU::setExist(void) {
    _exist = !_exist;
}

CPU::~CPU() {
    return;
}