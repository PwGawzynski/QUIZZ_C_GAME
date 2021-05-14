#pragma once

void singleplayer_3lifes(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu,
	ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface, ALLEGRO_BITMAP** scoreBoard,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS, int* which_menu)
{
	al_draw_bitmap(*menu_interface, 0, 0, 0);
	al_flip_display();
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	p_questions cp_head = head_of_questions;

	int ptk = 0;
	int lifes = 3;
	char tmp_int_char[10];
	char tmp_int_char_2[10];
	int returned_from_list = 0;
	int correct_ans = 0;
	int aling_up = 15;
	while (cp_head->next)
	{
		if (lifes == 0) break;
		string_typewriter(font, cp_head->question, 24, 1308, 216, *resolution_x / 2, 140, 60);
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
		char tmp_poit_container_2[10] = { "ZYCIA: " };
		al_draw_text(*font, color, 1250, 100,
			ALLEGRO_ALIGN_CENTER, strcat(tmp_poit_container_2, itoa(lifes, tmp_int_char_2, 10)));
		

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
			al_draw_bitmap(*menu_interface, 0, 0, 0);
			al_flip_display();
			cp_head = cp_head->next;
		}
		else
		{
			lifes--;
			al_draw_bitmap(*menu_interface, 0, 0, 0);
			al_flip_display();
			cp_head = cp_head->next;
		}
	}
	al_draw_bitmap(*scoreBoard, 0, 0, 0);
	al_flip_display();
	print_score_singlepalyer(font, ptk);
	(*which_menu) = 4;
}
