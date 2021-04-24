#pragma once
#include "check_event_click.h"

/* This function is responsible for singleplayer_forwarding to appropriate functions which serves game modes */
int singleplayer_forwarding(const int check_returned, ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface, ALLEGRO_BITMAP** scoreBoard,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu)
{
	switch (check_returned)
	{
	case 1: /* Singleplayer */
		al_draw_bitmap(*game_mode_menu, 0, 0, 0);
		al_flip_display();
	break;
	case 2: /* Multiplayer */
		printf(" wieloosobowy ");
	break;
	case 3: /* Add Question*/
		printf(" dodaj pytanie ");
	break;
	case 4: /* Exit Game */
		printf(" wyjscie ");
	break;
	case 5: /* Trening */
			singleplayer_trening(timer, display, queue, font, main_menu,
			game_mode_menu, menu_interface, scoreBoard, resolution_x, resolution_y, FPS, which_menu);
	break;
	case 6: /* 3 Lifes */
		printf(" 3 zycia ");
	break;
	case 7: /* Hardcore */
		printf(" hardcore ");
	break;
	case 12:
		return 12;
	break;
	}
}
int listener_menu(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu, 
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface, ALLEGRO_BITMAP** scoreBoard,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu,bool *singleplayer)
{
	ALLEGRO_EVENT event;

	bool done = false;
	bool redraw = false;
	bool flag = true;
	int check_returned = 0;
	unsigned int mouse_x, mouse_y, mouse_click;
	while (1)
	{
		al_wait_for_event(*queue, &event);
		switch (event.type)
		{
			/* on click event */
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			mouse_x = event.mouse.x;
			mouse_y = event.mouse.y;
			check_returned = check_event_click(&mouse_x, &mouse_y, which_menu);
			printf("%d", check_returned);
			/* Below check is for single player function which has permission to call listener
			function as her own. */
			if (check_returned >= 8 && check_returned <= 11) return check_returned;

			/* here will be next statements for next game modes */
			if (check_returned == 0) return 0;
			/* Bellow if statement check if listener has been called from init_menu */
			if (*singleplayer) {
				if (singleplayer_forwarding(check_returned, timer, display, queue, font, main_menu,
					game_mode_menu, menu_interface, scoreBoard, resolution_x, resolution_y, FPS, which_menu)==12)return 1;
			}
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		default: break;
		}
		if (done) break;
	}	
}

void init_menu(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue,
	ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu, ALLEGRO_BITMAP** game_mode_menu,
	ALLEGRO_BITMAP** menu_interface, ALLEGRO_BITMAP** scoreBoard,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS)
{
	int a;
	bool singleplayer = true;
	int which_menu = 1;
	al_draw_bitmap(*main_menu, 0, 0, 0);
	al_flip_display();
	if ((a=listener_menu(timer, display, queue, font, main_menu,
		game_mode_menu, menu_interface, scoreBoard, resolution_x, resolution_y,
		FPS, &which_menu, &singleplayer)) == 0) {
		init_menu(timer, display, queue, font, main_menu,
			game_mode_menu, menu_interface, scoreBoard, resolution_x, resolution_y,
			FPS);
		return;
	}
		return;
}