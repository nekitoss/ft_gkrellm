
#ifndef OSINFO_HPP
# define OSINFO_HPP

# include "IMonitorModule.hpp"

class OSinfo: public IMonitorModule {

private:
    int _index;
    bool _exist;
    std::string _os;

public:
    OSinfo();
    OSinfo(const OSinfo &obj);
    void upData();
    int getIndex(void) const;
    bool getExist(void) const;
    void setExist(void);
    std::string getOS(void) const;
    OSinfo &operator=(const OSinfo &obj);
    ~OSinfo();
};

#endif
