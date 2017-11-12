
#include "GrafDisplay.hpp"

const int space_after_data = 30;
const int shift_data_x = 200;
const int space_before_data = 30;

GrafDisplay::GrafDisplay()
{
    updateScreenSize();
}

void GrafDisplay::updateScreenSize()
{
    this->_sizeX = 1200;
    this->_sizeY = 800;
}

GrafDisplay::GrafDisplay(GrafDisplay& src)
{
    *this = src;
}

GrafDisplay& GrafDisplay::operator=(GrafDisplay& src)
{
    this->_sizeX = src._sizeX;
    this->_sizeY = src._sizeY;
    return (*this);
}

GrafDisplay::~GrafDisplay(){}

int	GrafDisplay::getSizeX()
{
    return (this->_sizeX);
}
int	GrafDisplay::getSizeY()
{
    return (this->_sizeY);
}

int GrafDisplay::draw_host(Hostname& ptr, int x, int y, sf::Text &text, sf::Text &host)
{
    if (ptr.getExist())
    {
        ptr.upData();
        y += space_before_data + 30;
        text.setString(ptr.getUser().c_str());
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + shift_data_x, y);
        text.setStyle(sf::Text::Bold);

        host.setString(ptr.getHost().c_str());
        host.setCharacterSize(24);
        host.setFillColor(sf::Color::Black);
        host.setPosition(x + shift_data_x, y + 30);
        host.setStyle(sf::Text::Bold);
        y += (space_after_data) + 30;
    }
    return (y);
}

int GrafDisplay::draw_os(OSinfo& ptr, int x, int y, sf::Text &os)
{
    if (ptr.getExist())
    {
        ptr.upData();
        y += space_before_data;

        os.setString(ptr.getOS().c_str());
        os.setCharacterSize(24);
        os.setFillColor(sf::Color::Black);
        os.setPosition(x + shift_data_x, y + 30);
        os.setStyle(sf::Text::Bold);
        y += (space_after_data) + 30;
    }
    return (y);
}
int GrafDisplay::draw_date(DateTime& ptr, int x, int y, sf::Text &date)
{
    if (ptr.getExist())
    {
        ptr.upData();
        y += space_before_data;

        date.setString(ptr.getTime().c_str());
        date.setCharacterSize(24);
        date.setFillColor(sf::Color::Black);
        date.setPosition(x + shift_data_x, y + 30);
        date.setStyle(sf::Text::Bold);

        y += (space_after_data) + 30;
    }
    return (y);
}
int GrafDisplay::draw_cpu(CPU& ptr, int x, int y, sf::Text &cpu, sf::Text &num, sf::Text &load)
{
    if (ptr.getExist())
    {
        ptr.upData();
        y += space_before_data;

        cpu.setString(ptr.getCPU().c_str());
        cpu.setCharacterSize(24);
        cpu.setFillColor(sf::Color::Black);
        cpu.setPosition(x + shift_data_x, y + 30);
        cpu.setStyle(sf::Text::Bold);

        num.setString(ptr.getNumber().c_str());
        num.setCharacterSize(24);
        num.setFillColor(sf::Color::Black);
        num.setPosition(x + shift_data_x, y + 60);
        num.setStyle(sf::Text::Bold);

        char temp[256];
        sprintf(temp, "%f", ptr.getCPULoad());

        load.setString(temp);
        load.setCharacterSize(24);
        load.setFillColor(sf::Color::Black);
        load.setPosition(x + shift_data_x, y + 90);
        load.setStyle(sf::Text::Bold);

        y += (space_after_data) + 30;
    }
    return (y);
}
int GrafDisplay::draw_ram(RAM& ptr, int x, int y, sf::Text &ram, sf::Text &use)
{
    if (ptr.getExist())
    {
        ptr.upData();

        y += space_before_data + 30;
        ram.setString(ptr.getRam().c_str());
        ram.setCharacterSize(24);
        ram.setFillColor(sf::Color::Black);
        ram.setPosition(x + shift_data_x, y + 60);
        ram.setStyle(sf::Text::Bold);



        char temp[256];
        sprintf(temp, "%d", ptr.getUseram());

        use.setString(temp);
        use.setCharacterSize(24);
        use.setFillColor(sf::Color::Black);
        use.setPosition(x + shift_data_x, y + 90);
        use.setStyle(sf::Text::Bold);

        y += (space_after_data) + 30;
    }
    return (y);
}
int GrafDisplay::draw_net(Network& ptr, int x, int y, sf::Text &b, sf::Text &g)
{
    if (ptr.getExist())
    {
        ptr.upData();
        y += space_before_data + 60;

        b.setString(ptr.getButes().c_str());
        b.setCharacterSize(24);
        b.setFillColor(sf::Color::Black);
        b.setPosition(x + shift_data_x, y + 30);
        b.setStyle(sf::Text::Bold);

        g.setString(ptr.getPuckets().c_str());
        g.setCharacterSize(24);
        g.setFillColor(sf::Color::Black);
        g.setPosition(x + shift_data_x, y + 60);
        g.setStyle(sf::Text::Bold);

        y += (space_after_data);
    }
    return (y);
}