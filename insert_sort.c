#include "sort.h"
//smaller to bigger
void insert_sort_action(S_TYPE *yum, S_TYPE n)
{
	S_TYPE i,j;
	for(i = 1; i < n; i++){
		for(j = i; j >= 1; j--){
			if(yum[j] >= yum[j - 1])
				break;
			else swap(&yum[j], &yum[j-1]);
		}
	}
}
