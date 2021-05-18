#pragma once
int check_event_click(unsigned int* mouse_x, unsigned int* mouse_y, int* which_menu)
{
	if ((*which_menu) == 1)
	{
		/* Main menu */
		if (((*mouse_x >= 294) && (*mouse_x <= 782)) && ((*mouse_y >= 395) && (*mouse_y <= 607))) { (*which_menu) = 2; return 1; } // singleplayer
		if (((*mouse_x >= 294) && (*mouse_x <= 782)) && ((*mouse_y >= 635) && (*mouse_y <= 847))) return 2; // multiplayer
		if (((*mouse_x >= 813) && (*mouse_x <= 1129)) && ((*mouse_y >= 396) && (*mouse_y <= 847))) return 3; // add question
		if (((*mouse_x >= 1159) && (*mouse_x <= 1619)) && ((*mouse_y >= 586) && (*mouse_y <= 847))) return 12; // leave game
	}
	if ((*which_menu) == 2)
	{
		/* Game mode menu */
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 305) && (*mouse_y <= 484))) { (*which_menu) = 3; return 5; } // trening
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 520) && (*mouse_y <= 699))) return 6;  // 3 lifes
		if (((*mouse_x >= 444) && (*mouse_x <= 1476)) && ((*mouse_y >= 735) && (*mouse_y <= 914))) return 7; // hardcore
	}
	if ((*which_menu) == 3)
	{
		/* Menu Interface */
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 404) && (*mouse_y <= 538))) return 8; // ans a
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 555) && (*mouse_y <= 689))) return 9;  // ans b
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 707) && (*mouse_y <= 841))) return 10; // ans c
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 859) && (*mouse_y <= 993))) return 11; // ans d
	}
	if ((*which_menu) == 4)
	{
		/* Scoreboard */
		if (((*mouse_x >= 1159) && (*mouse_x <= 1619)) && ((*mouse_y >= 349) && (*mouse_y <= 610))) { (*which_menu) = 2; return 1; } // play again
		if (((*mouse_x >= 1159) && (*mouse_x <= 1619)) && ((*mouse_y >= 630) && (*mouse_y <= 891))) { (*which_menu) = 1; return 0; } // exit to main menu
	}
	if ((*which_menu) == 5)
	{
		/* Question Creator */
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 140) && (*mouse_y <= 356))) return 1; // question
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 404) && (*mouse_y <= 538))) return 2; // ans a
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 555) && (*mouse_y <= 689))) return 3;  // ans b
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 707) && (*mouse_y <= 841))) return 4; // ans c
		if (((*mouse_x >= 306) && (*mouse_x <= 1614)) && ((*mouse_y >= 859) && (*mouse_y <= 993))) return 5; // ans d
		if (((*mouse_x >= 686) && (*mouse_x <= 1031)) && ((*mouse_y >= 57) && (*mouse_y <= 125))) return 6; // add question
		if (((*mouse_x >= 1048) && (*mouse_x <= 1440)) && ((*mouse_y >= 57) && (*mouse_y <= 125))) return 7; // leave to menu
	}
}
