#ifndef TEXTDISPLAY_HPP
# define TEXTDISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include <ncurses.h>

class TextDisplay : public IMonitorDisplay
{
public:
	TextDisplay();
	void updateScreenSize();

// protected:
// 	int _sizeX;
// 	int _sizeY;

// private:

};

#endif
