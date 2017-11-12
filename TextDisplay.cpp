#include "TextDisplay.hpp"

	class Hostname;
	class OSinfo;
	class DateTime;
	class CPU;
	class RAM;
	class Network;

	const int space_after_data = 1;
	const int shift_data_x = 2;
	const int space_before_data = 1;
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





	int TextDisplay::draw_host(Hostname& ptr, int x, int y)
	{
		// attron(COLOR_PAIR(1));
		// WINDOW * local_win = newwin(10, 10, 1, 1);
		 // wbkgd(local_win, COLOR_PAIR(1));
		// wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
		// wrefresh(local_win);
		// getch();
		// refresh();
		// delwin(local_win);
		// attroff(COLOR_PAIR(1));
		if (ptr.getExist())
		{
			ptr.upData();
			y += space_before_data;
			mvprintw(y, x + shift_data_x, ptr.getUser().c_str());
			mvprintw(++y, x + shift_data_x, ptr.getHost().c_str());
			y += (space_after_data);
		}
		return (y);
	}

	int TextDisplay::draw_os(OSinfo& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			y += space_before_data;
			mvprintw(y, x + shift_data_x, ptr.getOS().c_str());
			y += (space_after_data);
		}
		return (y);
	}
	int TextDisplay::draw_date(DateTime& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			y += space_before_data;
			mvprintw(y, x + shift_data_x, ptr.getTime().c_str());
			y += (space_after_data);
		}
		return (y);
	}
	int TextDisplay::draw_cpu(CPU& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			y += space_before_data;
			mvprintw(y, x + shift_data_x, ptr.getCPU().c_str());
			mvprintw(++y, x + shift_data_x, ptr.getNumber().c_str());

			int right = (400 - ptr.getCPULoad()) / 10;
			int left = 40 - right;
			// mvprintw(++y, x + shift_data_x, "L=%d; R=%d; PTR=%f", left, right, ptr.getCPULoad()); //in %
			++y;
			mvaddch(y, x++ + shift_data_x, '[' | A_BOLD | COLOR_PAIR(1));
			for (int i = 0; i < left; i++)
				mvaddch(y, x + shift_data_x + i, '#' | A_BOLD | A_REVERSE | COLOR_PAIR(4));
			for (int i = 0; i < right; i++)
				mvaddch(y, x + shift_data_x + left + i, '-' );
			mvaddch(y, x + shift_data_x + left + right, ']' | A_BOLD | COLOR_PAIR(1));
			// mvprintw(++y, x + shift_data_x, "%c", ptr.getCPULoad()); //in %

			y += (space_after_data);
		}
		return (y);
	}
	int TextDisplay::draw_ram(RAM& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			y += space_before_data;
			mvprintw(y, x + shift_data_x, ptr.getRam().c_str());
			// mvprintw(++y, x + shift_data_x, "float: %d", ptr.getUseram()); //in mb
			int right = (400 - (ptr.getUseram()) / 81.92) / 10;
			int left = 40 - right;
			// mvprintw(++y, x + shift_data_x, "L=%d; R=%d; PTR=%d", left, right, ptr.getUseram()); //in %
			++y;
			mvaddch(y, x++ + shift_data_x, '[' | A_BOLD | COLOR_PAIR(1));
			for (int i = 0; i < left; i++)
				mvaddch(y, x + shift_data_x + i, '#' | A_BOLD | A_REVERSE | COLOR_PAIR(4));
			for (int i = 0; i < right; i++)
				mvaddch(y, x + shift_data_x + left + i, '-' );
			mvaddch(y, x + shift_data_x + left + right, ']' | A_BOLD | COLOR_PAIR(1));
			y += (space_after_data);
		}
		return (y);
	}
	int TextDisplay::draw_net(Network& ptr, int x, int y)
	{
		if (ptr.getExist())
		{
			ptr.upData();
			y += space_before_data;
			mvprintw(y, x + shift_data_x, ptr.getButes().c_str());
			mvprintw(++y, x + shift_data_x, ptr.getPuckets().c_str());
			y += (space_after_data);
		}
		return (y);
	}