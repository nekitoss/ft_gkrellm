
#ifndef CPU_HPP
# define CPU_HPP

# include "IMonitorModule.hpp"

class CPU: public IMonitorModule  {

public:
    CPU();
    void upData(void);
};

#endif
