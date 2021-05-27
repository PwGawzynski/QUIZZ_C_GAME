#pragma once
/**
 * \brief Funckja tworzy listę cykliczną graczy.
 * @param nr_players ilość graczy.
 * @param podwójny wskaźnik na trukturę graczy.
 */
void create_cyclical_list(struct players** player, int nr_player)
{
	if ((nr_player) == 0) return;
	if ((*player)==NULL)
	{
		(*player) = (struct players*)malloc(sizeof(struct players));
		(*player)->player_nr = nr_player;
		(*player)->lives = 1;
		(*player)->points = 0;
		must_init_exit(player, "cyclical list allocation memory");
		(*player)->next = (*player);
	}
	else
	{
		struct players* tmp = (*player)->next;
		(*player)->next = (struct players*)malloc(sizeof(struct players));
		(*player)->next->player_nr = nr_player;
		(*player)->next->lives = 1;
		(*player)->next->points = 0;
		must_init_exit((*player)->next, "cyclical list allocation memory");
		(*player)->next->next = tmp;
	}
	create_cyclical_list(player, --nr_player);
}
/**
 * \brief Funckja usuwa zaalokowaną pamięć dla listy cyklicznej graczy.
 * @param podwójny wskaźnik na trukturę graczy.
 */
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
	(*player) = NULL;
	
}
/**
 * \brief Driver tworzenia struktur graczy.
 *
 * @param resolution_x rozdzielczość pozioma okna programu.
 * @param resolution_y rozdzielczość pionowa okna programu.
 * @param FPS ilość klatek na sekundę.
 * @param timer podwójny wskaźnik na timer biblioteki allegro.
 * @param display podwójny wskaźnik na display biblioteki allegro.
 * @param queue podwójny wskaźnik na kolejkę biblioteki allegro.
 * @param main_menu podwójny wskaźnik na tło menu głównego.
 * @param game_mode_menu podwójny wskaźnik na tło trybów gry.
 * @param menu_interface podwójny wskaźnik na tło interfejsu gry.
 * @param scoreBoard podwójny wskaźnik na tło wyników końcowych.
 * @param font podwójny wskaźnik na font biblioteki allegro.
 * @param which_menu określa typ przekierowań.
 * @param nr_players ilość graczy.
 * @param singleplayer typ zachowania funkcji.
 */
void multiplayer_create_structures(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface, ALLEGRO_BITMAP** scoreBoard,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu, bool* singleplayer, int nr_players){
	
	
	wh_game();

	*which_menu = 2;
	int lop_ret=1;
	while (lop_ret)
	{
		create_cyclical_list(&player, nr_players);
	lop_ret=main_loop(timer, display, queue, font, main_menu,
		game_mode_menu, menu_interface, scoreBoard, resolution_x, resolution_y,
		FPS, which_menu,nr_players);
	kill_quest_list();
	kill_cycilcal_list(&player);

	}
	return;
}