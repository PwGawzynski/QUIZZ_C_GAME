

int check_event_click(unsigned int* mouse_x, unsigned int* mouse_y, int* which_menu)
{
	if ((*which_menu) == 1)
	{
		//main menu
		if (((*mouse_x >= 294) && (*mouse_x <= 782)) && ((*mouse_y >= 395) && (*mouse_y <= 607))) { (*which_menu)++; return 1; } // jednoosobowy
		if (((*mouse_x >= 294) && (*mouse_x <= 782)) && ((*mouse_y >= 635) && (*mouse_y <= 847))) return 2; // wieloosobowy
		if (((*mouse_x >= 813) && (*mouse_x <= 1129)) && ((*mouse_y >= 396) && (*mouse_y <= 847))) return 3; // dodaj pytanie
		if (((*mouse_x >= 1159) && (*mouse_x <= 1619)) && ((*mouse_y >= 586) && (*mouse_y <= 847))) return 4; // wyjscie
	}
	if ((*which_menu) == 2)
	{
		//game mode menu 
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 305) && (*mouse_y <= 484))) return 1; // trening
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 520) && (*mouse_y <= 699))) return 2;  // 3 zycia
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 735) && (*mouse_y <= 914))) return 3; // hardcore
	}
}

int forwarding(const int check_returned, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, int* which_menu)
{
	switch (check_returned)
	{
	case 1: // jednoosobowy
		al_draw_bitmap(*game_mode_menu, 0, 0, 0);
		al_flip_display();
		
	break;
	case 2:
		printf("wieloosobowy");
	break;
	case 3:
		printf("dodaj pytanie");
	break;
	case 4:
		printf("wyjscie");
	break;
	}
}
void listener(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu, 
	ALLEGRO_BITMAP** game_mode_menu, 
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu)
{
	ALLEGRO_EVENT event;
	bool done = false;
	bool redraw = false;
	int check_returned;
	unsigned int mouse_x, mouse_y, mouse_click;
	while (1)
	{
		al_wait_for_event(*queue, &event);
		switch (event.type)
		{
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			mouse_x = event.mouse.x;
			mouse_y = event.mouse.y;
			check_returned = check_event_click(&mouse_x, &mouse_y, which_menu);
			forwarding(check_returned, font, main_menu, game_mode_menu, which_menu);
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		default: break;
		}
		if (done) break;

	}
}

bool init_menu(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue,
	ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu, ALLEGRO_BITMAP** game_mode_menu,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS)
{
	int which_menu = 1;
	al_draw_bitmap(*main_menu, 0, 0, 0);
	al_flip_display();
	listener(timer, display, queue, font, main_menu, game_mode_menu, resolution_x, resolution_y, FPS, &which_menu);
}