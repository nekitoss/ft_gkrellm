
#ifndef CPU_HPP
# define CPU_HPP

# include "IMonitorModule.hpp"

class CPU: public IMonitorModule  {

private:
    std::string _nc;
    float _cl;
    int _index;
    bool _exist;

public:
    CPU();
    CPU(const CPU &obj);
    void upData(void);
    int getIndex(void) const;
    bool getExist(void) const;
    void setExist(void);
    std::string getCPU(void) const;
    void CPULoad(void);
    float getCPULoad(void) const;
    float GetCPULoad();
    float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
    CPU &operator=(const CPU &obj);
    ~CPU();
};

#endif
