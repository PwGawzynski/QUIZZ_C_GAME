#pragma once
/**
 * \brief Struktura potrzebna do przechowywania pojedynczego pytania.
 */
struct questions
{
	int id;
	char* question;
	char* answer_a;
	char* answer_b;
	char* answer_c;
	char* answer_d;
	char* correct;
	struct questions* next;
};
/**
 * \brief Własny typ wskaźnika na strukturę.
 */
typedef struct questions* p_questions;
/**
 * \brief Własny typ podwójnego wskaźnika na strukturę.
 */
typedef struct questions** ref_questions;
p_questions head_of_questions;
p_questions tmp_head;
/**
 * \brief Struktura potrzebna do wczytywania pytań.
 */
struct questions_tmp
{
	int id;
	char* question;
	char* answer_a;
	char* answer_b;
	char* answer_c;
	char* answer_d;
	char* correct;
};
/**
 * \brief Własny typ wskaźnika na strukturę.
 */
typedef struct questions_tmp* p_questions_tmp;
/**
 * \brief Własny typ podwójnego wskaźnika na strukturę.
 */
typedef struct questions_tmp** ref_questions_tmp;

struct questions_tmp tmp_question;
/**
 * \brief Inicjalizuje pamięć na łańcuch znaków pytania.
 */
void load_mem_for_questions_ptrs()
{
	tmp_question.question = (const char*)malloc(1); 
	tmp_question.answer_a = (const char*)malloc(1); 
	tmp_question.answer_b = (const char*)malloc(1); 
	tmp_question.answer_c = (const char*)malloc(1); 
	tmp_question.answer_d = (const char*)malloc(1); 
	tmp_question.correct = (const char*)malloc(1);

	
}
/**
 * \brief Czyści pamięć zaalokowaną dla łańcucha znaków pytań.
 */
void kill_mem_for_questions_ptrs()
{
	free(tmp_question.question);
	tmp_question.question = NULL;
	free(tmp_question.answer_a);
	tmp_question.answer_a = NULL;
	free(tmp_question.answer_b);
	tmp_question.answer_b = NULL;
	free(tmp_question.answer_c);
	tmp_question.answer_c = NULL;
	free(tmp_question.answer_d);
	tmp_question.answer_d = NULL;
	free(tmp_question.correct);
	tmp_question.correct = NULL;
}
/**
 * \brief Usuwa zaalokowaną pamięć dla listy pytań.
 */
void kill_quest_list()
{
	while(head_of_questions)
	{
		p_questions next = head_of_questions->next;
		kill_mem_for_questions_ptrs();
		free(head_of_questions);
		head_of_questions = NULL;
		head_of_questions = next;
	}
	
}
/**
 * \brief Struktura przechowująca dane graczy w trybie multiplayer.
 */
struct players
{
	int player_nr;
	int points;
	int lives;
	struct players* next;
};

struct players* player = NULL;
/**
 * \brief Własny typ wskaźnika na strukturę.
 */
typedef struct players* p_player;