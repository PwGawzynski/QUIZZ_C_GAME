#pragma once
#include "check_event_click.h"
void wh_game();
void main_loop()
{
	wh_game();
	ALLEGRO_EVENT event;
	ALLEGRO_EVENT_QUEUE* queue =  al_create_event_queue();
	must_init(queue, "queue");
	bool done = false;
	bool redraw = false;
	int which_menu = 3;
	int check_returned = 0;
	unsigned int mouse_x, mouse_y, mouse_click;
	while (1)
	{
		al_wait_for_event(queue, &event);
		switch (event.type)
		{
			/* on click event */
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			mouse_x = event.mouse.x;
			mouse_y = event.mouse.y;
			check_returned = check_event_click(&mouse_x, &mouse_y, which_menu);
			printf(" cr: %d \n", check_returned);
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		default: break;
		}
		if (done) break;
	}
}

void wh_game()
{
	ALLEGRO_BITMAP* game_mode = al_load_bitmap("game_mode_menu.jpg");
	must_init(game_mode, "game_mode_menu PTR");
	al_draw_bitmap(game_mode, 0, 0, 0);
	al_flip_display();
	al_destroy_bitmap(game_mode);
	
	
}