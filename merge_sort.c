#include "merge_sort.h"
#include "string.h"

static S_TYPE *merge_tmp;

//from smaller to bigger
static inline void merge(S_TYPE *yum, S_TYPE start, S_TYPE middle, S_TYPE end)
{
	S_TYPE first = start;
	S_TYPE second = middle + 1;
	S_TYPE index = start;

	while((first <=  middle) && (second <= end)){
		if(yum[first] <= yum[second])
			merge_tmp[index++] = yum[first++];
		else merge_tmp[index++] = yum[second++];
	}

	while(first <= middle){
		merge_tmp[index++] = yum[first++];
	}

	while(second <= end){
		merge_tmp[index++] = yum[second++];
	}

	memcpy(yum, merge_tmp, sizeof(S_TYPE) * (end + 1));
}

static inline void __merge_sort(S_TYPE *yum, S_TYPE start, S_TYPE end)
{
	if(start >= end )
		return;

	int middle = (start + end)/2;
	__merge_sort(yum, start, middle);
	__merge_sort(yum, middle + 1, end);
	merge(yum, start, middle, end);
}
void merge_sort(S_TYPE *yum, S_TYPE n)
{
	merge_tmp = malloc(sizeof(S_TYPE) * n);
	if(!merge_tmp){
		printf("no memory for merge sort tmp array!\n");
		exit(-1);
	}

	__merge_sort(yum, 0, n-1);

	free(merge_tmp);
}
