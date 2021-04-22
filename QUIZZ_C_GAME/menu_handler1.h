int listener_menu(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu);

bool singleplayer_trening(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu)
{
	al_draw_bitmap(*menu_interface, 0, 0, 0);
	al_flip_display();
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

	int ptk=0;
	char tmp_int_char[10];
	char tmp_poit_container[100]={"PUNKTY: "};
	int returned_from_list=0;
	int correct_ans=0;
	int aling_up = 15;
	while (head_of_questions->next) {

		al_draw_text(*font, color, *resolution_x / 2, 216-aling_up,
			ALLEGRO_ALIGN_CENTER, head_of_questions->question);
		al_draw_text(*font, color, *resolution_x / 2, 471-aling_up,
			ALLEGRO_ALIGN_CENTER, head_of_questions->answer_a);
		al_draw_text(*font, color, *resolution_x / 2, 622-aling_up,
			ALLEGRO_ALIGN_CENTER, head_of_questions->answer_b);
		al_draw_text(*font, color, *resolution_x / 2, 774-aling_up,
			ALLEGRO_ALIGN_CENTER, head_of_questions->answer_c);
		al_draw_text(*font, color, *resolution_x / 2, 926-aling_up,
			ALLEGRO_ALIGN_CENTER, head_of_questions->answer_d);
		al_draw_text(*font, color, 1450, 100,
			ALLEGRO_ALIGN_CENTER, strcat(tmp_poit_container,itoa(ptk,tmp_int_char,10)));


		switch (head_of_questions->correct[0])
		{
		case 'A':
			correct_ans = 8;
			break;
		case 'B':
			correct_ans = 9;
			break;
		case 'C':
			correct_ans = 10;
			break;
		case 'D':
			correct_ans = 11;
			break;
		default:
			break;
		}

		al_flip_display();

		
		

		if(listener_menu(timer, display, queue, font, main_menu, game_mode_menu, menu_interface,
			resolution_x, resolution_y, FPS, which_menu)==correct_ans)
		{
			ptk++;
			al_draw_bitmap(*menu_interface, 0, 0, 0);
			al_flip_display();
		}else
		{
			al_draw_bitmap(*menu_interface, 0, 0, 0);
			al_flip_display();
		}
	}
}
int check_event_click(unsigned int* mouse_x, unsigned int* mouse_y, int* which_menu)
{
	if ((*which_menu) == 1)
	{
		//main menu
		if (((*mouse_x >= 294) && (*mouse_x <= 782)) && ((*mouse_y >= 395) && (*mouse_y <= 607))) { (*which_menu) = 2; return 1; } // jednoosobowy
		if (((*mouse_x >= 294) && (*mouse_x <= 782)) && ((*mouse_y >= 635) && (*mouse_y <= 847))) return 2; // wieloosobowy
		if (((*mouse_x >= 813) && (*mouse_x <= 1129)) && ((*mouse_y >= 396) && (*mouse_y <= 847))) return 3; // dodaj pytanie
		if (((*mouse_x >= 1159) && (*mouse_x <= 1619)) && ((*mouse_y >= 586) && (*mouse_y <= 847))) return 4; // wyjscie
	}
	if ((*which_menu) == 2)
	{
		//game mode menu 
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 305) && (*mouse_y <= 484))) { (*which_menu) = 3; return 5; } // trening
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 520) && (*mouse_y <= 699))) return 6;  // 3 zycia
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 735) && (*mouse_y <= 914))) return 7; // hardcore
	}
	if ((*which_menu) == 3)
	{
		//menu_interface 
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 404) && (*mouse_y <= 538))) return 8; // odpowiedz a
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 555) && (*mouse_y <= 689))) return 9;  // odpowiedz b
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 707) && (*mouse_y <= 841))) return 10; // odpowiedz c
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 859) && (*mouse_y <= 993))) return 11; // odpowiedz d
	}
}

int forwarding(const int check_returned, ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu)
{
	switch (check_returned)
	{
	case 1: // jednoosobowy
		al_draw_bitmap(*game_mode_menu, 0, 0, 0);
		al_flip_display();
	break;
	case 2:
		printf(" wieloosobowy ");
	break;
	case 3:
		printf(" dodaj pytanie ");
	break;
	case 4:
		printf(" wyjscie ");
	break;
	case 5: //trening
			singleplayer_trening(timer, display, queue, font, main_menu,
			game_mode_menu, menu_interface, resolution_x, resolution_y, FPS, &which_menu);
	break;
	case 6:
		printf(" 3 zycia ");
	break;
	case 7:
		printf(" hardcore ");
	break;
	}
}
int listener_menu(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu, 
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu)
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
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			mouse_x = event.mouse.x;
			mouse_y = event.mouse.y;
			if (check_returned >= 8 && check_returned <= 11) return check_returned;
			check_returned = check_event_click(&mouse_x, &mouse_y, which_menu);
			forwarding(check_returned, timer, display, queue, font, main_menu,
					game_mode_menu, menu_interface, resolution_x, resolution_y, FPS, &which_menu);
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		default: break;
		}
		if (done) break;
	}	
}

int listener_game(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu, 
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface,
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
			forwarding(check_returned, timer, display, queue, font, main_menu,
				game_mode_menu, menu_interface, resolution_x, resolution_y, FPS, &which_menu);
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
	ALLEGRO_BITMAP** menu_interface,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS)
{
	int which_menu = 1;
	al_draw_bitmap(*main_menu, 0, 0, 0);
	al_flip_display();
	listener_menu(timer, display, queue, font, main_menu, game_mode_menu, menu_interface, resolution_x, resolution_y, FPS, &which_menu);
}

