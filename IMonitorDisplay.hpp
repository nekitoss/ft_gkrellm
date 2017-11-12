#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

class IMonitorDisplay
{
public:
	virtual void updateScreenSize() = 0;
	virtual int	getSizeX() =0;
	virtual int	getSizeY() =0;
};

#endif
