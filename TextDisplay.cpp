#include "TextDisplay.hpp"

	class Hostname;
	class OSinfo;
	class DateTime;
	class CPU;
	class RAM;
	class Network;

	// TextDisplay::TextDisplay(){};

	// TextDisplay::TextDisplay(IMonitorModule a[]) : all(a)
	// TextDisplay::TextDisplay(IMonitorModule *m0, IMonitorModule *m1, IMonitorModule *m2, IMonitorModule *m3, IMonitorModule *m4, IMonitorModule *m5) : all{m0, m1, m2, m3, m4, m5}
	TextDisplay::TextDisplay()
	{
		updateScreenSize();
	}
	// TextDisplay(TextDisplay& src)
	// {
	// 	*this = src;
	// }
	// TextDisplay& operator=(TextDisplay& src)
	// {
	// 	this->_sizeX = src._sizeX;
	// 	this->_sizeY = src._sizeY;
	// 	return (*this);
	// }
	// ~TextDisplay(){}

	// int	getSizeX()
	// {
	// 	return (this->_sizeX);
	// }
	// int	getSizeY()
	// {
	// 	return (this->_sizeY);
	// }

	void TextDisplay::updateScreenSize()
	{
		int x=0, y=0;

		getmaxyx(stdscr, y, x);

		this->_sizeX = x;
		this->_sizeY = y;
	}

	void TextDisplay::draw_host(Hostname& ptr)
	{
		ptr.upData();
		mvprintw(0, 0, ptr.getUser().c_str());
		mvprintw(1, 0, ptr.getHost().c_str());
		mvprintw(2, 2, "sraw_host");
	}

	TextDisplay::TextDisplay(TextDisplay& src)
	{
		*this = src;
	}
	
	TextDisplay& TextDisplay::operator=(TextDisplay& src)
	{
		this->_sizeX = src._sizeX;
		this->_sizeY = src._sizeY;
		return (*this);
	}
	
	TextDisplay::~TextDisplay(){}

	int	TextDisplay::getSizeX()
	{
		return (this->_sizeX);
	}
	int	TextDisplay::getSizeY()
	{
		return (this->_sizeY);
	}