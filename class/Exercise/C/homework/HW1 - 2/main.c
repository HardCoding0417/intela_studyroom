#include <stdio.h>




int main(){
	double weight, height;

	printf("몸무게(kg)와 키(cm) 입력 : ");
	scanf_s("%lf %lf", &weight, &height);

	double BMI = weight/(height*height/10000.);

	printf("%s", BMI >= 20.0 && BMI < 25.0 ? "표준 입니다." : "체중관리가 필요합니다.");

	return 0;
}