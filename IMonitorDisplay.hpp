#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

// # include <>

class IMonitorDisplay
{
public:
	IMonitorDisplay();
	IMonitorDisplay(IMonitorDisplay& src);
	IMonitorDisplay& operator=(IMonitorDisplay& src);
	~IMonitorDisplay();
	void updateScreenSize() = 0;
	int	getSizeX();
	int	getSizeY();

private:
	int _sizeX;
	int _sizeY;

};

#endif
