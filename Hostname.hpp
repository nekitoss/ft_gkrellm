
#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

# include "IMonitorModule.hpp"
# include <climits>

class Hostname: public IMonitorModule{

private:
    int _index;
    bool _exist;
    std::string _u;
    std::string _h;

public:
    Hostname();
    Hostname(const Hostname &obj);
    void upData(void);
    int getIndex(void) const;
    bool getExist(void) const;
    void setExist(void);
    std::string getUser(void) const;
    std::string getHost(void) const;
    Hostname &operator=(const Hostname &obj);
    ~Hostname();
};

#endif