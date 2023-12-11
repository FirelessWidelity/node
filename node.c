 /*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description: just test ide for C 
 *
 *        Created:  12/09/23 22:21:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  FirelessWidelity, viyskiy@gmail.com
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include	<stdio.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Двусвязный список. Добавление элемента в начало и конец списка, вывод
 *  информации, высвобождение выделенной памяти.
 * =====================================================================================
 */

#define NEW_VECTOR (vector*)malloc (sizeof(vector))

typedef struct vector {
	struct vector* next;
	struct vector* prev;
    union {
	    struct vector* HEAD;
    };
	union {
		int32_t data;
	};

} vector;

void push_to_begin (vector* V, vector* p);
void push_to_end (vector* V, vector* p);
void print_node (vector *p);
void free_all (vector* p);
vector* find_first_el (vector* p);
vector* find_last_el (vector* p);

int main ( int argc, char *argv[] ) {

	vector* begin = NEW_VECTOR;
	begin->HEAD = begin;
	begin->data = 100;

	vector* MASS;
	MASS = (vector*) malloc (sizeof(vector) * 10);
	int tmp;
	for (tmp = 0; tmp < 10; ++tmp) {
		push_to_end (&MASS[tmp], begin);
	}

  	vector* second = NEW_VECTOR;
  	push_to_end (second, begin);

	vector* three = NEW_VECTOR;
	push_to_end (three, begin);

	vector* four = NEW_VECTOR;
	push_to_begin (four, begin);

	vector* five = NEW_VECTOR;
	push_to_begin (five, four);

	vector* p = four;

	print_node (p);

	free_all (p);

	return EXIT_SUCCESS;
}

void push_to_begin (vector* V, vector* p) {
	p = find_first_el (p);
	p->prev = V;
	p->HEAD = NULL;
	V->prev = NULL;
	V->next = p;
	V->HEAD = V;
	V->data = p->data - 100;
}

void free_all (vector* p) {
    p = find_first_el (p);
    vector* el = p->next;

    int tmp = 0;
    while (el) {
        free (p);
        p = el;
	    printf ("\n deleted %d el", ++tmp);
        el = el->next;
    }
}

void push_to_end (vector* V, vector* p) {
	p = find_last_el (p);

	p->next = V;
	V->next = NULL;
	V->prev = p;
	V->data = p->data + 100;
}

void print_node (vector *p) {
	p = find_first_el (p);
	int tmp;
	for (tmp = 1; ;) {
		printf ("\n counter: %d, data: %d", tmp++, p->data);
		if (p->next == NULL) {
			break;
		}
		p = p->next;
	}
}

vector* find_first_el (vector* p) {
	while (p->HEAD == NULL) {
		p = p->prev;
	}
	return p;
}


vector* find_last_el (vector* p) {
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}
