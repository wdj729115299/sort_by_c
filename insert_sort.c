void swap(S_TYPE *a, S_TYPE*b)
{
	S_TYPE *tmp;
	*tmp = *a;
	*a = *b;
	*b = *tmp;
}
//smaller to bigger
void sort_action(S_TYPE *yum, S_TYPE n)
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
void insert_sort(S_TYPE *yum, S_TYPE n, void (*print_result)(S_TYPE *yum, S_TYPE n))
{
	sort_action(yum, n);
	print_result(yum, n);
}

