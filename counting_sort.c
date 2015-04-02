#include "counting_sort.h"
#include "sort.h"

void __counting_sort(S_TYPE *yum, S_TYPE n, S_TYPE min, S_TYPE max)
{
	struct timeval tv_start, tv_end;
	gettimeofday(&tv_start, NULL);
	printf("start sorting!\n");
	
	int i;

	S_TYPE *tmp = malloc(sizeof(S_TYPE) *(max-min+1));
	if(!tmp){
		printf("no memory for counting sort tmp!\n");
		exit(-1);
	}
	memset(tmp, 0, sizeof(S_TYPE) *(max-min+1));

	for(i = 0; i < n; i++){
		if(yum[i] < min || yum[i] > max){
			printf("fatal input!\n");
			exit(-1);
		}
		tmp[yum[i] - min]++;
	}
	
	int  z = 0;
	for(i = 0; i < max - min + 1; i++){
		while(tmp[i]-- > 0){
			yum[z++] = min + i;
		}
	}

	printf("end sorting!\n");
	print_element("after sort:", yum, n);
	gettimeofday(&tv_end, NULL);

	unsigned long tv = tv_end.tv_sec * 1000000 + tv_end.tv_usec - tv_start.tv_sec * 1000000 - tv_start.tv_usec;
	printf("%lu us\n", tv);
}

void counting_sort(S_TYPE *yum, S_TYPE n, S_TYPE min, S_TYPE max)
{
	__counting_sort(yum, n, min, max);
}
