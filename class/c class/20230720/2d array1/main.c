#include <stdio.h>


#define MAX_ARR_SIZE 40




int main(){
	int arr[MAX_ARR_SIZE][MAX_ARR_SIZE];
	int n;
	int num = 1;

	scanf("%d", &n);

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			arr[i][j] = num++;
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%4d ", arr[i][j]);
		}
		putchar('\n');
	}

	return 0;
}