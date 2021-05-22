#pragma once
int listener_menu(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface, ALLEGRO_BITMAP** scoreBoard,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu, bool* singleplayer);

void print_score_singlepalyer(ALLEGRO_FONT** font, int ptk);

void singleplayer_trening(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface, ALLEGRO_BITMAP** scoreBoard,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu)
{
	*font = al_load_font("spotify_circular.ttf", 30, 1);
	must_init(*font, "font");
	*menu_interface = al_load_bitmap("menu_interface.jpg");
	must_init(*menu_interface, "menu_interface PTR");
	al_draw_bitmap(*menu_interface, 0, 0, 0);
	al_flip_display();
	al_destroy_bitmap(*menu_interface);
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

	p_questions cp_head = head_of_questions;
	
	int ptk = 0;
	char tmp_int_char[10];
	int returned_from_list = 0;
	int correct_ans = 0;
	int aling_up = 15;
	while (cp_head->next) 
	{

		string_typewriter(font, cp_head->question, 24, 1308, 216, *resolution_x / 2 , 140, 60);
		al_flip_display();
		string_typewriter(font, cp_head->answer_a, 24, 1308, 134, *resolution_x / 2, 404, 45);
		al_flip_display();
		string_typewriter(font, cp_head->answer_b, 24, 1308, 134, *resolution_x / 2, 555, 45);
		al_flip_display();
		string_typewriter(font, cp_head->answer_c, 24, 1308, 134, *resolution_x / 2, 707, 45);
		al_flip_display();
		string_typewriter(font, cp_head->answer_d, 24, 1308, 134, *resolution_x / 2, 859, 45);
		al_flip_display();

		char tmp_poit_container[10] = { "PUNKTY: " };
		al_draw_text(*font, color, 1450, 100,
			ALLEGRO_ALIGN_CENTER, strcat(tmp_poit_container, itoa(ptk, tmp_int_char, 10)));


		switch (cp_head->correct[0])
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

		bool training = false;


		if (listener_menu(timer, display, queue, font, main_menu, game_mode_menu, menu_interface, scoreBoard,
			resolution_x, resolution_y, FPS, which_menu, &training) == correct_ans)
		{
			ptk++;
			*menu_interface = al_load_bitmap("menu_interface.jpg");
			must_init(*menu_interface, "menu_interface PTR");
			al_draw_bitmap(*menu_interface, 0, 0, 0);
			al_flip_display();
			al_destroy_bitmap(*menu_interface);
			cp_head = cp_head->next;
		}
		else
		{
			*menu_interface = al_load_bitmap("menu_interface.jpg");
			must_init(*menu_interface, "menu_interface PTR");
			al_draw_bitmap(*menu_interface, 0, 0, 0);
			al_flip_display();
			al_destroy_bitmap(*menu_interface);
			cp_head = cp_head->next;
		}
	}
	*scoreBoard = al_load_bitmap("scoreboard.jpg");
	must_init(*scoreBoard, "score_board PTR");
	al_draw_bitmap(*scoreBoard, 0, 0, 0);
	al_flip_display();
	print_score_singlepalyer(font, ptk);
	al_destroy_bitmap(*scoreBoard);
	al_destroy_font(*font);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	(*which_menu) = 4;
}

void print_score_singlepalyer(ALLEGRO_FONT** font, int ptk)
{
	ALLEGRO_COLOR color_white = al_map_rgb(255, 255, 255);
	*font = al_load_font("spotify_circular.ttf", 60, 1);
	char tmp_poit_container[20] = { "ZDOBYTE PUNKTY: " };
	char tmp_int_char[10];
	al_draw_text(*font, color_white, 339, 311,
	ALLEGRO_ALIGN_LEFT, strcat(tmp_poit_container, itoa(ptk, tmp_int_char, 10)));
	al_flip_display();
	*font = al_load_font("spotify_circular.ttf", 30, 1);
}