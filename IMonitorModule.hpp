
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

class IMonitorModule {

public:
    virtual void upData(void) = 0;
    virtual int getIndex(void) const = 0;
    virtual bool getExist(void) const = 0;
    virtual void setExist(void) = 0;
};

#endif
