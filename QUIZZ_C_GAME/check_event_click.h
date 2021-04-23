#pragma once
int check_event_click(unsigned int* mouse_x, unsigned int* mouse_y, int* which_menu)
{
	if ((*which_menu) == 1)
	{
		//main menu
		if (((*mouse_x >= 294) && (*mouse_x <= 782)) && ((*mouse_y >= 395) && (*mouse_y <= 607))) { (*which_menu) = 2; return 1; } // jednoosobowy
		if (((*mouse_x >= 294) && (*mouse_x <= 782)) && ((*mouse_y >= 635) && (*mouse_y <= 847))) return 2; // wieloosobowy
		if (((*mouse_x >= 813) && (*mouse_x <= 1129)) && ((*mouse_y >= 396) && (*mouse_y <= 847))) return 3; // dodaj pytanie
		if (((*mouse_x >= 1159) && (*mouse_x <= 1619)) && ((*mouse_y >= 586) && (*mouse_y <= 847))) return 4; // wyjscie
	}
	if ((*which_menu) == 2)
	{
		//game mode menu 
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 305) && (*mouse_y <= 484))) { (*which_menu) = 3; return 5; } // trening
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 520) && (*mouse_y <= 699))) return 6;  // 3 zycia
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 735) && (*mouse_y <= 914))) return 7; // hardcore
	}
	if ((*which_menu) == 3)
	{
		//menu_interface 
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 404) && (*mouse_y <= 538))) return 8; // odpowiedz a
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 555) && (*mouse_y <= 689))) return 9;  // odpowiedz b
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 707) && (*mouse_y <= 841))) return 10; // odpowiedz c
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 859) && (*mouse_y <= 993))) return 11; // odpowiedz d
	}
}
