#pragma once
#include "init_structures.h"
#include <time.h>

FILE* file;
/// <summary>
/// must be from 1!!!
/// </summary>
unsigned int id = 1;

void scan_file();
void add_questions();
void get_quest_from_usr();
void write_to_file();
void read_from_file();
void free_all_allocated_strings();
void create_list();
p_questions create_head(p_questions head);
void create_next_list_el(ref_questions el);
bool is_id_in_array(int* array, int id);

void load_saved_info()
{
	file = fopen("database.bin", "rb+");
	must_init_get_info(file, "FILE WITH SAVED QUESTIONS");
}

void scan_file()
{
	if(file)
	{
		read_from_file();
		fclose(file);
	}
	else 
	{
		file = fopen("database.bin", "wb+");
		must_init_get_info(file, "FILE WITH SAVED QUESTIONS");
		add_questions();
		fclose(file);
	}
}

void get_quest_from_usr()
{
	
	// clears stdin buffer from \n char which has left 
	fseek(stdin, 0, SEEK_END);
	
	printf("Wprowadz pytanie: \n\n");
	tmp_question.question = read_str();

	printf("\n");

	printf("Wprowadz odpowiedz A: ");
	tmp_question.answer_a = read_str();
	
	printf("\n");

	printf("Wprowadz odpowiedz B: ");
	tmp_question.answer_b = read_str();
	
	printf("\n");

	printf("Wprowadz odpowiedz C: ");
	tmp_question.answer_c = read_str();
	
	printf("\n");

	printf("Wprowadz odpowiedz D: ");
	tmp_question.answer_d = read_str();
	
	printf("\n");

	printf("Wprowadz oznaczenie poprawnej odpowiedzi: ");
	scanf("%c", tmp_question.correct);

	printf("\n");
	
}

void add_questions()
{
	int questions_number;
	printf(" Ile pytan chcesz dodac: ");
	scanf("%d", &questions_number);
	fwrite(&questions_number, sizeof(int), 1, file);
	while(questions_number)
	{
		load_mem_for_questions_ptrs();

		tmp_question.id = id;
		id++;
		
		get_quest_from_usr();
		write_to_file();
		free_all_allocated_strings();
		questions_number--;
	}
}

int get_str_len(char* string)
{
	int counter = 0;
	while (*string != '\0') {
		counter++; string++;
	}
	return counter+1;
}

