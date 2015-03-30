#include "rand_quick_sort.h"

static inline S_TYPE partion(S_TYPE *yum, S_TYPE start, S_TYPE end)
{
	S_TYPE i = start;
	S_TYPE j;
	S_TYPE pivot = yum[start];
	for(j = start + 1; j <= end; j++){
		if(yum[j] < pivot){
			i++;
			swap(&yum[i], &yum[j]);
		}
	}
	return i;
}

static inline void __rand_quick_sort(S_TYPE *yum, S_TYPE start, S_TYPE end)
{
	if(start >= end)
		return;
	
	S_TYPE i = rand() % (end - start + 1) + start;
	swap(&yum[start], &yum[i]);
	
	S_TYPE middle = partion(yum, start, end);
	__rand_quick_sort(yum, start, middle);
	__rand_quick_sort(yum, middle + 1, end);

	return;
}

void rand_quick_sort(S_TYPE *yum, S_TYPE n)
{
	__rand_quick_sort(yum, 0, n-1);
}
