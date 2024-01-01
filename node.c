 /*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description: just test ide for C 
 *
 *        Created:  16/12/23 22:21:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  FirelessWidelity, viyskiy@gmail.com
 *
 * =====================================================================================
 */

#include "node.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  linked list for enjoy
 *  
 * =====================================================================================
 */

static vector* HEAD;
static vector* END;

int main (int argc, char *argv[]) {

	init_begin(0);
	
	int tmp = 0;
	while (tmp < 10) {
		push_to_end(++tmp);
	}

	print_node ();
	free_all ();

	return EXIT_SUCCESS;
}

void init_begin (int32_t data) {
	vector* first_el = NULL;
	first_el = NEW_VECTOR;
	first_el->data = data;
	first_el->prev = NULL;
	first_el->next = NULL;
	HEAD = first_el;
	END  = first_el;
}

void push_to_begin (int32_t data) {
	vector* el = NULL;
	el = NEW_VECTOR;

	el->next = HEAD;
	el->prev = NULL;
	el->data = data;

	HEAD->prev = el;
	HEAD = el;
}

void push_to_end (int32_t data) {
	vector* el = NULL;
	el = NEW_VECTOR;

	END->next = el;

	el->prev = END;
	el->next = NULL;
	el->data = data;

	END = el;
}

void free_all () {
    vector* p = HEAD;
    vector* el = p->next;

    int tmp = 0;
    while (el) {
        free (p);
        p = el;
	    printf ("\n deleted %d el", ++tmp);
        el = el->next;
    }
}

void print_node () {
	vector* p = HEAD;
	int tmp;
	for (tmp = 1; ;) {
		printf ("\n counter: %d, data: %d", tmp++, p->data);
		if (p->next == NULL) {
			break;
		}
		p = p->next;
	}
}
