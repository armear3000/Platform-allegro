#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <math.h>
#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>

#include "DevicesAndButtons.h"


using namespace std;

#ifndef GLOBALVAR
#define GLOBALVAR

ALLEGRO_DISPLAY *display;

ALLEGRO_FONT *font24 = NULL;

int width = 800;
int height = 600;

mouses mouse;
keyboards kboard;

#endif