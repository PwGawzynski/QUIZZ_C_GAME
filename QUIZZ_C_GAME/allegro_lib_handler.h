// ____ALLEGRO HEADERS____ //
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/mouse.h>
#include <allegro5/allegro_image.h>

/// <summary>
///  THIS FUNC CHECKS IF INSERTED VALUE HAS BEEN INICIALIZED 
/// </summary>
/// <param name="test">FUNC OR POINTER OR VARIABLE, WHICH CAN BE CHECK IN IF STATEMENT</param>
/// <param name="description">CONSTANT STRING TO DESCRIBE FIRST INSERTED VALUE</param>
void must_init(bool test, const char* description)
{
    if (test) return;

    printf("Couldn't initialize %s\n", description);
    exit(1);
}
/// <summary>
/// THIS FUNCTION INICIALIZES ALLEGRO LIB AND POINTERS
/// </summary>
/// <param name="timer">POINTER TO TIMER</param>
/// <param name="display">POINTER TO DISPLAY</param>
/// <param name="queue">POINTER TO QUEUE</param>
/// <param name="font">POINTER TO FONT</param>
/// <param name="resolution_x">RESOLUTION OF DISPLAY</param>

void allegro_game_init(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
    ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** main_menu, 
    ALLEGRO_BITMAP** game_mode_menu, ALLEGRO_BITMAP** menu_interface,
    unsigned int* resolution_x, unsigned int* resolution_y, float* FPS) {

    //----Allegro & addons init----//
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    must_init(al_install_mouse(), "mouse");
    must_init(al_init_image_addon(), "bg_image");
    must_init(al_init_font_addon(), "font_addon");
    must_init(al_init_ttf_addon(), "ttf_addon");

    //----POINTER INIT----//
    *timer = al_create_timer(1 / *FPS);
    must_init(*timer, "timer");
    *queue = al_create_event_queue();
    must_init(*queue, "queue");
    *display = al_create_display(*resolution_x, *resolution_y);
    must_init(*display, "display");
    *font = al_load_font("spotify_circular.ttf", 30, 1);
    must_init(*font, "font");
    *main_menu = al_load_bitmap("main_menu.jpg");
    must_init(*main_menu, "main_menu");
    *game_mode_menu = al_load_bitmap("game_mode_menu.jpg");
    must_init(*game_mode_menu, "game_mode_menu");
    *menu_interface = al_load_bitmap("menu_interface.jpg");
    must_init(*menu_interface, "menu_interface");

 

    //----DISPLAY SETTINGS----//
    al_set_window_position(*display, 0, 0);
    al_set_window_title(*display, "QUIZ GAME");

    //----GRAPHICAL SETTINGS----//
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    //----REGISTER EVENTS SETTINGHS----//
    al_register_event_source(*queue, al_get_keyboard_event_source());
    al_register_event_source(*queue, al_get_display_event_source(*display));
    al_register_event_source(*queue, al_get_timer_event_source(*timer));
    al_register_event_source(*queue, al_get_mouse_event_source());
}
