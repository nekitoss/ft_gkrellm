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

	TextDisplay disp;

	if (disp.getSizeX() < 50 || disp.getSizeY() < 40)
	{
		endwin();
		std::cerr << "Terminal window is too small!\nResize it and try again!" << std::endl;
		exit(1);
	}
	

	// std::string str = "test";

	// printw(str.c_str());
	IMonitorModule * module = NULL;
	bool exit_requested = false;
	bool redraw = true;

	time_t timer;
    time(&timer);



	while(!exit_requested)
	{
		disp.updateScreenSize();

		if (disp.getSizeX() < 50 || disp.getSizeY() < 40)
		{
			clear();
			endwin();
			std::cerr << "You make size of window too small! Resize it and run again!" << std::endl;
			exit(1);
		}

		if((difftime(time(0), timer)) >= 1 || redraw)
		{
			clear();
			
			disp.draw_host(host1, 0, 0);
			disp.draw_os(os2, 0, 5);
			disp.draw_date(date3,0, 10);
			disp.draw_cpu(cpu4,0, 15);
			disp.draw_ram(ram5,0, 20);
			disp.draw_net(net6,0, 25);
			
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
				if (module)
					module->setExist();
				redraw = true;
				break;
			case 'd':
				if (module)
					module->setExist();
				redraw = true;
				break;
			default:
				break;
		}
	}

	std::cout << host1.getUser() << std::endl;
	// getch();
	endwin();
	// std::cout << "x=" << disp.getSizeX() << " y=" << disp.getSizeY() << std::endl;
	
	return (0);
}
