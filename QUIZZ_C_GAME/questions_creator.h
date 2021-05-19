#pragma once
#include "questions_string_writter.h"
/*void show_select(int check_returned)
{
	ALLEGRO_COLOR color_green = al_map_rgb(173, 255, 47);

	if(check_returned == 2)
	{
		al_draw_filled_recentagle(278, 406, 292, 540, color_green);
	}
	if(check_returned == 3) 
	{
		al_draw_filled_recentagle(278, 555, 292, 689, color_green);
	}
	if(check_returned == 4)
	{
		al_draw_filled_recentagle(278, 707, 292, 841, color_green);
	}
	if(check_returned == 5)
	{
		al_draw_filled_recentagle(278, 859, 292, 993, color_green);
	}
}*/

void listener_creator(int* resolution_x, int* resolution_y, ALLEGRO_EVENT_QUEUE** queue)
{
	/*INITIALIZATION BACKGROUND PTR AND DRAW IT ON THE SCREEN*/
	ALLEGRO_BITMAP* question_creator = al_load_bitmap("question_creator.jpg");
	must_init(question_creator, "question_creator PTR");
	al_draw_bitmap(question_creator, 0, 0, 0);
	al_flip_display();

	
	/*LOCALS*/
	ALLEGRO_EVENT event;
	bool done = false;
	/*KEYBOARD KEY VALUE*/
	int unichar;
	/*MARKING OF THE FIELD TO INSERT*/
	int window_counter=0;
	/*FONTS POSITIONS*/
	int font_position_y[] = { 216, 471, 622, 774, 926 };
	/*VALUE RETURNED FROM CHECK_EVENT_CLICK MEANS WHICH ELEMENT'S BEEN CLICKED*/
	int check_returned = 0;
	/*VALUE INFORMING ABOUT CURRENT SCREEN*/
	int which_menu = 5;
	/*CHARACTERS COUNTER*/
	int counter = -1;
	/*ALLEGRO USER TYPED STRING*/
	ALLEGRO_USTR* input_quest= al_ustr_new("");
	ALLEGRO_USTR* input_answer_a= al_ustr_new("");
	ALLEGRO_USTR* input_answer_b= al_ustr_new("");
	ALLEGRO_USTR* input_answer_c= al_ustr_new("");
	ALLEGRO_USTR* input_answer_d= al_ustr_new("");
	/*MOUSE POSITIONS*/
	unsigned int mouse_x, mouse_y;
	/*WHICH_STR VARIABLE TO SAVE INFO WHICH STRING IS FILLED*/
	int which_str = 0;
	
	/*END OF LOCALS*/


	/*QUESTION CREATOR MAIN LOOP*/
	while (1)
	{
		al_wait_for_event(*queue, &event);
		switch (event.type)
		{
			/*MOUSE EVENT CLICK*/
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			/*GET MOUSE POSITION */
			mouse_x = event.mouse.x;
			mouse_y = event.mouse.y;
			/*CHECK WHICH ELEMENT'S BEEN CLICKED*/
			check_returned = check_event_click(&mouse_x, &mouse_y, &which_menu);
			/*DEBUG INFO*/
			printf("CR: %d\n", check_returned);

			/*IF BACK TO MENU'S BEEN CLICKED*/
			if (check_returned==6)
			{
				/*check if every field has been filled*/
				if (al_ustr_length(input_quest) && al_ustr_length(input_answer_a) && al_ustr_length(input_answer_b) &&
					al_ustr_length(input_answer_c) && al_ustr_length(input_answer_d)) {
					while (1)
					{
						al_wait_for_event(*queue, &event);
						switch (event.type)
						{
							case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
								check_returned = check_event_click(&mouse_x, &mouse_y, &which_menu);
								if(check_returned)
							case ALLEGRO_EVENT_DISPLAY_CLOSE:
								done = true;
								break;
							default: break;
						}
						if (done) break;
					}
					
					scan_file(0, 1, (id += 1));
					fseek(file, 0, SEEK_END);// be careful 
					tmp_question.id = id;
					tmp_question.question = al_cstr(input_quest);
					tmp_question.answer_a = al_cstr(input_answer_a);
					tmp_question.answer_b = al_cstr(input_answer_b);
					tmp_question.answer_c = al_cstr(input_answer_c);
					tmp_question.answer_d = al_cstr(input_answer_d);
					tmp_question.correct = "A";
					write_to_file();
					fclose(file);
				}
				else printf("%s", "chuja");
			}
			if (check_returned == 7) { done = true; break; }
			if (check_returned == 1) {
				window_counter = 0, which_str = 0;
				counter = al_ustr_length(input_quest);
			}else if(check_returned==2)
			{
				window_counter = 1, which_str = 1;
				counter = al_ustr_length(input_answer_a)-1;
			}
			else if (check_returned == 3)
			{
				window_counter = 2, which_str = 2;
				counter = al_ustr_length(input_answer_b)-1;
			}
			else if (check_returned == 4)
			{
				window_counter = 3, which_str = 3;
				counter = al_ustr_length(input_answer_c)-1;
			}else if (check_returned == 5)
			{
				window_counter = 4, which_str = 4;
				counter = al_ustr_length(input_answer_d)-1;
			}
			

			
			break;
		case ALLEGRO_EVENT_KEY_CHAR:
			/*GET KEY CODE*/
			unichar = event.keyboard.unichar;
			/*DEBUG KEY CODE*/
			printf("%d", event.keyboard.unichar);

			/*FIND WHICH KEY'S BEEN TYPED*/
			if (unichar >= 32 && unichar <= 126)
			{
				/*FILLING QUESTION STR*/
				if (which_str == 0)
				{
					al_draw_bitmap(question_creator, 0, 0, 0);
					al_ustr_append_chr(input_quest, unichar);
					counter++;
				}
				/*FILLING ANSWER A*/
				else if(which_str == 1)
				{
					al_draw_bitmap(question_creator, 0, 0, 0);
					al_ustr_append_chr(input_answer_a, unichar);
					counter++;
				}
				/*FILING ANSWER B*/
				else if(which_str == 2)
				{
					al_draw_bitmap(question_creator, 0, 0, 0);
					al_ustr_append_chr(input_answer_b, unichar);
					counter++;
				}
				/*FILLING ANSWER C*/
				else if (which_str == 3)
				{
					al_draw_bitmap(question_creator, 0, 0, 0);
					al_ustr_append_chr(input_answer_c, unichar);
					counter++;
				}
				/*FILLING ANSWER D*/
				else if (which_str == 4)
				{
					al_draw_bitmap(question_creator, 0, 0, 0);
					al_ustr_append_chr(input_answer_d, unichar);
					counter++;
				}
				quest_writter(&input_quest, font_position_y, resolution_x, resolution_y, 0);
				quest_writter(&input_answer_a, font_position_y, resolution_x, resolution_y, 1);
				quest_writter(&input_answer_b, font_position_y, resolution_x, resolution_y, 2);
				quest_writter(&input_answer_c, font_position_y, resolution_x, resolution_y, 3);
				quest_writter(&input_answer_d, font_position_y, resolution_x, resolution_y, 4);

				al_flip_display();

			}
			else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
			{
				window_counter++;
				if (window_counter == 0) {
					window_counter = 0, which_str = 0;
					counter = al_ustr_length(input_quest);
				}
				else if (window_counter == 1)
				{
					window_counter = 1, which_str = 1;
					counter = al_ustr_length(input_answer_a) - 1;
				}
				else if (window_counter == 2)
				{
					window_counter = 2, which_str = 2;
					counter = al_ustr_length(input_answer_b) - 1;
				}
				else if (window_counter == 3)
				{
					window_counter = 3, which_str = 3;
					counter = al_ustr_length(input_answer_c) - 1;
				}
				else if (window_counter == 4)
				{
					window_counter = 4, which_str = 4;
					counter = al_ustr_length(input_answer_d) - 1;
				}
				break;
			}
			else if (event.keyboard.keycode==ALLEGRO_KEY_BACKSPACE&&counter>=0)
			{

				/*FILLING QUESTION STR*/
				if (which_str == 0)
				{
					printf("\n%d", counter);
					al_ustr_remove_chr(input_quest, counter);
					al_draw_bitmap(question_creator, 0, 0, 0);
				}
				/*FILLING ANSWER A*/
				else if (which_str == 1)
				{
					al_ustr_remove_chr(input_answer_a, counter);
					al_draw_bitmap(question_creator, 0, 0, 0);
				}
				/*FILING ANSWER B*/
				else if (which_str == 2)
				{
					al_ustr_remove_chr(input_answer_b, counter);
					al_draw_bitmap(question_creator, 0, 0, 0);
				}
				/*FILLING ANSWER C*/
				else if (which_str == 3)
				{
					al_ustr_remove_chr(input_answer_c, counter);
					al_draw_bitmap(question_creator, 0, 0, 0);
				}
				/*FILLING ANSWER D*/
				else if (which_str == 4)
				{
					al_ustr_remove_chr(input_answer_d, counter);
					al_draw_bitmap(question_creator, 0, 0, 0);
				}
				quest_writter(&input_quest, font_position_y, resolution_x, resolution_y, 0);
				quest_writter(&input_answer_a, font_position_y, resolution_x, resolution_y, 1);
				quest_writter(&input_answer_b, font_position_y, resolution_x, resolution_y, 2);
				quest_writter(&input_answer_c, font_position_y, resolution_x, resolution_y, 3);
				quest_writter(&input_answer_d, font_position_y, resolution_x, resolution_y, 4);
				counter--;
				printf("\n%d", counter);
				al_flip_display();
			}
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		default: break;
		}
		if (done) break;

	}
	al_destroy_bitmap(question_creator);
}


void allegro_questions_creator(int* resolution_x, int* resolution_y,ALLEGRO_EVENT_QUEUE** queue)
{
	int tmp;
	listener_creator(resolution_x, resolution_y,queue);
	
}