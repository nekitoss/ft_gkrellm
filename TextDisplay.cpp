#include "TextDisplay.hpp"

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