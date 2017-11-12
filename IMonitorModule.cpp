
#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule() {
    return;
}

IMonitorModule::IMonitorModule(const IMonitorModule &obj) {
    *this = obj;
}

int IMonitorModule::getIndex() const {
    return (_index);
}

IMonitorModule & IMonitorModule::operator=(const IMonitorModule &obj) {
    _index = obj.getIndex();
    return (*this);
}
