#include "sort.h"
#include <sys/time.h>

struct sort_ops *g_sort_ops;

static void action(S_TYPE *yum, S_TYPE n)
{
	struct timeval tv_start, tv_end;
	gettimeofday(&tv_start, NULL);
	printf("start sorting!\n");
	g_sort_ops->sort(yum, n);
	printf("end sorting!\n");
	g_sort_ops->print_element("after sort:", yum, n);
	gettimeofday(&tv_end, NULL);

	unsigned long tv = tv_end.tv_sec * 1000000 + tv_end.tv_usec - tv_start.tv_sec * 1000000 - tv_start.tv_usec;
	printf("%lu us\n", tv);
}

void global_task_init(void (*sort)(S_TYPE *, S_TYPE), void (*print_element)(char *desc, S_TYPE *, S_TYPE))
{
	g_sort_ops = malloc(sizeof(*g_sort_ops));
	if(!g_sort_ops){
		printf("no memory for sort_ops!\n");
		exit(-1);
	}
	
	g_sort_ops->sort = sort;
	g_sort_ops->print_element = print_element;
	g_sort_ops->action = action;
}
