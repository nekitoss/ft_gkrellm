
#ifndef OSINFO_HPP
# define OSINFO_HPP

# include "IMonitorModule.hpp"

class OSinfo: public IMonitorModule {

private:
    std::string _os;
public:
    OSinfo();
    void upData();
    std::string getOS(void);
};

#endif
