
#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

# include "IMonitorModule.hpp"
# include <unistd.h>
# include <climits>

class Hostname: public IMonitorModule{

private:
    std::string _u;
    std::string _h;

public:
    Hostname();
    void upData(void);
    std::string getUser(void);
    std::string getHost(void);
};

#endif