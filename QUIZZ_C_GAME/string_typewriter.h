#pragma once
/**
 * \brief Funkcja odpowiadająca za wyświetlanie wielolinijkowe pytań w danym obszarze. 
 *
 * @param string ciąg znaków.
 * @param font podwójny wskaźnik na font biblioteki allegro.
 * @param font_size wielkość czcionki.
 * @param box_resolution_x szerokość boxa.
 * @param box_resolution_y wysokość boxa.
 * @param pos_x pozycja w osi x położenia teksu.
 * @param pos_y pozycja w osi y położenia teksu.
 * @param margin_up margin up.
 */
void string_typewriter(ALLEGRO_FONT** font, char* string, int font_size,
	int box_resolution_x, int box_resolution_y, /*center of box*/ int pos_x, /*top edge*/ int pos_y, int margin_up)
{
	/*flag to break while*/
	bool flag = true;

	/*allegro color*/
	ALLEGRO_COLOR color_white = al_map_rgb(255, 255, 255);

	pos_y += margin_up;

	char* last_char = strchr(string, '\0');
	const int char_per_line = box_resolution_x / font_size;
	char* tmp_str = (char*)malloc((char_per_line + 1));
	while (1)
	{
		//if ((pos_y + font_size) > box_resolution_y)break;
		if (flag)
		{
			strncpy(tmp_str, string, char_per_line);
			al_draw_text(*font, color_white , pos_x, pos_y - (font_size / 2),
				ALLEGRO_ALIGN_CENTER, tmp_str);
			pos_y += font_size + 5;

		}
		else
		{
			strncpy(tmp_str, string, char_per_line);
			al_draw_text(*font, color_white , pos_x, pos_y - font_size / 2,
				ALLEGRO_ALIGN_CENTER, tmp_str);
			break;
		}
		/*check if remained string is bigger then possible to write on screen string.*/
		/*if it is not pointer is placed on the top of the rest
		 *(It won't be possible to cross string end 'couse of flag which will trigger break while loop */
		if ((string + char_per_line + 1) > last_char) {
			(string += char_per_line + 1);
			(flag = false);
		}
		else {
			(string += char_per_line + 1);
		}
	}
	/*clearing tmp_string allocated mem */
	free(tmp_str);
	tmp_str = NULL;
}