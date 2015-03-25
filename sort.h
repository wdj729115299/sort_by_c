#ifndef __SORT_H
#define __SORT_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>

typedef unsigned int S_TYPE;
#define MAX UINT_MAX

typedef struct sort_ops{
	void (*sort)(S_TYPE *, S_TYPE);
	void (*print_element)(char *desc, S_TYPE *, S_TYPE);
	void (*init)(void (*sort)(S_TYPE *, S_TYPE), void (*print_element)(char *desc, S_TYPE *, S_TYPE));
	void (*action)(S_TYPE *, S_TYPE);
}sort_ops_s;
static void swap(S_TYPE *a, S_TYPE*b)
{
	S_TYPE tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

extern void init(void (*sort)(S_TYPE *, S_TYPE), void (*print_element)(char *desc, S_TYPE *, S_TYPE));
extern void insert_sort(S_TYPE *, S_TYPE , void (*print_result)(char *, S_TYPE *, S_TYPE ));


#ifdef __cplusplus
}
#endif
#endif