void write_to_file()
{
	int struct_size;
	
	fwrite(&tmp_question.id, sizeof(int), 1, file);
	
	struct_size = get_str_len(tmp_question.question);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.question, 1, struct_size, file);
	
	struct_size = get_str_len(tmp_question.answer_a);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.answer_a, 1, struct_size, file);
	
	struct_size = get_str_len(tmp_question.answer_b);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.answer_b, 1, struct_size, file);
	
	struct_size = get_str_len(tmp_question.answer_c);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.answer_c, 1, struct_size, file);
	
	struct_size = get_str_len(tmp_question.answer_d);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.answer_d, 1, struct_size, file);
	
	struct_size = sizeof(int);
	fwrite(&struct_size, sizeof(int), 1, file);
	fwrite(tmp_question.correct, sizeof(int), 1, file);
}
void read_from_file()
{
	int ids_tab[10]={ 0 };
	int struct_size=0;
	int number_of_struct;
	int random_number;
	int random_number_next;
	int el_counter = 0;
	int tab_counter = 0;
	int debug_position_crs;
	bool flag_end_of_struct=false;
	fread(&number_of_struct, sizeof(int), 1, file);
	srand(time(NULL));
	random_number = rand() % number_of_struct + 1;
	while (fread(&tmp_question.id, sizeof(int), 1, file))
	{
		el_counter = 0;
		if (tmp_question.id==random_number) 
			fread(&struct_size, sizeof(int), 1, file);
		while (tmp_question.id!=random_number && ++el_counter)
		{
			if (!flag_end_of_struct|| tmp_question.id == 1) {
				fread(&struct_size,
					sizeof(int), 1, file);
			}
			
			flag_end_of_struct = false; //change 
			fseek(file, struct_size, SEEK_CUR);// be careful 
			if (el_counter == 6) {
				fread(&tmp_question.id, sizeof(int), 1, file);
				fread(&struct_size, sizeof(int), 1, file);
				el_counter=0;
				flag_end_of_struct = true;
			}
		}
		
		
		
		
		printf("%d\n", tmp_question.id);
		
		tmp_question.question = (char*)malloc(struct_size * sizeof(char));
		fread(tmp_question.question, struct_size, 1, file);
		printf("%s\n", tmp_question.question);
		
		fread(&struct_size, sizeof(int), 1, file);
		tmp_question.answer_a= (char*)malloc(struct_size );
		fread(tmp_question.answer_a, 1, struct_size, file);
		printf("%s\n", tmp_question.answer_a);

		fread(&struct_size, sizeof(int), 1, file);
		tmp_question.answer_b = (char*)malloc(struct_size );
		fread(tmp_question.answer_b, 1, struct_size, file);
		printf("%s\n", tmp_question.answer_b);

		fread(&struct_size, sizeof(int), 1, file);
		tmp_question.answer_c = (char*)malloc(struct_size );
		fread(tmp_question.answer_c, 1, struct_size, file);
		printf("%s\n", tmp_question.answer_c);

		fread(&struct_size, sizeof(int), 1, file);
		tmp_question.answer_d = (char*)malloc(struct_size );
		fread(tmp_question.answer_d, 1, struct_size, file);
		printf("%s\n", tmp_question.answer_d);

		fread(&struct_size, sizeof(int), 1, file);
		tmp_question.correct = (char*)malloc(struct_size );
		fread(tmp_question.correct, sizeof(int), 1, file);
		printf("%c\n", tmp_question.correct[0]);
		printf("\n");
		//set ids in arr of ids
		ids_tab[tab_counter] = tmp_question.id;
		tab_counter++;
		//break if all was read 
		if (ids_tab[9])break;
		
		create_list();
		if (random_number==number_of_struct)
		{
			fseek(file, sizeof(int), SEEK_SET);
			while ((random_number_next = rand() % number_of_struct + 1) == random_number);
		}else 
		while ((random_number_next = rand() % number_of_struct + 1) == random_number);

		if(random_number_next>random_number)
		{
			random_number = random_number_next;
			while (is_id_in_array(ids_tab, random_number))
				random_number = rand() % number_of_struct + 1;
			//even if the number has been cheecked the new number can be bigger or smaller then last read struct and this occurred infinite loop
			if (random_number > tmp_question.id);
			else fseek(file, sizeof(int), SEEK_SET);
			flag_end_of_struct = false;
		}else
		{
			random_number = random_number_next;
			while (is_id_in_array(ids_tab, random_number))
				random_number = rand() % number_of_struct + 1;
			
				fseek(file, sizeof(int), SEEK_SET);

				flag_end_of_struct = false;
		}

	}
}
void free_all_allocated_strings()
{
	free(tmp_question.question);
	tmp_question.question = NULL;
	must_init_get_info(!tmp_question.question, 
		"CORRECT IF ALLOCATED STR_question WAS KILLED");

	free(tmp_question.answer_a);
	tmp_question.answer_a = NULL;
	must_init_get_info(!tmp_question.answer_a,
		"CORRECT IF ALLOCATED STR_answer_a WAS KILLED");

	free(tmp_question.answer_b);
	tmp_question.answer_b = NULL;
	must_init_get_info(!tmp_question.answer_b,
		"CORRECT IF ALLOCATED STR_answer_b WAS KILLED");

	free(tmp_question.answer_c);
	tmp_question.answer_c = NULL;
	must_init_get_info(!tmp_question.answer_c,
		"CORRECT IF ALLOCATED STR_answer_c WAS KILLED");

	free(tmp_question.answer_d);
	tmp_question.answer_d = NULL;
	must_init_get_info(!tmp_question.answer_d,
		"CORRECT IF ALLOCATED STR_answer_d WAS KILLED");

	free(tmp_question.correct);
	tmp_question.correct = NULL;
	must_init_get_info(!tmp_question.correct,
		"CORRECT IF ALLOCATED STR_answer_d WAS KILLED");
}


void create_list()
{
	if(!head_of_questions)
	{
		head_of_questions = (p_questions)malloc(sizeof(struct questions));
		tmp_head = create_head(head_of_questions);
	}else
	{
		create_next_list_el(&tmp_head);
	}
}

p_questions create_head(p_questions head)
{
	head->id = tmp_question.id;
	head->question = tmp_question.question;
	head->answer_a = tmp_question.answer_a;
	head->answer_b = tmp_question.answer_b;
	head->answer_c = tmp_question.answer_c;
	head->answer_d = tmp_question.answer_d;
	head->correct = tmp_question.correct;
	head->next = NULL;
	return head;
}

void create_next_list_el(ref_questions el)
{
	p_questions new_quest = (p_questions)malloc(sizeof(struct questions));
	new_quest->id = tmp_question.id;
	new_quest->question = tmp_question.question;
	new_quest->answer_a = tmp_question.answer_a;
	new_quest->answer_b = tmp_question.answer_b;
	new_quest->answer_c = tmp_question.answer_c;
	new_quest->answer_d = tmp_question.answer_d;
	new_quest->correct = tmp_question.correct;
	new_quest->next = NULL;
	(*el)->next = new_quest;
	(*el) = new_quest;
}

bool is_id_in_array(int* array,int id)
{
	for(int i=0; array[i]!=0;i++)
		if(array[i]==id) return true;
	return false;
}