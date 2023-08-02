#include <stdio.h>




int main(){
	printf("세 개의 물건값을 입력하세요 : ");

	int price1, price2, price3;
	scanf_s("%d %d %d", &price1, &price2, &price3);

	int change = 10000 - price1 - price2 - price3;
	printf("거스름돈은 %d원입니다.\n", change);

	printf("오천원권 : %d장\n", change/5000);
	change %= 5000;
	printf("천원권 : %d장\n", change/1000);
	change %= 1000;
	printf("오백원짜리 동전 : %d개\n", change/500);
	change %= 500;
	printf("백원짜리 동전 : %d개\n", change/100);
	change %= 100;
	printf("오십원짜리 동전 : %d개\n", change/50);
	change %= 50;
	printf("십원짜리 동전 : %d개", change/10);

	return 0;
}