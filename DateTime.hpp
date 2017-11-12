
#ifndef DATETIME_HPP
# define DATETIME_HPP

# include "IMonitorModule.hpp"

class DateTime: public IMonitorModule {

private:
    std::string _time;
public:
    DateTime();
    void upData(void);
    std::string getTime(void);
};

#endif
