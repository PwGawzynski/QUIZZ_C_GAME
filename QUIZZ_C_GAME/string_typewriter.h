#pragma once
void string_typewriter(ALLEGRO_FONT** font,char* string,int font_size,
	int box_resolution_x, int box_resolution_y)
{
	bool flag=true;

	int pos_x = box_resolution_x / 2;
	int pos_y = box_resolution_y / 2;
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

	
	char* last_char=strchr(string, '\0');
	const int char_per_line = box_resolution_x / font_size;
	char* tmp_str=(char*)malloc((char_per_line+1));
	while (1)
	{
		if (flag)
		{
			strncpy(tmp_str, string, char_per_line);
			al_draw_text(*font, color, pos_x, pos_y - (font_size / 2),
			             ALLEGRO_ALIGN_CENTER, tmp_str);
			pos_y += font_size + 5;
			
		}
		else
		{
			strncpy(tmp_str, string, char_per_line);
			al_draw_text(*font, color, pos_x, pos_y - font_size / 2,
				ALLEGRO_ALIGN_CENTER, tmp_str);
			break;
		}
		(string + char_per_line+1 )> last_char ? (string += char_per_line+1) : (flag = false);
	}
	free(tmp_str);
	tmp_str = NULL;
}