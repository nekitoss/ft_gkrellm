
#ifndef CPU_HPP
# define CPU_HPP

# include "IMonitorModule.hpp"

class CPU: public IMonitorModule  {

private:
    std::string _nc;
    std::string _cl;

public:
    CPU();
    void upData(void);
    std::string getCPU(void);
    void CPULoad(void);
    std::string getCPULoad(void);
};

#endif
