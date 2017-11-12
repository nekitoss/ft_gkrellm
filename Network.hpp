
#ifndef NETWORK_HPP
# define NETWORK_HPP

# include "IMonitorModule.hpp"

class Network: public IMonitorModule{

private:
    std::string _bytes;
    std::string _puckets;
    int _index;
    bool _exist;

public:
    Network();
    Network(const Network &obj);
    void upData();
    int getIndex(void) const;
    bool getExist(void) const;
    void setExist(void);
    std::string getButes(void) const;
    std::string getPuckets(void) const;
    Network &operator=(const Network &obj);
    ~Network();
};

#endif
