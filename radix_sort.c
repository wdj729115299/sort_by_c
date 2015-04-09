#include "radix_sort.h"
#include <math.h>

S_TYPE get_max(S_TYPE *yum, S_TYPE n)
{
	S_TYPE i, max = 0;
	for(i = 0; i < n; i++){
		if(yum[i] > max)
			max = yum[i];
	}

	return max;
}

void yum_push(S_TYPE *yum, S_TYPE n, radix_sort_bucket_t *bucket)
{
	int i;
	S_TYPE yum_index = 0, j;
	
	for(i = 0; i< 10; i++){
		for(j = 0; j < bucket[i].bucket_num; j++){
			yum[yum_index++] = bucket[i].radix_bucket[j];
		}
	}
}

void __radix_sort(S_TYPE *yum, S_TYPE n, radix_sort_bucket_t *bucket, int weight)
{
	int i;
	int w = 0;
	while(w < weight){
		for(i = 0; i < n; i++){
			int index = yum[i]/(S_TYPE)pow(10,w)? (yum[i]/(S_TYPE)pow(10,w))%10 : 0;
			S_TYPE num = bucket[index].bucket_num;
			bucket[index].radix_bucket[num] = yum[i];
			bucket[index].bucket_num++;
		}
		yum_push(yum, n, bucket);
		w++;
	}

	
}

void radix_sort(S_TYPE *yum, S_TYPE n)
{
	radix_sort_bucket_t *bucket;
	int i;
	int weight = 1;
	bucket = malloc(10 * sizeof(radix_sort_bucket_t));
	if(!bucket){
		printf("no memory for radix sort bucket!\n");
		exit(-1);
	}

	for(i = 0; i < 10; i++){
		bucket[i].radix_bucket = malloc(sizeof(S_TYPE) * n);
		bucket[i].bucket_num = 0;
		if(!bucket[i].radix_bucket){
			printf("no memory for radix sort radix_bucket!\n");
			exit(-1);
		}
	}

	S_TYPE max = get_max(yum, n);
	while((max = max/10) !=0){
		weight++;
	}

	__radix_sort(yum, n, bucket, weight);

	free(bucket);

	return;
}
