#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include "sort.h"
#include "insert_sort.h"

#define true 1
#define false 0
#define bool uint16_t

extern struct sort_ops *g_sort_ops;
static S_TYPE g_count;
static S_TYPE *g_yum;

#define SORT_PRINTER 0

void print_element(char *desc, S_TYPE *yum, S_TYPE n)
{
#if SORT_PRINTER
	printf("%s\n", desc);
	S_TYPE i;
	for(i = 0; i < n; i++){
		if(i == 0 || i % 16 != 0)
			printf("%u ", yum[i]);
		else printf("\n%u ", yum[i]);
	}
	printf("\n");
#endif
}

void usage()
{
	S_TYPE i;
	bool get_number = false;
	
	printf("Hello! Welcome to Kevin's sorting world!\n");
	printf("First of all,");

	while(!get_number){
		printf("input the count of number you want to sort:");
		if(!scanf("%u", &g_count)){
			printf("input error,please input number!\n");
			continue;
		}
		printf("starting producing %u numbers now,waitting...\n", g_count);

		g_yum = malloc(g_count * sizeof(S_TYPE));
		if(g_yum == NULL){
			printf("no memory for %u numbers", g_count);
			continue;
		}else get_number = true;
	}

	for(i = 0; i < g_count; i++){
		g_yum[i] = rand() % MAX;
	}
	print_element("before sorting:", g_yum, g_count);
}
int main(int argc, char *argv[])
{
	
	usage();
	
	if(g_yum == NULL || g_count <= 0)
		return -1;
	
	g_sort_ops = malloc(sizeof(*g_sort_ops));
	if(!g_sort_ops){
		printf("no memory for sort_ops!\n");
		return -1;
	}
	
	g_sort_ops->init = init;
	g_sort_ops->init(insert_sort_action, print_element);
	g_sort_ops->action(g_yum, g_count);

	free(g_yum);

	return 0;
}
