
#include "OSinfo.hpp"

OSinfo::OSinfo() {
    _index = 1;
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

std::string OSinfo::getOS() {
    return _os;
}