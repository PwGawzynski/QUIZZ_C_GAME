#pragma once
#include "check_event_click.h"
#include "multiplayer_training.h"
#include "multiplayer_3lifes.h"
#include "multiplayer_hardcore.h"
void wh_game();

int main_loop(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface, ALLEGRO_BITMAP** scoreBoard,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu, int nr_players)
{
	ALLEGRO_EVENT event;
	must_init(*queue, "queue");
	bool done = false;
	bool redraw = false;
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
			printf(" cr: %d \n", check_returned);
			if (check_returned >= 8 && check_returned <= 11) return check_returned;
			if (check_returned == 0) 
			{
				kill_quest_list();
				return 0;
			}
			if ((check_returned==1) && ((*which_menu)==2))
			{
				
				*game_mode_menu = al_load_bitmap("game_mode_menu.jpg");
				must_init(*game_mode_menu, "game_mode_menu PTR");
				al_draw_bitmap(*game_mode_menu, 0, 0, 0);
				al_flip_display();
				al_destroy_bitmap(*game_mode_menu);
				return 1;
			}

			if (check_returned == 5) 
			{
				load_saved_info();
				//zmienić ilość pytań 
				nr_of_questions_in_base = scan_file((2 * nr_players)+1, 0, 0);
				printf("%d\n", nr_of_questions_in_base);
				id = nr_of_questions_in_base;
				
				multiplayer_trening(timer, display, queue, font, main_menu,
					game_mode_menu, menu_interface, scoreBoard, resolution_x, resolution_y, FPS, which_menu, nr_players);
			}
			
			if (check_returned == 6) 
			{
				load_saved_info();
				//zmienić ilość pytań 
				nr_of_questions_in_base = scan_file((2 * nr_players)+1, 0, 0);
				printf("%d\n", nr_of_questions_in_base);
				id = nr_of_questions_in_base;
				
				multiplayer_3lifes(timer, display, queue, font, main_menu,
					game_mode_menu, menu_interface, scoreBoard, resolution_x, resolution_y, FPS, which_menu, nr_players);
			}
			
			if (check_returned == 7) 
			{
				load_saved_info();
				//zmienić ilość pytań 
				nr_of_questions_in_base = scan_file((2 * nr_players)+1, 0, 0);
				printf("%d\n", nr_of_questions_in_base);
				id = nr_of_questions_in_base;
				
				multiplayer_hardcore(timer, display, queue, font, main_menu,
					game_mode_menu, menu_interface, scoreBoard, resolution_x, resolution_y, FPS, which_menu, nr_players);
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

void wh_game()
{
	bool singleplayer = false;
	ALLEGRO_BITMAP* game_mode = al_load_bitmap("game_mode_menu.jpg");
	must_init(game_mode, "game_mode_menu PTR");
	al_draw_bitmap(game_mode, 0, 0, 0);
	al_flip_display();
	al_destroy_bitmap(game_mode);
}