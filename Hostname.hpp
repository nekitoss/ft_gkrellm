
#ifndef HOSTNAME_HPP
#define HOSTNAME_HPP

#include "IMonitorModule.hpp"

class Hostname: public IMonitorModule{

public:
    Hostname();
    void upData(void);
};

#endif