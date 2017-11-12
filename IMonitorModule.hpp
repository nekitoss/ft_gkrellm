
#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <iostream>
# include <ctime>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <iostream>
# include <sstream>
# include <sys/sysctl.h>
# include <sys/types.h>
# include <unistd.h>
# include <mach/mach_host.h>

class IMonitorModule {

protected:
    int _index;
    bool _exist;

public:
    IMonitorModule();
    IMonitorModule(const IMonitorModule &obj);
    virtual void upData(void) = 0;
    int getIndex(void) const;
    bool getExist(void) const;
    void setExist(void);
    IMonitorModule &operator=(const IMonitorModule &obj);
    ~IMonitorModule();
};

#endif
