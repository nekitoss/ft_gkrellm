#include "IMonitorDisplay.hpp"
#include "CPU.hpp"
#include "DateTime.hpp"
#include "Hostname.hpp"
#include "IMonitorModule.hpp"
#include "Network.hpp"
#include "OSinfo.hpp"
#include "RAM.hpp"
#include "TextDisplay.hpp"
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

	if (disp.getSizeX() < 40 || disp.getSizeY() < 40)
	{
		endwin();
		std::cerr << "Terminal window is too small!\nResize it and try again!" << std::endl;
		exit(1);
	}
	

	// std::string str = "test";

	// printw(str.c_str());
	IMonitorModule *module = host1;
	bool exit_requested = false;
	bool edit_mode = false;
	while(!exit_requested)
	{
		

		refresh();
		
		if ()
		{
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
					host1.setExist();
					break;
				case '2':
					os2.setExist();
					break;
				case '3':
					date3.setExist();
					break;
				case '4':
					cpu4.setExist();
					break;
				case '5':
					ram5.setExist();
					break;
				case '6':
					net6.setExist();
					break;
				case 'm':
					break;
				case ' ':
					break;
				default:
					break;
			}
		}
	}


	// getch();
	endwin();
	std::cout << "x=" << disp.getSizeX() << " y=" << disp.getSizeY() << std::endl;
	
	return (0);
}
/*
  main_win = initscr();
  cbreak();

  screen_max = Vector(COLS, LINES);
  int info_panel_h = 4;
  info_win = newwin(screen_max.y - info_panel_h - 2, screen_max.x - 2,
                    screen_min.y + 1, screen_min.x + 1);
  stats_win = newwin(info_panel_h - 1, screen_max.x - 10,
                    (screen_max.y - info_panel_h), 2);
  main_win = newwin(screen_max.y, screen_max.x, 0, 0);
  
*/