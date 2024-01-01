#include	<stdlib.h>
#include	<stdio.h>

#define NEW_VECTOR (vector*)malloc (sizeof(vector))

typedef struct vector {
	struct vector* next;
	struct vector* prev;
	int32_t data;
} vector;

extern void init_begin();
extern void push_to_begin ();
extern void push_to_end ();
extern void print_node ();
extern void free_all ();
