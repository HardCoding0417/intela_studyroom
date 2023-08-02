//#include <stdio.h>
//
//
//
//void local();
//
//
//int var;
//
//int main(){
//	printf("전역변수 var의 초기값은?: %d\n", var);
//
//	int i = 5;
//	int var = 10;
//
//	printf("main 함수 내에서의 지역변수 var의 값: %d\n", var);
//
//	if(i < 10){
//		local();
//
//		int var = 30;
//
//		printf("if문 내에서의 지역변수 var의 값: %d\n", var);
//	}
//
//	printf("현재 지역변수 var의 값: %d\n", var);
//
//	return 0;
//}
//
//
//void local(){
//	int var = 20;
//
//	printf("local 함수 내에서의 지역변수 var의 값: %d\n", var);
//}




//#include <stdio.h>
//
//
//
//void local();
//void staticVar();
//
//
//int var;
//var = 3;
//
//int main(){
//	printf("%d\n", var);
//
//	for(int i = 0; i < 3; ++i){
//		local();
//		staticVar();
//	}
//
//	return 0;
//}
//
//
//void local(){
//	int cnt = 1;
//
//	printf("local 함수가 %d번째 호출되었습니다.\n", cnt);
//
//	++cnt;
//}
//
//void staticVar(){
//	static int static_cnt = 1;
//
//	printf("staticVar 함수가 %d번째 호출되었습니다.\n", static_cnt);
//
//	++static_cnt;
//}




//#include <stdio.h>
//
//
//int main(){
//	int arr[5];
//
//	int arr_size = sizeof(arr);
//	int arr_len = arr_size / sizeof(arr[0]);
//
//	printf("%d %d\n", arr_size, arr_len);
//}



//
//#include <stdio.h>
//
//#define STUDENT_CNT 5
//
//
//int main(){
//	int arr[STUDENT_CNT];
//	int sum = 0;
//	double avg;
//
//	for(int i = 0; i < STUDENT_CNT; ++i){
//		printf("%d번째 학생의 성적은?: ", i + 1);
//		scanf("%d", arr + i);
//		sum += arr[i];
//	}
//
//	avg = sum / 5.;
//
//	printf("\n%d명 학생 성적의 평균은 %.2lf입니다.\n\n", STUDENT_CNT, avg);
//
//	for(int i = 0; i < STUDENT_CNT; ++i){
//		printf("%d번째 학생: ", i + 1);
//		if(arr[i] > avg){
//			printf("GOAT\n");
//		}
//		else{
//			printf("JOAT\n");
//		}
//	}
//
//	return 0;
//}




//#include <stdio.h>
//
//
//int main(){
//	int data[] = {78, 34, 55, 15, 63, 15, 77};
//	int data_len = sizeof(data) / sizeof(data[0]);
//
//	for(int i = 0; i < data_len; ++i){
//		printf("%d ", data[i]);
//	}
//	printf("\n\n");
//
//	
//	int key;
//	int is_found = 0;
//
//	printf("Enter a key value: ");
//	scanf("%d", &key);
//
//	putchar('\n');
//	for(int i = 0; i < data_len; ++i){
//		if(data[i] == key){
//			printf("index: %d\n", i);
//			is_found = 1;
//		}
//	}
//
//	if(!is_found){
//		printf("not found\n");
//	}
//
//	return 0;
//}




//#include <stdio.h>
//
//
//int main(){
//	int num;
//
//	printf("Enter an unsigned decimal number: ");
//	scanf("%d", &num);
//
//	signed char binary_arr[32] = {0};
//	int arr_idx = 0;
//
//	while(num){
//		binary_arr[arr_idx++] = num & 0x01;
//		num >>= 1;
//	}
//
//	for(int i = arr_idx - 1; i >= 0; --i){
//		printf("%hhd", binary_arr[i]);
//	}
//	putchar('\n');
//
//	return 0;
//}
//



//#include <stdio.h>
//
//
//#define MAX 10
//
//
//
//void print_intArray(int[], int);
//
//
//int main(){
//	int score[] = {99, 98, 97, 96, 95, 55};
//	int score_size = sizeof(score) / sizeof(score[0]);
//
//	print_intArray(score, score_size);
//
//	return 0;
//}
//
//
//void print_intArray(int arr[], int size){
//	for(int i = 0; i < size; ++i){
//		printf("%d ", arr[i]);
//	}
//	putchar('\n');
//}




