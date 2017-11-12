#ifndef TEXTDISPLAY_HPP
# define TEXTDISPLAY_HPP

# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"
# include <ncurses.h>
# include "CPU.hpp"
# include "DateTime.hpp"
# include "Hostname.hpp"
# include "Network.hpp"
# include "OSinfo.hpp"
# include "RAM.hpp"

class TextDisplay : public IMonitorDisplay
{
public:
	// TextDisplay(IMonitorModule *m0, IMonitorModule *m1, IMonitorModule *m2, IMonitorModule *m3, IMonitorModule *m4, IMonitorModule *m5);
	// TextDisplay(IMonitorModule a[]);
	TextDisplay();
	TextDisplay(TextDisplay& src);
	TextDisplay& operator=(TextDisplay& src);
	~TextDisplay();

	void updateScreenSize();
	virtual int	getSizeX();
	virtual int	getSizeY();
	
	void draw_host(Hostname& ptr, int x, int y);
	void draw_os(OSinfo& ptr, int x, int y);
	void draw_date(DateTime& ptr, int x, int y);
	void draw_cpu(CPU& ptr, int x, int y);
	void draw_ram(RAM& ptr, int x, int y);
	void draw_net(Network& ptr, int x, int y);

private:
	int _sizeX;
	int _sizeY;
	// TextDisplay();
	// static const IMonitorModule *all[6];

};

#endif
