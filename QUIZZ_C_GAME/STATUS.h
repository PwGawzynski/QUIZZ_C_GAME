#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
/**
 * \brief Klatki na sekundę.
 */
const float FPS = 30.0;
const int no_option = 3;
/**
 * \brief szerokość ekranu.
 */
unsigned int resolution_x = 1920;
/**
 * \brief wysokość ekranu.
 */
unsigned int resolution_y = 1080;
/**
 * \brief początkowa ilość pytań w bazie.
 */
unsigned int nr_of_questions_in_base;
/**
 * \brief Funkcja sprawdza czy wartość "test" została zainicjalizowana.
 *
 *	Ta funkcja sprawdza czy wartość która będzie użyta została poprawnie zainicjalizowana.
 *
 * @param description opis.
 * @param test wartość do sprawdzenia.
 * \return true jeżeli dana wartość działa poprawnie.
 *
 */
void must_init(bool test, const char* description)
{
	if (test) return;

	printf("Couldn't initialize %s\n", description);
	exit(1);
}
/**
 * \brief Funkcja sprawdza czy wartość "test" została zainicjalizowana, dodatkowo jeżeli nie zamyka program.
 *
 * @param description opis.
 * @param test wartość do sprawdzenia.
 *
 */
void must_init_exit(bool test, const char* description)
{
	if (test)
	{
		printf("// ____STATUS INFO____ //\n");
		printf("CHECKING: %s\n", description);
		printf("STATUS :: CORRECT\n");
		printf("// ____END OF STATUS INFO____ //\n\n");
	}
	else
	{
		printf("// ____STATUS INFO____ //\n");
		printf("CHECKING: %s\n", description);
		printf("STATUS :: FAILURE\n");
		printf("// ____END OF STATUS INFO____ //\n");
		Sleep(2000);
		exit(1);
	}
}
/**
 * \brief Funkcja sprawdza czy wartość "test" została zainicjalizowana i wypisuję informację czy podana wartość została poprawnie zainicjalizowana..
 *
 * @param description opis.
 * @param test wartość do sprawdzenia.
 * \return true jeżeli dana wartość działa poprawnie.
 *
 */
bool must_init_get_info(bool test, const char* description)
{
	if (test)
	{
		printf("// ____STATUS INFO____ //\n");
		printf("CHECKING: %s\n", description);
		printf("STATUS :: CORRECT\n");
		printf("// ____END OF STATUS INFO____ //\n\n");
		return true;
	}
	else
	{
		printf("// ____STATUS INFO____ //\n");
		printf("CHECKING: %s\n", description);
		printf("STATUS :: FAILURE\n");
		printf("// ____END OF STATUS INFO____ //\n\n");
		return false;
	}
}