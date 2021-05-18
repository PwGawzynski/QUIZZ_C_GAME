#pragma once
void quest_writter(ALLEGRO_USTR** input, int* positions, int* resolution_x, int* resolution_y, int*window){
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	ALLEGRO_FONT* font = al_load_font("spotify_circular.ttf", 50, 1);
	al_draw_text(font, color,
		*resolution_x / 2, positions[*window],
		ALLEGRO_ALIGN_CENTER, al_cstr(*input));
	al_destroy_font(font);
	
}