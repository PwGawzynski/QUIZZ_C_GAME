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
void kill_cycilcal_list(struct players** player, struct players** first)
{
	if((*player)!=(*first))
	{
		kill_cycilcal_list(&((*player)->next), first);
		free(*player);
		(*player) = NULL;
	}
	
}

void multiplayer_create_structures(int* resolution_x, int* resolution_y, int nr_players,ALLEGRO_EVENT_QUEUE** queue){
	struct players* player = NULL;
	create_cyclical_list(&player, nr_players);


	kill_cycilcal_list(&(player->next), &player);
	free(player);
	return;
}