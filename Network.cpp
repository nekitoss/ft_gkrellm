
#include "Network.hpp"
#include <net/route.h>
#include <net/if.h>

Network::Network() {
    _index = 5;
    _exist = true;
}

void Network::upData() {
    int          mib[6];
    char         *lim;
    char         *next;
    size_t       len;
    struct       if_msghdr *ifm;
    long int     ipackets = 0;
    long int     opackets = 0;
    long int     ibytes = 0;
    long int     obytes = 0;
    mib[0]= CTL_NET;
    mib[1]= PF_ROUTE;
    mib[2]= 0;
    mib[3]= 0;
    mib[4]= NET_RT_IFLIST2;
    mib[5]= 0;
    sysctl(mib, 6, NULL, &len, NULL, 0);
    char buf[len];
    sysctl(mib, 6, buf, &len, NULL, 0);
    lim = buf + len;
    for (next = buf; next < lim; )
    {
        ifm = (struct if_msghdr *)next;
        next += ifm->ifm_msglen;

        if (ifm->ifm_type == RTM_IFINFO2)
        {
            struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;

            if(if2m->ifm_data.ifi_type!=18)
            {
                opackets += if2m->ifm_data.ifi_opackets;
                ipackets += if2m->ifm_data.ifi_ipackets;
                obytes   += if2m->ifm_data.ifi_obytes;
                ibytes   += if2m->ifm_data.ifi_ibytes;
            }
        }
    }
    std::ostringstream stream;
    stream << static_cast<double>(ibytes) / 1000000000.0;
    _bytes = "Bytes in: ";
    _bytes += stream.str().substr(0, 7);
    _bytes += " Gb";
    std::ostringstream stream2;
    stream2 << static_cast<double>(obytes) / 1000000.0;
    _bytes += " Out: ";
    _bytes += stream2.str().substr(0, 7);
    _bytes += " Mb";
    std::ostringstream stream3;
    stream3 <<  ipackets;
    _puckets = "Packets in: ";
    _puckets += stream3.str();
    std::ostringstream stream4;
    stream4 << opackets;
    _puckets += " Out: ";
    _puckets += stream4.str();
}

std::string Network::getButes() const {
    return _bytes;
}

std::string Network::getPuckets() const {
    return _puckets;
}

Network::Network(const Network &obj) {
    *this = obj;
}

int Network::getIndex() const {
    return (_index);
}

Network & Network::operator=(const Network &obj) {
    _index = obj.getIndex();
    _exist = obj.getExist();
    _puckets = obj.getPuckets();
    _bytes = obj.getButes();
    return (*this);
}

bool Network::getExist(void) const {
    return (_exist);
}

void Network::setExist(void) {
    _exist = !_exist;
}

Network::~Network() {
    return;
}