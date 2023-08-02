#include <stdio.h>




int main(){
	int bal;
	printf("한달 용돈을 입력해주세요: ");
	scanf("%d", &bal);

	int p1, p2, p3;
	printf("살 물건 3개의 가격을 입력해주세요: ");
	scanf("%d %d %d", &p1, &p2, &p3);

	int temp;
	if(p1 < p2 && p1 < p3){
		temp = p1;
		p1 = p3;
		p3 = temp;
	}
	else if(p2 < p3){
		temp = p2;
		p2 = p3;
		p3 = temp;
	}


	int case_cnt = 0;

	bal -= p1 + p2 + p3;
	int p1_maxCnt = bal/p1, p2_maxCnt;
	for(int i = 0; i <= p1_maxCnt; ++i){
		p2_maxCnt = (bal - p1*i)/p2;
		for(int j = 0; j <= p2_maxCnt; ++j){
			++case_cnt;
		}
	}

	printf("\n%d", case_cnt);


	return 0;
}