#pragma once
/**
 * \brief Funckja wyświetlająca text na ekranie w odpowiedniej pozycji.
 *
 * @param input łańcuch znaków z tekstem do wyświetlenia.
 * @param resolution_x rozdzielczość pozioma obszaru który ma być wyświetlony.
 * @param resolution_y rozdzielczość pionowa obszaru który ma być wyświetlony.
 * @param positions wskaźnik na tablicę współrzędnych y.
 * @param window oznaczenie odpowiedniego pola.
 * 
 */
quest_writter(ALLEGRO_USTR** input, int* positions, int* resolution_x, int* resolution_y, int window) {
/*draw font on the screen at positions given as position tab, must choose which position will be use using window value*/
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	ALLEGRO_FONT* font = al_load_font("spotify_circular.ttf", 50, 1);
	al_draw_text(font, color,
		*resolution_x / 2, positions[window],
		ALLEGRO_ALIGN_CENTER, al_cstr(*input));
	al_destroy_font(font);
}
/**
 * \brief Funckja wyświetla informację o braku uzupełnionego pola.
 *
 * @param input łańcuch znaków z tekstem do wyświetlenia.
 * @param resolution_x rozdzielczość pozioma obszaru który ma być wyświetlony.
 * @param resolution_y rozdzielczość pionowa obszaru który ma być wyświetlony.
 * @param positions wskaźnik na tablicę współrzędnych y.
 * @param window oznaczenie odpowiedniego pola.
 *
 */
quest_writter_empty(const char** input, int* positions, int* resolution_x, int* resolution_y, int window) {
	ALLEGRO_COLOR color = al_map_rgb(252, 43, 1);
	ALLEGRO_FONT* font = al_load_font("spotify_circular.ttf", 50, 1);
	al_draw_text(font, color,
		*resolution_x / 2, positions[window],
		ALLEGRO_ALIGN_CENTER, *input);
	al_destroy_font(font);
}