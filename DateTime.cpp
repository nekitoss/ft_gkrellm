
#include "DateTime.hpp"
#include <iomanip>
DateTime::DateTime() {
    _index = 2;
}

void DateTime::upData() {
    time_t t = time(0);
    struct tm * now = localtime( & t );

    std::stringstream ss;
    ss << (now->tm_year + 1900) << '-'
       << std::setfill('0') << std::setw(2)
       << (now->tm_mon + 1) << '-'
       << std::setfill('0') << std::setw(2)
       <<  now->tm_mday << ' '
       << std::setfill('0') << std::setw(2)
       <<  now->tm_hour << ':'
       << std::setfill('0') << std::setw(2)
       <<  now->tm_min << ':'
       << std::setfill('0') << std::setw(2)
       <<  now->tm_sec;
    _time = "Current date/time: ";
    _time += ss.str();
}

std::string DateTime::getTime() {
    return _time;
}