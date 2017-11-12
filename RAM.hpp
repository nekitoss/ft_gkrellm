
#ifndef RAM_HPP
# define RAM_HPP

# include "IMonitorModule.hpp"

class RAM: public IMonitorModule {

public:
    RAM();
    void upData(void);
};

#endif
