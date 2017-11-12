
#ifndef RAM_HPP
# define RAM_HPP

# include "IMonitorModule.hpp"

class RAM: public IMonitorModule {

private:
    int _index;
    bool _exist;
    std::string _ram;
    int _usr;

public:
    RAM();
    void upData(void);
    RAM(const RAM &obj);
    int getIndex(void) const;
    bool getExist(void) const;
    void setExist(void);
    std::string getRam(void) const;
    int getUseram(void) const;
    RAM &operator=(const RAM &obj);
    ~RAM();
};

#endif
