#include "IMonitorDisplay.hpp"
#include "TextDisplay.hpp"
#include "GrafDisplay.hpp"

#include "CPU.hpp"
#include "DateTime.hpp"
#include "Hostname.hpp"
#include "IMonitorModule.hpp"
#include "Network.hpp"
#include "OSinfo.hpp"
#include "RAM.hpp"

#include <ncurses.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

void ncur()
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
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	box(stdscr, 0 , 0);

	TextDisplay disp;

	if (disp.getSizeX() < 50 || disp.getSizeY() < 20)
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

    int x = 0;

    int old_x_size = disp.getSizeX();
    int old_y_size = disp.getSizeY();

	while(!exit_requested)
	{

		disp.updateScreenSize();

		if (disp.getSizeX() < 50 || disp.getSizeY() < 20)
		{
			clear();
			endwin();
			std::cerr << "You make size of window too small! Resize it and run again!" << std::endl;
			exit(1);
		}

		if((difftime(time(0), timer)) >= 1 || redraw || old_x_size != disp.getSizeX() || old_y_size != disp.getSizeY())
		{
			// refresh();
			clear();
			// if (old_x_size != disp.getSizeX() || old_y_size != disp.getSizeY())
			// {
				old_x_size = disp.getSizeX();
				old_y_size = disp.getSizeY();
			// }
			x = 0;
			// mvprintw(1, 50, "x=%d", x);
			

			x = disp.draw_host(host1, 0, x); 
			// mvprintw(2, 50, "x=%d", x);
			x = disp.draw_os(os2, 0, x);
			// mvprintw(3, 50, "x=%d", x);
			x = disp.draw_date(date3,0, x);
			// mvprintw(4, 50, "x=%d", x);
			x = disp.draw_cpu(cpu4,0, x);
			// mvprintw(5, 50, "x=%d", x);
			x = disp.draw_ram(ram5,0, x);
			// mvprintw(6, 50, "x=%d", x);
			x = disp.draw_net(net6,0, x);
			// mvprintw(7, 50, "x=%d", x);
			
			time(&timer);
			redraw = false;
			box(stdscr, 0 , 0);
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

	// std::cout << host1.getUser() << std::endl;
	// getch();
	endwin();
	// std::cout << "x=" << disp.getSizeX() << " y=" << disp.getSizeY() << std::endl;
}

void sfml(void)
{
	Hostname	host1;
	OSinfo		os2;
	DateTime	date3;
	CPU			cpu4;
	RAM			ram5;
	Network		net6;

	sf::RenderWindow window(sf::VideoMode(1200, 800), "ft_gkrellm");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		GrafDisplay disp;
		sf::Text text;
		sf::Font font;
		font.loadFromFile("GloriaHallelujah.ttf");
		text.setFont(font);

		disp.updateScreenSize();
		int y = 0;

		sf::Text host;
		host.setFont(font);
		y = disp.draw_host(host1, 0, y, text, host);

		sf::Text os;
		os.setFont(font);
		y = disp.draw_os(os2, 0, y, os);

		sf::Text date;
		date.setFont(font);
		y = disp.draw_date(date3,0, y, date);

		sf::Text cpu;
		cpu.setFont(font);
		sf::Text num;
		num.setFont(font);
		sf::Text load;
		load.setFont(font);
		y = disp.draw_cpu(cpu4,0, y, cpu, num, load);

		sf::Text ram;
		ram.setFont(font);
		sf::Text use;
		use.setFont(font);
		y = disp.draw_ram(ram5,0, y, ram, use);

		sf::Text b;
		b.setFont(font);
		sf::Text g;
		g.setFont(font);
		y = disp.draw_net(net6,0, y, b ,g);
		window.draw(text);
		window.draw(host);
		window.draw(os);
		window.draw(date);
		window.draw(cpu);
		window.draw(num);
		window.draw(load);
		window.draw(ram);
		window.draw(use);
		window.draw(b);
		window.draw(g);

		window.display();
		usleep(300000);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage : ./ft_gkrellm <t> <g>" << std::endl;
		return 1;
	}
	if (argv[1][0] == 't' && !argv[1][1])
		ncur();
	else if (argv[1][0] == 'g' && !argv[1][1])
		sfml();
	return (0);
}
