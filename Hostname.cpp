
#include "Hostname.hpp"

Hostname::Hostname(){
    _index = 0;
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

std::string Hostname::getHost() {
    return _h;
}

std::string Hostname::getUser() {
    return _u;
}