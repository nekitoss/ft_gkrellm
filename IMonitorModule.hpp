
#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <iostream>

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
    void setExist(bool b);
    IMonitorModule &operator=(const IMonitorModule &obj);
    ~IMonitorModule();
};

#endif
