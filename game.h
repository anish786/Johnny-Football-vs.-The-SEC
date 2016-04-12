#include "std_lib_facilities_3.h"
#include "GUI.h"
#include "Graph.h"
#include <stdlib.h>
#ifndef game_h
#define game_h

using namespace Graph_lib;
using namespace std;

//---------------------------------------------------------------------------------
struct gameboard : Simple_window{
	gameboard(Point xy, int w, int h, const string& title);
	
private:
Button quit_button;
//Image quit_img;
//Image reset_img;
//Image save_img;

static void cb_quit(Address, Address);
void quit();
};

gameboard::gameboard(Point xy, int w, int h, const string& title)
:Simple_window(xy,w,h,title),

quit_button (Point(900,250),125,40,"Quit",cb_quit)
{
	attach(quit_button);

	
}
void gameboard::cb_quit(Address, Address pw){
	reference_to<gameboard>(pw).quit();
}
void gameboard::quit(){
	hide();
}
#endif
