#include <stdio.h>

#include <stdlib.h>
#include <time.h>
#include <string.h>


#define NUM_CNT 3
#define	MAX_TRY 20
#define MAX_PRINTSTR_LEN 40 // current length: 36




int main(){
	srand((unsigned int) time(NULL));
	

	char history[MAX_TRY][MAX_PRINTSTR_LEN];

	int num[NUM_CNT]; // input numbers
	int num_cnt[10]; // count input numbers; idx: 1~9
	int ans[NUM_CNT]; // answer numbers
	int ans_cnt[10] = {0}; // count answer numbers

	for(int i = 0; i < NUM_CNT; ++i){
		ans[i] = rand()%9 + 1;
		// if duplicate not allowed? -> pick again
		++ans_cnt[ans[i]];
	}


	int s_cnt, b_cnt; // strike count, ball count

	int attempt;
	printf("Enter four numbers ranged 1 to 9 until you hit %d strikes.\n\n", NUM_CNT);
	for(attempt = 0; attempt < 20; ++attempt){
		memset(num_cnt, 0, sizeof(num_cnt));

		s_cnt = 0, b_cnt = 0;


		for(int i = 0; i < NUM_CNT; ++i){
			scanf("%d", num + i);
			++num_cnt[num[i]];
		}

		for(int n = 1; n <= 9; ++n){
			if(ans_cnt[n] > 0){
				b_cnt += ans_cnt[n] > num_cnt[n] ? num_cnt[n] : ans_cnt[n];
				// count ball and strike first
			}
		}
		

		for(int i = 0; i < NUM_CNT; ++i){
			if(num[i] == ans[i]){
				++s_cnt;
			}
		}
		b_cnt -= s_cnt;

		
		system("cls");
		for(int i = 0; i < NUM_CNT; ++i){
			sprintf(history[attempt] + i*2, "%d ", num[i]); // length: 2*4
		}
		sprintf(history[attempt] + NUM_CNT*2,
			"    %d strike, %d ball --- %d", s_cnt, b_cnt, attempt + 1); // length: 27 + 1

		for(int j = 0; j <= attempt; ++j){
			printf("%s\n", history[j]);
		}
		putchar('\n');

		
		if(s_cnt == NUM_CNT) break;
	}

	if(s_cnt == NUM_CNT){
		printf("You won! The answer was ");
		for(int i = 0; i < NUM_CNT; ++i) printf("%d ", ans[i]);
		printf("\b!\nattempts you used: %d\n\n", attempt + 1);
	}
	else{
		printf("You lose... (the answer was ");
		for(int i = 0; i < NUM_CNT; ++i) printf("%d ", ans[i]);
		printf("\b)\n\n");
	}
	system("pause");


	return 0;
}