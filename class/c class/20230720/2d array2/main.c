#include <stdio.h>


#define MAX_ARR_SIZE 40




int main(){
	int arr[MAX_ARR_SIZE][MAX_ARR_SIZE];
	int n;

	scanf("%d", &n);

	int init_val = n*n - n + 1, diff;
	for(int i = 0; i < n; ++i){
		diff = 0;
		for(int j = 0; j < n; ++j){
			arr[i][j] = init_val - diff;
			diff += n;
		}
		++init_val;
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%4d ", arr[i][j]);
		}
		putchar('\n');
	}

	return 0;
}