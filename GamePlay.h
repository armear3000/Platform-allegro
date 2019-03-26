
#include "GlobalVar.h"

#ifndef GAMEPLAY
#define GAMEPLAY

class titles {
public:
	int state;
	void init(int s) {
		state = s;
	}
	void draw(double x, double y, double sizet) {
		al_draw_rectangle(x, y, x + sizet, y + sizet, al_map_rgb(50, 50, 50), 1);
	}
	void destroy();
};
class cmap {
public:

	titles t[100][40];
	int maxt_x, maxt_y;
	double sizet;

	void draw(double px, double py);

	cmap();
};
cmap::cmap() {
	sizet = 30;
	maxt_x = 100;
	maxt_y = 40;
}
void cmap::draw(double px,double py)
{
	int min_x = (px - width / 2) / sizet - 1;
	int min_y = (py - height / 2) / sizet - 1;
	int max_x = (px + width / 2) / sizet + 1;
	int max_y = (py + height / 2) / sizet + 1;

	if (min_x < 0) min_x = 0;
	else if (max_x > maxt_x - 1) max_x = maxt_x - 1;
	if (min_y < 0) min_y = 0;
	else if (max_y > maxt_y - 1) max_y = maxt_y - 1;



	for (int y = min_y; y < max_y; y++) {
		for (int x = min_x; x < max_x; x++) {
			t[x][y].draw(x*sizet, y*sizet, sizet);
		}
	}

	al_draw_line(0, height*7/8, width, height*7/8, al_map_rgb(255,0,0), 1);
}

class cplayer {
public:
	bool worth;
	double x, y;
	QVector sizeXY;
	QVector sizeXYdiv2;

	

	QVector route;
	QVector speed;
	void control_keyboard();
	void mat(cmap m);
	void draw();
	cplayer();
};
cplayer::cplayer(){
	x = width/2; y = height/2;
	sizeXY.init(50,100);
	sizeXYdiv2.init(25, 50);
	route.init(0, 0);
	speed.init(5, 0);

}
void cplayer::control_keyboard()
{
	if (speed.y == 0 && worth)
		if (kboard.key[ALLEGRO_KEY_SPACE] || kboard.key[ALLEGRO_KEY_UP]) {
			speed.y = -6; 
			worth = false;
		}

	route.x = -(kboard.key[ALLEGRO_KEY_A] || kboard.key[ALLEGRO_KEY_LEFT]);
	route.x += (kboard.key[ALLEGRO_KEY_D] || kboard.key[ALLEGRO_KEY_RIGHT]);
	

}
void cplayer::mat(cmap m)
{
	x += route.x * speed.x;



	speed.y += 0.2;
	
	if (y + speed.y + sizeXYdiv2.y > height * 7 / 8) {
		y = height * 7 / 8 - sizeXYdiv2.y;
		speed.y = 0;
		worth = true;
	}

	y += speed.y;
}
void cplayer::draw(){
	al_draw_rectangle(x - sizeXYdiv2.x, y - sizeXYdiv2.y, x + sizeXYdiv2.x, y + sizeXYdiv2.y, al_rgb(255, 0, 0), 1);
}

///////////////////

class ClassGamePlay
{
public:
	cmap map;
	cplayer player;
	ALLEGRO_TRANSFORM camera;

	void init();
	void matmousedown();
	void matmouseup();
	void matdown();
	void matup();
	void mat();
	void draw();
	void destroy();
	void refresh();
	void timers(ALLEGRO_EVENT e);

};

///////////////////

void ClassGamePlay::init() {


	return;
}
void ClassGamePlay::matmousedown() {

	return;
}
void ClassGamePlay::matmouseup() {

	return;
}
void ClassGamePlay::matdown() {


	

	return;
}
void ClassGamePlay::matup() {


	return;
}
void ClassGamePlay::mat() {
	player.control_keyboard();
	player.mat(map);

	return;
}
void ClassGamePlay::draw() {
	al_identity_transform(&camera);
	al_translate_transform(&camera, -player.x + width / 2 , -player.y + height / 2 );
	al_use_transform(&camera);

	map.draw(player.x,player.y);
	player.draw();

	al_identity_transform(&camera);
	al_use_transform(&camera);
	return;
}
void ClassGamePlay::refresh() {


	return;
}
void ClassGamePlay::timers(ALLEGRO_EVENT e)
{

}
void ClassGamePlay::destroy() {

}


#endif
