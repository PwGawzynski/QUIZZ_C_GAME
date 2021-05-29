#pragma once
#include "questions_string_writter.h"

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
	int align_up = 30; 
	int font_position_y[] = { 216, 471 - align_up, 622 - align_up, 774 - align_up, 926 - align_up };
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
	/*TMP BITMAP HOLDER*/
	ALLEGRO_BITMAP* tmp;
	/*ALLEGRO FONT*/
	ALLEGRO_FONT* font = al_load_font("spotify_circular.ttf", 50, 1);
	/*MOUSE POSITIONS*/
	unsigned int mouse_x, mouse_y;
	/*WHICH_STR VARIABLE TO SAVE INFO WHICH STRING IS FILLED*/
	int which_str = 0;
	/*CORRECT ANSWER FLAG*/
	int correct_flag=0;
	int last_correct_flag=0;
	/*WARNING PLACEHOLDER*/
	const char* empty = "UZUPELNIJ POLE!!!";
	/*CORRECT ANSWER RECTANGLE POSITIONS TAB*/
	int rec_correct[4][4] = 
	{ 279, 406, 292, 540,
		278, 555, 292, 689,
		279, 707, 292, 841,
		279, 859, 292, 993,
	};
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
					al_ustr_length(input_answer_c) && al_ustr_length(input_answer_d) && tmp_question.correct) {

					/*REMOVING WHITE CHARACTERS ON THE END*/
					/*al_ustr_get(input_quest, al_ustr_length(input_quest)) == 32 ? al_ustr_remove_chr(input_quest, al_ustr_length(input_quest)) : 0;
					al_ustr_get(input_quest, al_ustr_length(input_answer_a)) == 32 ? al_ustr_remove_chr(input_quest, al_ustr_length(input_answer_a)) : 0;
					al_ustr_get(input_quest, al_ustr_length(input_answer_b)) == 32 ? al_ustr_remove_chr(input_quest, al_ustr_length(input_answer_b)) : 0;
					al_ustr_get(input_quest, al_ustr_length(input_answer_c)) == 32 ? al_ustr_remove_chr(input_quest, al_ustr_length(input_answer_c)) : 0;
					al_ustr_get(input_quest, al_ustr_length(input_answer_d)) == 32 ? al_ustr_remove_chr(input_quest, al_ustr_length(input_answer_d)) : 0;*/

					file = fopen("database.bin", "rb+");
					fread(&id, sizeof(int), 1, file);
					fclose(file);
					scan_file(0, 1, (id += 1));
					fseek(file, 0, SEEK_END);// be careful 
					tmp_question.id = id;
					tmp_question.question = al_cstr(input_quest);
					tmp_question.answer_a = al_cstr(input_answer_a);
					tmp_question.answer_b = al_cstr(input_answer_b);
					tmp_question.answer_c = al_cstr(input_answer_c);
					tmp_question.answer_d = al_cstr(input_answer_d);
					write_to_file();
					fclose(file);
					tmp_question.correct = NULL;


					al_ustr_free(input_quest);
					al_ustr_free(input_answer_a);
					al_ustr_free(input_answer_b);
					al_ustr_free(input_answer_c);
					al_ustr_free(input_answer_d);

					input_quest = al_ustr_new("");
					input_answer_a = al_ustr_new("");
					input_answer_b = al_ustr_new("");
					input_answer_c = al_ustr_new("");
					input_answer_d = al_ustr_new("");

					al_destroy_bitmap(question_creator);
					question_creator = al_load_bitmap("question_creator.jpg");
					must_init(question_creator, "question_creator PTR");
					al_draw_bitmap(question_creator, 0, 0, 0);

					al_draw_text(font, al_map_rgb(201, 255, 37),
						1308, 1000,
						ALLEGRO_ALIGN_CENTER, "PYTANIE ZOSTAŁO DODANE POMYŚLNIE :)");
					al_flip_display();

					al_rest(2);
					
					al_draw_bitmap(question_creator, 0, 0, 0);

					window_counter = 0; which_str = 0; counter = -1;
				}
				else
				{
					

					if(!(al_ustr_length(input_quest))){
						quest_writter_empty(&empty, font_position_y, resolution_x, resolution_y, 0);

					}else if (!(al_ustr_length(input_answer_a))) {
						quest_writter_empty(&empty, font_position_y, resolution_x, resolution_y, 1);

					}else if (!(al_ustr_length(input_answer_b))) {
						quest_writter_empty(&empty, font_position_y, resolution_x, resolution_y, 2);

					}
					else if (!(al_ustr_length(input_answer_c))) {
						quest_writter_empty(&empty, font_position_y, resolution_x, resolution_y, 3);

					}
					else if (!(al_ustr_length(input_answer_d))) {
						quest_writter_empty(&empty, font_position_y, resolution_x, resolution_y, 4);

					}else if(!tmp_question.correct)
					{
						al_draw_bitmap(question_creator, 0, 0, 0);

						al_draw_text(font, al_map_rgb(255, 66, 33),
							1308, 1000,
							ALLEGRO_ALIGN_CENTER, "ZAZNACZ PRAWIDŁOWĄ ODPOWIEDŹ !!!");
						al_flip_display();
					}
					al_flip_display();
				}
			}
			if (check_returned == 7) { done = true; break; }
			if (check_returned == 1) {
				window_counter = 0, which_str = 0;
				counter = al_ustr_length(input_quest);
			}else if(check_returned==2)
			{
				window_counter = 1; which_str = 1;
				counter = al_ustr_length(input_answer_a)-1;
			}
			else if (check_returned == 3)
			{
				window_counter = 2; which_str = 2;
				counter = al_ustr_length(input_answer_b)-1;
			}
			else if (check_returned == 4)
			{
				window_counter = 3; which_str = 3;
				counter = al_ustr_length(input_answer_c)-1;
			}else if (check_returned == 5)
			{
				window_counter = 4; which_str = 4;
				counter = al_ustr_length(input_answer_d)-1;
			}
			else if (check_returned == 22)
			{
				if ((correct_flag!=22))
				{
					al_destroy_bitmap(question_creator);
					question_creator = al_load_bitmap("question_creator.jpg");
					must_init(question_creator, "question_creator PTR");
					al_draw_bitmap(question_creator, 0, 0, 0);
					
					
					tmp = al_get_target_bitmap();
					al_set_target_bitmap(question_creator);
					correct_flag = 22;
					al_draw_filled_rectangle(rec_correct[0][0], rec_correct[0][1], rec_correct[0][2], rec_correct[0][3], al_map_rgb(66, 245, 138));
					al_set_target_bitmap(tmp);
					al_draw_bitmap(question_creator,0,0,0);
					al_flip_display();
					tmp_question.correct = "A";
				}
				printf("na uj dwa razy");
			}
			else if (check_returned == 33)
			{
				if ((correct_flag != 33))
				{
					al_destroy_bitmap(question_creator);
					question_creator = al_load_bitmap("question_creator.jpg");
					must_init(question_creator, "question_creator PTR");
					al_draw_bitmap(question_creator, 0, 0, 0);


					tmp = al_get_target_bitmap();
					al_set_target_bitmap(question_creator);
					correct_flag = 33;
					al_draw_filled_rectangle(rec_correct[1][0], rec_correct[1][1], rec_correct[1][2], rec_correct[1][3], al_map_rgb(66, 245, 138));
					al_set_target_bitmap(tmp);
					al_draw_bitmap(question_creator, 0, 0, 0);
					al_flip_display();
					tmp_question.correct = "B";
				}
			}
			else if (check_returned == 44)
			{
				if ((correct_flag != 44))
				{
					al_destroy_bitmap(question_creator);
					question_creator = al_load_bitmap("question_creator.jpg");
					must_init(question_creator, "question_creator PTR");
					al_draw_bitmap(question_creator, 0, 0, 0);


					tmp = al_get_target_bitmap();
					al_set_target_bitmap(question_creator);
					correct_flag = 44;
					al_draw_filled_rectangle(rec_correct[2][0], rec_correct[2][1], rec_correct[2][2], rec_correct[2][3], al_map_rgb(66, 245, 138));
					al_set_target_bitmap(tmp);
					al_draw_bitmap(question_creator, 0, 0, 0);
					al_flip_display();
					tmp_question.correct = "C";
				}
				
			}
			else if (check_returned == 55)
			{
				if ((correct_flag != 55))
				{
					al_destroy_bitmap(question_creator);
					question_creator = al_load_bitmap("question_creator.jpg");
					must_init(question_creator, "question_creator PTR");
					al_draw_bitmap(question_creator, 0, 0, 0);


					tmp = al_get_target_bitmap();
					al_set_target_bitmap(question_creator);
					correct_flag = 55;
					al_draw_filled_rectangle(rec_correct[3][0], rec_correct[3][1], rec_correct[3][2], rec_correct[3][3], al_map_rgb(66, 245, 138));
					al_set_target_bitmap(tmp);
					al_draw_bitmap(question_creator, 0, 0, 0);
					al_flip_display();
					tmp_question.correct = "D";
				}
				printf("na uj dwa razy");
			}

			quest_writter(&input_quest, font_position_y, resolution_x, resolution_y, 0);
			quest_writter(&input_answer_a, font_position_y, resolution_x, resolution_y, 1);
			quest_writter(&input_answer_b, font_position_y, resolution_x, resolution_y, 2);
			quest_writter(&input_answer_c, font_position_y, resolution_x, resolution_y, 3);
			quest_writter(&input_answer_d, font_position_y, resolution_x, resolution_y, 4);
			al_flip_display();
			continue;
			break;
		case ALLEGRO_EVENT_KEY_CHAR:
			/*GET KEY CODE*/
			unichar = event.keyboard.unichar;
			
			/*DEBUG KEY CODE*/
			printf("%d", event.keyboard.unichar);

			/*FIND WHICH KEY'S BEEN TYPED*/
			if (unichar >= 32 )
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
	al_destroy_font(font);
}


void allegro_questions_creator(int* resolution_x, int* resolution_y,ALLEGRO_EVENT_QUEUE** queue)
{
	int tmp;
	listener_creator(resolution_x, resolution_y,queue);
}