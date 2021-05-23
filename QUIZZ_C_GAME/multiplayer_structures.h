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

void multiplayer_create_structures(int* resolution_x, int* resolution_y, int nr_players,ALLEGRO_EVENT_QUEUE** queue){
	struct players* player = NULL;
	create_cyclical_list(&player, nr_players);

	// tutaj napis loading 
	
	load_saved_info();
	nr_of_questions_in_base = scan_file(5*nr_players, 0, 0);
	printf("%d\n", nr_of_questions_in_base);
	id = nr_of_questions_in_base;

	main_loop();
	

	kill_cycilcal_list(&player);
	kill_quest_list();
	return;
}