#include "IMonitorDisplay.hpp"
#include "TextDisplay.hpp"

#include "CPU.hpp"
#include "DateTime.hpp"
#include "Hostname.hpp"
#include "IMonitorModule.hpp"
#include "Network.hpp"
#include "OSinfo.hpp"
#include "RAM.hpp"

#include <ncurses.h>
#include <iostream>
#include <string>


int main()
{
	Hostname	host1;
	OSinfo		os2;
	DateTime	date3;
	CPU			cpu4;
	RAM			ram5;
	Network		net6;

	// IMonitorModule *all[6] = {&host1, &os2, &date3, &cpu4, &ram5, &net6};

	initscr();
	noecho();
	curs_set(0);
	clear();
	keypad(stdscr, true);
	nodelay(stdscr, true);

/*
• Hostname/username module
• OS info module
• Date/time module
• CPU module (Model, clock speed, number of cores, activity, ...)
• RAM module
• Network throughput module
*/

	// TextDisplay disp(new IMonitorModule arr{&host1, &os2, &date3, &cpu4, &ram5, &net6});
	// TextDisplay disp(all);
	TextDisplay disp;

	if (disp.getSizeX() < 40 || disp.getSizeY() < 40)
	{
		endwin();
		std::cerr << "Terminal window is too small!\nResize it and try again!" << std::endl;
		exit(1);
	}
	

	// std::string str = "test";

	// printw(str.c_str());
	IMonitorModule * module = &host1;
	bool exit_requested = false;
	bool redraw = false;

	time_t timer;
    time(&timer);



	while(!exit_requested)
	{
		
		if((difftime(time(0), timer)) >= 1 || redraw)
		{
			clear();
			disp.draw_host(host1);
			time(&timer);
			redraw = false;
			refresh();
		}

		switch (getch()) {
			case 'q':
				exit_requested = true;
				break;
			case 27:
				exit_requested = true;
				break;
			case KEY_UP:
				break;
			case KEY_DOWN:
				break;
			case KEY_LEFT:
				break;
			case KEY_RIGHT:
				break;
			case '1':
				module = &host1;
				break;
			case '2':
				module = &os2;
				break;
			case '3':
				module = &date3;
				break;
			case '4':
				module = &cpu4;
				break;
			case '5':
				module = &ram5;
				break;
			case '6':
				module = &net6;
				break;
			case ' ':
				module->setExist();
				redraw = true;
				break;
			case 'd':
				module->setExist();
				break;
			default:
				break;
		}
	}

	std::cout << host1.getUser() << std::endl;
	// getch();
	endwin();
	std::cout << "x=" << disp.getSizeX() << " y=" << disp.getSizeY() << std::endl;
	
	return (0);
}
