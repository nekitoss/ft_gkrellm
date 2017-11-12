
#ifndef GRAFDISPLAY_HPP
# define GRAFDISPLAY_HPP

# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"
# include "CPU.hpp"
# include "DateTime.hpp"
# include "Hostname.hpp"
# include "Network.hpp"
# include "OSinfo.hpp"
# include "RAM.hpp"
#include <SFML/Graphics.hpp>

class GrafDisplay: public IMonitorDisplay {

public:
    GrafDisplay();
    GrafDisplay(GrafDisplay& src);
    GrafDisplay& operator=(GrafDisplay& src);
    ~GrafDisplay();

    int draw_host(Hostname& ptr, int x, int y, sf::Text &text, sf::Text &host);
    int draw_os(OSinfo& ptr, int x, int y, sf::Text &os);
    int draw_date(DateTime& ptr, int x, int y, sf::Text &date);
    int draw_cpu(CPU& ptr, int x, int y, sf::Text &cpu, sf::Text &num, sf::Text &load);
    int draw_ram(RAM& ptr, int x, int y, sf::Text &ram, sf::Text &use);
    int draw_net(Network& ptr, int x, int y, sf::Text &b, sf::Text &g);

    void updateScreenSize();
    int	getSizeX();
    int	getSizeY();

private:
    int _sizeX;
    int _sizeY;
};


#endif