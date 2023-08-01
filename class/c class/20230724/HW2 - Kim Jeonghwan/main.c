#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <process.h>


int length;

int count = 0;

double weight = 0;

char obj = '@';


struct coordinate
{
	int x;
	int y;
	int direction;
};

typedef  struct coordinate coordinate;

coordinate head, food;
//#include

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gotoxy(int x, int y)
{
	COORD coord = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

COORD c = {0,0};


int gotoxy(int, int);

void display() {

	printf("-----------------------------------------------\n");
	printf("----------------Survive! Mola mola!------------\n");
	printf("-----------------------------------------------\n");

	//scanf("%d")

	printf("1. 먹이----------------------------------------\n");
	printf("2. 모험----------------------------------------\n");
	printf("3. 상점----------------------------------------\n");
	printf("4. 종료----------------------------------------\n");

}


void food_menu() {

	system("cls");

	printf("1.동물성 플랑크톤");
	printf("▒\n");

	printf("2.해파리★\n");

	printf("3.오징어♠\n");

	printf("4.새우♣\n");

	printf("5.정어리⊙\n");

	printf("6.게◎\n");

	printf("7.가리비§\n");

	printf("8.닭새우♤\n");

	printf("9.굴▨\n");

	printf("보유하고있는 MP량: %d\n", count);

	printf("구입할 먹이를 선택:");

	int food_num = 0;

	scanf_s("%d", &food_num);

	switch(food_num)
	{

		case 1:
			if(count >= 110) {

				printf("구입성공!\n");
				weight = weight + 0.2;
				count -= 110;

			}
			else {

				printf("구매불가!\n");
			}
			break;

		case 2:
			if(count >= 220) {

				printf("구입성공!\n");
				weight = weight + 0.4;
				count -= 220;
			}
			else {

				printf("구매불가!\n");
			}
			break;

		case 3:
			if(count >= 600) {

				printf("구입성공!\n");
				weight = weight + 0.7;
				count -= 600;
			}
			else {

				printf("구매불가!\n");
			}
			break;

	}

	//system("cls");


}

void adven_menu() {


}

void setxy(int x, int y)
{
	c.X = x; c.Y = y; // Set X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}


void food_generate() {

	if(head.x == food.x && head.y == food.y)
	{
		length++;
		time_t a;
		a = time(0);
		srand(a);
		food.x = rand() % 70;
		if(food.x <= 10)
			food.x += 11;
		food.y = rand() % 30;
		if(food.y <= 10)

			food.y += 11;
	}
	else if(food.x == 0)/*to create food for the first time coz global variable are initialized with 0*/
	{
		food.x = rand() % 70;
		if(food.x <= 10)
			food.x += 11;
		food.y = rand() % 30;
		if(food.y <= 10)
			food.y += 11;
	}


}

//	setxy(50,50);
//	
//	char food='*';
//	
//	char a[50][50];




//}

void adven_2() {

	system("cls");

	int x = 20, y = 10, ch1, ch2;
	//char obj = '@';
	printf("Press UP, DOWN, RIGHT, LEFT Arrow Key..\n");
	printf("Press X to exit game... \n");
	ch1 = _getch();
	ch2 = 0;

	if(ch1 == 0xE0)
		//When accepting arrow key, function must be called twice; first call returns 0/0xE0; second call returns actual key code
	{
		setxy(x, y);
		while(ch2 != 'X')
		{
			ch2 = _getch();
			switch(ch2)
			{
				case 72: setxy(x, y--);
					printf("%c", obj);
					count += 1;
					break;
				case 80:
					setxy(x, y++);
					printf("%c", obj);
					count += 1;
					break;
				case 75:
					setxy(x--, y);
					printf("%c", obj);
					count += 1;
					break;
				case 77:
					setxy(x++, y);
					printf("%c", obj);
					count += 1;
					break;
				default:
					//system("cls");
					break;
			};
		}
	}
	else
		printf("key pressed: %d %c\n", ch1, ch2);
	system("pause");
	system("cls");



}

void adven() {

	int a, b, c, i;
	char obj;

	a = 5;
	b = 6;

	printf("Enter the object : ");
	scanf_s("%c", &obj);

	system("cls");
	gotoxy(a, b);
	printf("%c", obj);

	while(1)
	{
		if(_kbhit())
		{
			c = _getch();
			if(c == 77)
				a++;

			if(c == 75)
				a--;

			if(c == 72)
				b--;

			if(c == 80)
				b++;
			//system("cls");             /*Showing just The new movement*/
			gotoxy(a, b);
			printf("%c", obj);

		}
	}

}




//}


void store() {

	int num2 = 0;

	system("cls");

	printf("진화 상점\n");

	printf("1.별사탕\n");
	printf("2.아기\n");
	printf("3.어린이\n");
	printf("4.젊은이\n");
	printf("5.사회의 일원\n");

	printf("원하는 진화를 선택:");


	scanf_s("%d", &num2);

	switch(num2)
	{
		case 1:
			if(weight >= 0 && weight <= 1.9) {

				printf("진화 시작!\n");

				obj = 'C';


			}
			break;

		case 2:
			if(weight >= 2 && weight <= 19.9) {

				printf("진화 시작!\n");

				obj = 'O';
			}

			break;

		case 3:
			if(weight >= 20 && weight <= 89.9) {

				printf("진화 시작!\n");

				obj = '#';
			}

			break;

		case 4:
			if(weight >= 90 && weight <= 319.9) {

				printf("진화 시작!\n");

				obj = '&';
			}

			break;

		case 5:

			if(weight >= 320 && weight <= 999.9) {

				printf("진화 시작!\n");

				obj = '💂 ';
			}
			break;


		default:
			break;
	}



}

void foodo() {

	//	if(head.x==food.x&&head.y==food.y)
	//    {
	//        length++;
	//        time_t a;
	//        a=time(0);
	//        srand(a);
	//        food.x=rand()%70;
	//        if(food.x<=10)
	//            food.x+=11;
	//        food.y=rand()%30;
	//        if(food.y<=10)
	//
	//            food.y+=11;
	//    }
	//    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
	//    {
	//        food.x=rand()%70;
	//        if(food.x<=10)
	//            food.x+=11;
	//        food.y=rand()%30;
	//        if(food.y<=10)
	//            food.y+=11;
	//    }

}

void end() {

	return 0;
}



int main() {

	head.x = 20;
	head.y = 10;

	//display();
	//printf("\n");

	//printf("입력:");



	int menu_num = 0;


	//scanf_s("%d", &menu_num);

	do {

		system("cls");

		display();

		printf("\n");

		printf("입력:");



		//int menu_num = 0;


		scanf_s("%d", &menu_num);



		switch(menu_num) {

			case 1:food_menu();//food();
				break;

			case 2:food_generate();
				adven_2();
				//adven_menu();
				//move()
				break;

			case 3:store();

				break;

			case 4:end();
				break;
		}

	} while(menu_num != 4);


}