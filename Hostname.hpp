
#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

# include "IMonitorModule.hpp"

class Hostname: public IMonitorModule{

// private:
//     std::string _data;

public:
    Hostname();
    void upData(void);
};

#endif