
#ifndef DATETIME_HPP
# define DATETIME_HPP

# include "IMonitorModule.hpp"

class DateTime: public IMonitorModule {

private:
    int _index;
    bool _exist;
    std::string _time;

public:
    DateTime();
    DateTime(const DateTime &obj);
    void upData(void);
    int getIndex(void) const;
    bool getExist(void) const;
    void setExist(void);
    std::string getTime(void) const;
    DateTime &operator=(const DateTime &obj);
    ~DateTime();
};

#endif
