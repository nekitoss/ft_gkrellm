#ifndef TEXTDISPLAY_HPP
# define TEXTDISPLAY_HPP

#include "IMonitorDisplay.hpp"

class TextDisplay : public IMonitorDisplay
{
public:
	TextDisplay();
	TextDisplay(TextDisplay& src);
	TextDisplay& operator=(TextDisplay& src);
	~TextDisplay();
	void updateScreenSize();
	int	getSizeX();
	int	getSizeY();

// protected:
// 	int _sizeX;
// 	int _sizeY;

// private:

};

#endif
