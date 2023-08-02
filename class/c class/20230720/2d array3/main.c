#include <stdio.h>


#define MAX_ARR_LEN 40




int main(){
	int n;
	scanf("%d", &n);

	int arr[MAX_ARR_LEN][MAX_ARR_LEN];
	
	int base = 0;
	int diff = 4*(n - 1);
	int bias;
	int i_limit;

	for(int k = 0; k < n/2; ++k){
		bias = 1;
		i_limit = n - k - 1;

		for(int i = k; i < i_limit; ++i){
			arr[k][i] = base + bias;
			++bias;
		}
		for(int i = k; i < i_limit; ++i){
			arr[i][i_limit] = base + bias;
			++bias;
		}
		for(int i = k; i < i_limit; ++i){
			arr[i_limit][n - i - 1] = base + bias;
			++bias;
		}
		for(int i = k; i < i_limit; ++i){
			arr[n - i - 1][k] = base + bias;
			++bias;
		}

		base += diff;
		diff -= 8;
	}
	if(n%2 == 1){
		arr[n/2][n/2] = n*n;
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%4d ", arr[i][j]);
		}
		putchar('\n');
	}

	return 0;
}