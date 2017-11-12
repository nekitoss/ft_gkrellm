
#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule() {
    _exist = true;
}

IMonitorModule::IMonitorModule(const IMonitorModule &obj) {
    *this = obj;
}

int IMonitorModule::getIndex() const {
    return (_index);
}

IMonitorModule & IMonitorModule::operator=(const IMonitorModule &obj) {
    _index = obj.getIndex();
    _exist = obj.getExist();
    return (*this);
}

bool IMonitorModule::getExist(void) const {
    return (_exist);
}

void IMonitorModule::setExist(bool b) {
    _exist = b;
}

IMonitorModule::~IMonitorModule() {
    return;
}