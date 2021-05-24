#pragma once

struct players
{
	int points;
	int lives;
	struct players* next;
};

void create_cyclical_list(struct players** player, int nr_player)
{
	if ((nr_player) == 0) return;
	if ((*player)==NULL)
	{
		(*player) = (struct players*)malloc(sizeof(struct players));
		must_init_exit(player, "cyclical list allocation memory");
		(*player)->next = (*player);
	}
	else
	{
		struct players* tmp = (*player)->next;
		(*player)->next = (struct players*)malloc(sizeof(struct players));
		must_init_exit((*player)->next, "cyclical list allocation memory");
		(*player)->next->next = tmp;
	}
	create_cyclical_list(player, --nr_player);
}
void kill_cycilcal_list(struct players** player)
{
	struct players* start = *player;

	do
	{
		struct player* tmp = (*player)->next;
		free(*player);
		(*player) = NULL;
		(*player) = tmp;
	} while ((*player) != (start));
	
}

void multiplayer_create_structures(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface, ALLEGRO_BITMAP** scoreBoard,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu, bool* singleplayer,int nr_players){
	struct players* player = NULL;
	create_cyclical_list(&player, nr_players);

	// tutaj napis loading 
	
	load_saved_info();
	nr_of_questions_in_base = scan_file(5*nr_players, 0, 0);
	printf("%d\n", nr_of_questions_in_base);
	id = nr_of_questions_in_base;

	main_loop(timer, display, queue, font, main_menu,
		game_mode_menu, menu_interface, scoreBoard, resolution_x, resolution_y,
		FPS, which_menu);
	

	kill_cycilcal_list(&player);
	kill_quest_list();
	return;
}