//#include <stdio.h>
//
//
//
//void print_2dIntArr(int *, int, int);
//
//
//int main(){
//	int arr[][3] = {
//		{1, 2, 3},
//		{4, 5, 6},
//		{7, 8}
//	};
//
//	print_2dIntArr((int *)arr, sizeof(arr) / sizeof(arr[0]),
//				   sizeof(arr[0]) / sizeof(arr[0][0]));
//
//	return 0;
//}
//
//
//void print_2dIntArr(int *arr, int arr_len, int arr_elementLen){
//	for(int i = 0; i < arr_len; ++i){
//		for(int j = 0; j < arr_elementLen; ++j){
//			printf("%d ", *(arr + i*arr_elementLen + j));
//		}
//		putchar('\n');
//	}
//}




//#include <stdio.h>
//
//
//
//int main(){
//	int a = 1, b;
//	const int *ptr1; // const for int
//	int *const ptr2 = &b; // const for pointer
//	const int *const ptr3 = &a; // const for both int and pointer
//
//	
//	ptr1 = &b;
//	ptr1 = &a;
//
//	*ptr2 = 2;
//
//
//	printf("%d\n", *ptr1);
//	printf("%d\n", *ptr2);
//	printf("%d\n", *ptr3);
//
//
//	return 0;
//}




//#include <stdio.h>
//
//
//int main(){
//	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int *int_ptr = arr;
//	int sum = 0;
//
//	while(int_ptr - arr <= 9){
//		sum += *int_ptr++;
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//}




//#include <stdio.h>
//
//
//int main(){
//	int ap = 2147483647;
//	int *pap = &ap;
//	int **ppap = &pap;
//
//	printf("%p %p\n", ppap, &pap);
//	printf("%p %p %p\n", *ppap, pap, &ap);
//	printf("%d %d %d\n", **ppap, *pap, ap);
//
//	return 0;
//}




//#include <stdio.h>
//
//
//int main(){
//	int arr[2][3];
//
//	printf("arr[0]: %p\n", arr[0]);
//	printf("&arr[0][0]: %p\n", &arr[0][0]);
//	printf("arr[1]: %p\n", arr[1]);
//	printf("&arr[1][0]: %p\n\n", &arr[1][0]);
//
//	printf("arr: %p\n", arr);
//	printf("arr + 1: %p\n", arr + 1);
//
//	*(*(arr + 1) + 2) = 3;
//	printf("%d\n", arr[1][2]);
//
//
//	int (*int_double_ptr)[3] = arr;
//
//	printf("%d\n", int_double_ptr[1][2]);
//
//
//	return 0;
//}




//#include <stdio.h>
//
//
//int main(){
//	int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
//
//	printf("%zd\n", sizeof arr);
//	printf("%zd\n", sizeof arr[0] / sizeof arr[0][0]);
//	printf("%zd\n", sizeof arr / sizeof arr[0]);
//
//	return 0;
//}




#include <stdio.h>


//int main(){
//	int *arr[3];
//	int a = 1, b = 2, c = 3;
//
//	arr[0] = &a;
//	arr[1] = &b;
//	arr[2] = &c;
//
//	printf("%d %d\n", a, *arr[0]);
//	printf("%d %d\n", b, *arr[1]);
//	printf("%d %d\n", c, *arr[2]);
//
//	printf("\n%p %p\n", &a, arr[0]);
//
//	return 0;
//}



//
//#include <stdio.h>
//
//
//int main(){
//	int arr1[3] = {1, 2, 3};
//	int arr2[4] = {11, 12, 13, 14};
//	int arr3[5] = {21, 22, 23, 24, 25};
//	int *intPtr_arr[3] = {arr1, arr2, arr3};
//
//	printf("%d\n", intPtr_arr[2][4]);
//
//	return 0;
//}




//#include <stdio.h>
//
//
//int main(){
//	int arr[3] = {1, 2, 3};
//	int *p = arr;
//
//	for(int i = 0; i < 3; ++i){
//		printf("%p %d\n", p, (*p)++); // vs. *p++
//	}
//
//	return 0;
//}



//
//#include <stdio.h>
//
//
//
//struct Human{
//	int age;
//	int height;
//	int weight;
//};
//
//
//int main(){
//	struct Human myself = {20, 174, 56};
//
//	printf("%zd\n", sizeof myself);
//	printf("%d %d %d\n", myself.age, myself.height, myself.weight);
//
//	return 0;
//}




#include <stdio.h>


int main(){
	char *s0 = "apple";
	char *s1 = "apple";
	char s2[6] = "apple";

	printf("%p\n%p\n%p\n", s0, s1, s2);

	return 0;
}
