
#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP


class IMonitorModule {

protected:
    int _index;

public:
    IMonitorModule();
    IMonitorModule(const IMonitorModule &obj);
    virtual void upData(void) = 0;
    int getIndex(void) const;
    IMonitorModule &operator=(const IMonitorModule &obj);
    ~IMonitorModule();
};

#endif
