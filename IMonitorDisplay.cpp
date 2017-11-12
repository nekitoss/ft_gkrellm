#include "IMonitorDisplay.hpp"

	IMonitorDisplay::IMonitorDisplay(){}
	IMonitorDisplay::IMonitorDisplay(IMonitorDisplay& src)
	{
		*this = src;
	}
	IMonitorDisplay& IMonitorDisplay::operator=(IMonitorDisplay& src)
	{
		this->_sizeX = src._sizeX;
		this->_sizeY = src._sizeY;
		return (*this);
	}
	IMonitorDisplay::~IMonitorDisplay(){}

	int	IMonitorDisplay::getSizeX()
	{
		return (this->_sizeX);
	}
	int	IMonitorDisplay::getSizeY()
	{
		return (this->_sizeY);
	}