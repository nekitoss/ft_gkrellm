
#include "Hostname.hpp"

Hostname::Hostname(){
    _index = 0;
    _exist = true;
}

void Hostname::upData() {

    char hostname[_SC_HOST_NAME_MAX];
    char username[_SC_LOGIN_NAME_MAX];
    if (gethostname(hostname, _SC_HOST_NAME_MAX))
        _h = "Can't  resolve hostname";
    else
    {
        _h = "Hostname: ";
        _h += hostname;
    }
    if (getlogin_r(username, _SC_LOGIN_NAME_MAX))
        _u = "Can't resolve username";
    else
    {
        _u = "Username: ";
        _u += username;
    }
}

std::string Hostname::getHost() const {
    return _h;
}

std::string Hostname::getUser() const {
    return _u;
}

Hostname::Hostname(const Hostname &obj) {
    *this = obj;
}

int Hostname::getIndex() const {
    return (_index);
}

Hostname & Hostname::operator=(const Hostname &obj) {
    _index = obj.getIndex();
    _exist = obj.getExist();
    _u = obj.getUser();
    _h = obj.getHost();
    return (*this);
}

bool Hostname::getExist(void) const {
    return (_exist);
}

void Hostname::setExist(void) {
    _exist = !_exist;
}

Hostname::~Hostname() {
    return;
}