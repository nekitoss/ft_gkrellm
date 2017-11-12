
#include "OSinfo.hpp"

OSinfo::OSinfo() {
    _index = 1;
    _exist = true;
}

void OSinfo::upData() {
    size_t siz = 255;
    char os[255];
    char rel[255];
    sysctlbyname("kern.ostype", &os, &siz, NULL, 0);
    std::ostringstream stream;
    stream << os;
    _os = "OS info: ";
    _os += stream.str();
    sysctlbyname("kern.osrelease", &rel, &siz, NULL, 0);
    std::ostringstream strm;
    strm << rel;
    _os += ", Kernel Version: ";
    _os += strm.str();
}

std::string OSinfo::getOS() const {
    return _os;
}


OSinfo::OSinfo(const OSinfo &obj) {
    *this = obj;
}

int OSinfo::getIndex() const {
    return (_index);
}

OSinfo & OSinfo::operator=(const OSinfo &obj) {
    _index = obj.getIndex();
    _exist = obj.getExist();
    _os = obj.getOS();
    return (*this);
}

bool OSinfo::getExist(void) const {
    return (_exist);
}

void OSinfo::setExist(void) {
    _exist = !_exist;
}

OSinfo::~OSinfo() {
    return;
}