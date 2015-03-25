#include <stdio.h>
#include <limits.h>

void print_result(S_TYPE *yum, S_TYPE n)
{
	S_TYPE i;
	for(i = 0; i < n; i++){
		if(i != 0 && i % 16 == 0)
			printf("%u ", yum[i]);
		else printf("\n");
	}
}
int main(int argc, char *argv[])
{
	S_TYPE n;
	S_TYPE i;
	S_TYPE *yum;
	bool get_number = false;
	
	printf("Hello! Welcome to Kevin's sorting world!\n");
	printf("First of all,");

	while(!get_number){
		printf("input the count of number you want to sort:");
		if(!scanf("%u", &n)){
			printf("input error,please input number!\n");
			continue;
		}
		printf("starting producing %u numbers now,waitting...\n", n);

		yum = malloc(n * sizeof(S_TYPE));
		if(yum == NULL){
			printf("no memory for %u numbers", n);
			continue;
		}else get_number = true;
	}
	for(i = 0; i < n; i++){
		yum[i] = rand() % MAX;
	}
	insert_sort(yum, n, print_result);
}
hehehehhee

