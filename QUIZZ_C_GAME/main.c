#include "STATUS.h"
#include "init_structures.h"
#include "strings.h"
#include "load_game_file.h"
#include "allegro_lib_handler.h"
#include "string_typewriter.h"
#include "multiplayer_main_loop.h"
#include "multiplayer_structures.h"
#include "main_menu_handler.h"
#include "questions_string_writter.h"
#include "questions_creator.h"

int main() 
{
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT* font = NULL;
    ALLEGRO_BITMAP* main_menu = NULL;
    ALLEGRO_BITMAP* game_mode_menu = NULL;
    ALLEGRO_BITMAP* menu_interface = NULL;
    ALLEGRO_BITMAP* scoreBoard = NULL;
    ALLEGRO_BITMAP* question_creator = NULL;
	
    allegro_game_init(&timer, &display, &queue, &font, &main_menu, &game_mode_menu ,&menu_interface, &scoreBoard, &question_creator,&resolution_x, &resolution_y, &FPS);
   
	init_menu(&timer, &display, &queue, &font, &main_menu, &game_mode_menu, &menu_interface, &scoreBoard, &resolution_x, &resolution_y, &FPS);
   
    //al_rest(15.0);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}