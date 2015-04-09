#ifndef __RADIX_SORT_H
#define __RADIX_SORT_H
#include "sort.h"

typedef struct{
	S_TYPE *radix_bucket;
	S_TYPE bucket_num;
}radix_sort_bucket_t;

extern void radix_sort(S_TYPE*, S_TYPE);
#endif
