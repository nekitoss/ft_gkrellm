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

	void TextDisplay::draw_host(Hostname& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			mvprintw(y+1, x+1, ptr.getUser().c_str());
			mvprintw(y+2, x+1, ptr.getHost().c_str());
		}
	}

	void TextDisplay::draw_os(OSinfo& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			mvprintw(y+1, x+1, ptr.getOS().c_str());
		}
	}
	void TextDisplay::draw_date(DateTime& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			mvprintw(y+1, x+1, ptr.getTime().c_str());
		}
	}
	void TextDisplay::draw_cpu(CPU& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			mvprintw(y+1, x+1, ptr.getCPU().c_str());
			mvprintw(y+2, x+1, "float: %f", ptr.getCPULoad()); //in %
		}
	}
	void TextDisplay::draw_ram(RAM& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			mvprintw(y+1, x+1, ptr.getRam().c_str());
			mvprintw(y+2, x+1, "float: %d", ptr.getUseram()); //in mb
		}
	}
	void TextDisplay::draw_net(Network& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			mvprintw(y+1, x+1, ptr.getButes().c_str());
			mvprintw(y+2, x+1, ptr.getPuckets().c_str());
		}
	}