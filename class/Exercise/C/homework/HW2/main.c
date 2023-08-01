#include <stdio.h>

#include <stdlib.h>
#include <time.h>


#define MAX_ENTITY_NAME_LEN 47
#define MAX_FOOD_NAME_LEN 22
#define MAX_ADV_NAME_LEN 35

#define MAX_INPUT_LEN 3


#define NAME_CNT 9
#define FOOD_CNT 9
#define FOODCNT_CNT 24
#define ADV_CNT 9

#define FEED_CNT_FOR_ADV_CNT 3
#define ADV_LIMIT 3

#define INIT_WEIGHT 0.1





inline char read_cCmd();
inline int read_dCmd();


void print_mola(int);
void print_deadMola(int);


char display_startScreen();
char display_mainScreen(char *, int, int, double, double, char *, int, int, int);
void display_deathScreen(int, int);

int display_advScreen(char (*)[MAX_ADV_NAME_LEN + 1], double *, double, int, int);

char display_shopMenu();
int display_shopScreen_food(char (*)[MAX_FOOD_NAME_LEN + 1], int *, int, int);
int display_shopScreen_foodCnt(int *, int, int);
int display_shopScreen_adv(char (*)[MAX_ADV_NAME_LEN + 1], int *, int, int);




int main(){
	srand((unsigned int)time(NULL));



	char name[NAME_CNT][MAX_ENTITY_NAME_LEN + 1] = {
		"별사탕",
		"아기",
		"어린이",
		"젊은이",
		"사회의 일원",
		"개복치왕",
		"수족관 주인",
		"(모두로부터의 축복) 살아있는 전설",
		"(자유와 희망) 떠돌이물고기"
	};
	int name_idx = 0;
	int max_name_idx = 0;
	int firstEvo_mp[NAME_CNT] = {0, 40, 70, 230, 600, 1950, 3340, 5000, 5000};
	int evo_mp[NAME_CNT] = {0, 20, 60, 90, 140, 360, 680, 1000, 1000};
	int death_mp[NAME_CNT] = {30, 120, 240, 560, 900, 1950, 3340, 5000, 5000};
	double weight_limit[NAME_CNT] = {1.9, 19.9, 89.9, 319.9, 999.9,
									2499.9, 4999.9, 10000., 999999999.};
	double weight = INIT_WEIGHT;

	char food[FOOD_CNT][MAX_FOOD_NAME_LEN + 1] = {
		"동물성 플랑크톤",
		"해파리",
		"오징어",
		"새우",
		"정어리",
		"게",
		"가리비",
		"굴",
		"닭새우"
	};
	int food_mpCost[FOOD_CNT] = {0, 110, 220, 600, 1200, 3200, 6500, 11000, 23000};
	int food_idx = 0;
	double food_weight[FOOD_CNT] = {.1, .2, .4, .7, 1., 1.4, 2.5, 4., 5.5};
	int food_death_ratio[FOOD_CNT] = {0, 80, 80, 80, 80, 80, 80, 80, 80};

	char adv[ADV_CNT][MAX_ADV_NAME_LEN + 1] = {
		"몸이 가려워",
		"해저에는 진수성찬이",
		"바위의 그림자에는 보물이",
		"햇볕 쬐기",
		"바다거북아, 안녕",
		"물고기 천국",
		"새들은 친구들",
		"동료를 구해라!",
		"빛의 방향으로"
	};
	int adv_mpReward[ADV_CNT] = {30, 30, 40, 40, 50, 60, 110, 220, 300};
	int adv_mpCost[ADV_CNT] = {0, 100, 260, 800, 1600, 4200, 8300, 15000, 24000};
	int adv_idx = 1;
	double adv_weight[ADV_CNT] = {2.6, 3.9, 4.9, 11.8, 21.5, 33.7, 49.9, 87.4, 120.};
	int adv_death_ratio[ADV_CNT] = {500, 500, 500, 500, 500, 500, 500, 500, 500};


	int food_cnt = 7;
	int foodCnt_mpCost[FOODCNT_CNT] = {
		0,		24,		64,
		96,		128,	192,
		400,	600,	800,
		1200,	2080,	3120,
		4000,	6000,	8000,
		10000,	12000,	14000,
		16000,	18000,	20000,
		22000,	24000,	26000
	};
	int feed_cnt = 0;
	int adv_cnt = 0;
	int mp = 0;

	int death_set = 0x00000;
	int death_setCnt = 0;
	int gen = 1;
	const double weight_bonus_inc = 0.202941176470588;
	double weight_w = 1.;

	int is_dead = 0;




	char c_cmd = display_startScreen();
	int d_cmd = 0;

	if(c_cmd == 'q'){
		return 0;
	}

	while(1){
		system("cls");
		c_cmd = display_mainScreen(name[name_idx], name_idx, gen, weight,
								   weight_limit[name_idx], food[food_idx], food_cnt,
								   adv_cnt, mp);

		if(c_cmd == '1'){
			for(int cur_food_cnt = 0; cur_food_cnt < food_cnt; ++cur_food_cnt){
				if(rand()%1000 < food_death_ratio[food_idx]){
					is_dead = cur_food_cnt + 1;
					break;
				}
			}

			if(is_dead){
				if(!(death_set & 1 << (food_idx - 1))){
					death_set |= 1 << (food_idx - 1);
					++death_setCnt;

					food_death_ratio[food_idx] = 1;
					weight_w = 1. + weight_bonus_inc*death_setCnt;
				}


				system("cls");
				display_deathScreen(name_idx, death_mp[name_idx]);


				mp += death_mp[name_idx];
				name_idx = 0;
				++gen;

				weight = INIT_WEIGHT;
				feed_cnt = 0;
				adv_cnt = 0;

				is_dead = 0;
			}
			else{
				weight += food_weight[food_idx]*food_cnt*weight_w;
				while(weight >= weight_limit[name_idx]){
					++name_idx;
					if(name_idx > max_name_idx){
						++max_name_idx;
						mp += firstEvo_mp[name_idx];
					}else{
						mp += evo_mp[name_idx];
					}
				}

				++feed_cnt;
				if(feed_cnt == FEED_CNT_FOR_ADV_CNT){
					adv_cnt += adv_cnt == ADV_LIMIT ? 0 : 1;
					feed_cnt = 0;
				}
			}
		}
		else if(c_cmd == '2'){
			system("cls");
			d_cmd = display_advScreen(adv, adv_weight, weight_w, adv_idx, adv_cnt);

			if(d_cmd <= 0 || d_cmd > adv_idx || adv_cnt == 0){
				continue;
			}

			if(rand()%1000 < adv_death_ratio[--d_cmd]){
				if(!(death_set & 1 << (d_cmd + 8))){
					death_set |= 1 << (d_cmd + 8);
					++death_setCnt;

					weight_w = 1. + weight_bonus_inc*death_setCnt;
				}

				if(adv_death_ratio[d_cmd] == 500){
					adv_death_ratio[d_cmd] = 250;
				}
				else if(adv_death_ratio[d_cmd] == 250){
					adv_death_ratio[d_cmd] = 50;
				}
				else if(adv_death_ratio[d_cmd] == 50){
					adv_death_ratio[d_cmd] = 10;
				}


				system("cls");
				display_deathScreen(name_idx, death_mp[name_idx]);


				mp += death_mp[name_idx];
				name_idx = 0;
				++gen;

				weight = INIT_WEIGHT;
				feed_cnt = 0;
				adv_cnt = 0;

				is_dead = 0;
			}else{
				weight += adv_weight[d_cmd]*weight_w;
				if(weight >= weight_limit[name_idx]){
					++name_idx;
					if(name_idx > max_name_idx){
						++max_name_idx;
						mp += firstEvo_mp[name_idx];
					}
					else{
						mp += evo_mp[name_idx];
					}
				}

				mp += adv_mpReward[d_cmd];

				--adv_cnt;
			}
		}
		else if(c_cmd == '3'){
			while(c_cmd != 'q'){
				system("cls");
				c_cmd = display_shopMenu();

				d_cmd = -1;
				if(c_cmd == 'a'){
					while(d_cmd != 0){
						system("cls");

						d_cmd = display_shopScreen_food(food, food_mpCost, food_idx, mp);

						if(d_cmd == 0){
							c_cmd = 'q';
							break;
						}

						if(d_cmd == food_idx + 2 && mp >= food_mpCost[d_cmd - 1]){
							++food_idx;
							mp -= food_mpCost[food_idx];
						}
					}
				}
				else if(c_cmd == 'b'){
					while(d_cmd != 0){
						system("cls");
						d_cmd = display_shopScreen_foodCnt(foodCnt_mpCost, food_cnt, mp);

						if(d_cmd == 0){
							c_cmd = 'q';
							break;
						}
						
						if(d_cmd - 1 == food_cnt){
							int mp_cost = foodCnt_mpCost[d_cmd - 7];

							if(mp >= mp_cost){
								++food_cnt;
								mp -= mp_cost;
							}
						}
					}
				}
				else if(c_cmd == 'c'){
					while(d_cmd != 0){
						system("cls");
						d_cmd = display_shopScreen_adv(adv, adv_mpCost, adv_idx, mp);

						if(d_cmd == 0){
							c_cmd = 'q';
							break;
						}

						if(d_cmd == adv_idx + 1 && mp >= adv_mpCost[adv_idx]){
							++adv_idx;
							mp -= adv_mpCost[adv_idx - 1];
						}
					}
				}
			}
		}
		else if(c_cmd == '4'){
			system("cls");
			c_cmd = display_startScreen();

			if(c_cmd == 'q'){
				break;
			}
		}
	}



	return 0;
}




inline char read_cCmd(){
	printf("  ");

	static char c_cmd[MAX_INPUT_LEN + 1];
	fgets(c_cmd, sizeof(c_cmd), stdin);

	return c_cmd[0];
}
inline int read_dCmd(){
	printf("  ");

	static char c_cmd[MAX_INPUT_LEN + 1];
	fgets(c_cmd, sizeof(c_cmd), stdin);

	return atoi(c_cmd);
}



char display_startScreen(){
	printf("\n\n         살  아  남  아  라  !\n");
	printf("\n\n\
                       /|\n\
                      / |\n\
                     /  |\n\
          _________--   |___\n\
         /                  \\\n\
       _|   o                }\n\
      | |                    }\n\
      |_|   개    복    치   }\n\
        |                    }\n\
         \\___________   ____/\n\
                     \\  |\n\
                      \\ |\n\
                       \\|\n\n");
	printf("   _______________    ______________\n");
	printf("  |               | |              |\n");
	printf("  |  시작(Enter)  | |    종료(q)   |\n");
	printf("  |_______________| |______________|\n\n");

	return read_cCmd();
}

void print_mola(int name_idx){
	putchar('\n');
	if(name_idx == 0){
		printf("\n\n\n\n\n\
              _/w//-^~-_\n\
             |  .       /\n\
             |         _\\\n\
              \\_~v\\_-\\_\\\n\n\n\n\n\n\n");
	}
	if(name_idx == 1){
		printf("\n\n\n\n\
            \\  _-^-~~~-/\n\
             \\/        \\__/\n\
             /  .        d\n\
            |            q\n\
             \\          / \\\n\
              -___ _ __/\n\
              /   v v  \\\n\n\n\n\n");
	}
	if(name_idx == 2){
		printf("\n\
                       /|\n\
                      / |\n\
                     /  |\n\
          _________--   |___\n\
         /                  \\\n\
       _|   o                }\n\
      | |                    }\n\
      |_|                    }\n\
        |                    }\n\
         \\___________   ____/\n\
                     \\  |\n\
                      \\ |\n\
                       \\|\n\n");
	}
	if(name_idx == 3){
		printf("\n\
                       /|\n\
                      / |\n\
                     /  |\n\
          _______----   |___\n\
       _ /       __      -- \\\n\
      \\ |   O   |//\\       ` }\n\
       )|       l _/         }\n\
      /_|                    }\n\
        |                    }\n\
         \\___________    ___/\n\
                     \\  ]\n\
                      \\ ]\n\
                       \\|\n\n");
	}
	if(name_idx == 4){
		printf("\
                         __     \n\
                     _---  |     ___\n\
                   _/     /   _--   >\n\
         ____----==__    |___/     /   \n\
       --      ___            \\  _/\\ \n\
   _  /  _    / l|-_           \\   / \n\
  / \\/  |_|  |  /// |           | /\\ \n\
  \\ |        l   __/            |   )\n\
  / |                           |  /\n\
  \\_/\\                     /   /  \\` \n\
      \\                       |    \\ \n\
       ---___     ____     __/\\_    )  \n\
             ==---  \\_      /   -__|      \n\
                      -=_  (          \n\
                         \\_|\n");
	}
	if(name_idx == 5){
		printf("\
       _/  ___           __     \n\
      __\\/    \\      _---  |     ___\n\
     /   \\     \\   _/     /   _--   >\n\
     \\   \\___----==__    |___/     /   \n\
      \\_/      ___            \\  _/\\ \n\
   _  / /_    / l|-_           \\   / \n\
  / \\/  |_|  |  /// |           | /\\ \n\
  \\ |        l   __/            |   )\n\
  / |   \\                       |  /\n\
  \\_/\\   |                 /   /  \\` \n\
      \\   \\                   |    \\ \n\
       ---___     ____     __/\\_    )  \n\
             ==---  \\_      /   -__|      \n\
                      -=_  (          \n\
                         \\_|\n");
	}
	if(name_idx == 6){
		printf("\
                         __     \n\
                     _---  |     ___\n\
                   _/     /   _--   >\n\
         ____----==__    |___/     /   \n\
       --      ___       ___  \\  _/\\ \n\
   _  /  _    / l|-_        `. \\   / \n\
  / \\/  |_|  |  /// |           | /\\ \n\
  \\ |    =   l   __/            |   )\n\
  / |    \\                      |  /\n\
  \\_/\\   ||                /   /  \\` \n\
      \\   \\\\            --=   |    \\ \n\
       ---_\\\\     ____     __/\\_    )  \n\
            \\\\=---  \\_      /   -__|      \n\
              \\       -=_  (          \n\
                         \\_|\n");
	}
	if(name_idx == 7){
		printf("\
                         __  \n\
           \\         _---  |     ___   \n\
                   _/     /   _--   >     \n\
   \\     ____----==__    |___/     /   \n\
       --        ^_      ___  \\  _/\\   /\n\
   _  /  _      / l|-_      `. \\   / \n\
  / \\/  == _  |  /// _>         | /\\ \n\
  \\ |    _/  _l   __/           |   )     --\n\
  / |    \\                _/_   |  /\n\
  \\_/\\  \\||\\             _/_   /  \\`  \\\n\
      \\  |\\\\            /     |    \\ \n\
       ---|\\\\     ____     __/\\_    )  \n\
   /      \\ \\\\=---  \\_      /   -__|  \\  \n\
        /  -_ \\ \\     -=_  (          \n\
                \\_       \\_|    \\\n");
	}
	if(name_idx == 8){
		printf("\n\n\n\
                _____\n\
               -     -\n\
              /       \\      \n\
              \\       /   \n\
                   __/  \n\
                  |\n\
                  |\n\
  \n\
                  o\n\n\n\n");
	}
}
void print_deadMola(int name_idx){
	if(name_idx == 0){
		printf("\n\n\n\n\n\n\
              _/w//-^~-_\n\
             |  ,       /\n\
             |         _\\\n\
              \\_~v\\_-\\_\\\n\n\n\n\n\n\n");
	}
	if(name_idx == 1){
		printf("\n\n\n\n\n\
            \\  _-^-~~~-/\n\
             \\/        \\__/\n\
             /  x        d\n\
            |            q\n\
             \\          / \\\n\
              -___ _ __/\n\
              /   v v  \\\n\n\n\n\n");
	}
	if(name_idx == 2){
		printf("\n\n\
                       /|\n\
                      / |\n\
                     /  |\n\
          _________--   |___\n\
         /                  \\\n\
       _|   X                }\n\
      | |                    }\n\
      |_|                    }\n\
        |                    }\n\
         \\___________   ____/\n\
                     \\  |\n\
                      \\ |\n\
                       \\|\n\n");
	}
	if(name_idx == 3){
		printf("\n\n\
                       /|\n\
                      / |\n\
                     /  |\n\
          _______----   |___\n\
       _ /       __      -- \\\n\
      \\ |   X   |//\\       ` }\n\
       )|       l _/         }\n\
      /_|                    }\n\
        |                    }\n\
         \\___________    ___/\n\
                     \\  ]\n\
                      \\ ]\n\
                       \\|\n\n");
	}
	if(name_idx == 4){
		printf("\n\n\
                         __     \n\
                     _---  |     ___\n\
                   _/     /   _--   >\n\
         ____----==__    |___/     /   \n\
       --      ___       ___  \\  _/\\ \n\
   _  /       / l|-_        `. \\   / \n\
  / \\/  |||  |  /// |           | /\\ \n\
  \\ |    -   l   __/            |   )\n\
  / |                           |  /\n\
  \\_/\\                     /   /  \\` \n\
      \\                       |    \\ \n\
       ---___     ____     __/\\_    )  \n\
             ==---  \\_      /   -__|      \n\
                      -=_  (          \n\
                         \\_|\n");
	}
	if(name_idx == 5){
		printf("\n\n\
       _/  ___           __     \n\
      __\\/    \\      _---  |     ___\n\
     /   \\     \\   _/     /   _--   >\n\
     \\   \\___----==__    |___/     /   \n\
      \\_/      ___       ___  \\  _/\\ \n\
   _  / /     / l|-_        `. \\   / \n\
  / \\/   $   |  /// |           | /\\ \n\
  \\ |    -   l   __/            |   )\n\
  / |   \\                       |  /\n\
  \\_/\\   |                 /   /  \\` \n\
      \\   \\                   |    \\ \n\
       ---___     ____     __/\\_    )  \n\
             ==---  \\_      /   -__|      \n\
                      -=_  (          \n\
                         \\_|\n");
	}
	if(name_idx == 6){
		printf("\n\n\
                         __     \n\
                     _---  |     ___\n\
                   _/     /   _--   >\n\
         ____----==__    |___/     /   \n\
       --      ___       ___  \\  _/\\ \n\
   _  /  =    / l|-_        `. \\   / \n\
  / \\/  |@|  |  /// |           | /\\ \n\
  \\ |    =   l   __/            |   )\n\
  / |    \\                      |  /\n\
  \\_/\\   ||                /   /  \\` \n\
      \\   \\\\            --=   |    \\ \n\
       ---_\\\\     ____     __/\\_    )  \n\
            \\\\=---  \\_      /   -__|      \n\
              \\       -=_  (          \n\
                         \\_|\n");
	}
	if(name_idx == 7){
		printf("\n\n\
                         __  \n\
           \\         _---  |     ___   \n\
                   _/     /   _--   >     \n\
   \\     ____----==__    |___/     /   \n\
       --        ^_      ___  \\  _/\\   /\n\
   _  /  _      / l|-_      `. \\   / \n\
  / \\/   . _  |  /// _>         | /\\ \n\
  \\ |    _/  _l   __/           |   )     --\n\
  / |    \\                _/_   |  /\n\
  \\_/\\  \\||\\             _/_   /  \\`  \\\n\
      \\  |\\\\            /     |    \\ \n\
       ---|\\\\     ____     __/\\_    )  \n\
   /      \\ \\\\=---  \\_      /   -__|  \\  \n\
        /  -_ \\ \\     -=_  (          \n\
                \\_       \\_|    \\\n");
	}
	if(name_idx == 8){
		printf("\n\n\n\n\n\
             __       __\n\
             \\ \\     / /\n\
              \\ \\   / / \n\
               \\ \\_/ /  \n\
                \\   /   \n\
                / _ \\   \n\
               / / \\ \\  \n\
              / /   \\ \\ \n\
             /_/     \\_\\\n\n\n\n");
	}
	putchar('\n');
}
char display_mainScreen(char *name, int name_idx, int gen, double weight, double weight_limit, char *food,
	int food_cnt, int adv_cnt, int mp){
	printf("\n  1.먹이    2.모험    3.상점    4.종료\n\n");
	print_mola(name_idx);
	printf("\n\n  명칭: %s (%d대)\n", name, gen);
	printf("  체중: %.1lfkg / %.1lfkg\n\n", weight, weight_limit);
	printf("  먹이: %-15s    먹이 수: %d개\n", food, food_cnt);
	printf("  모험 포인트: %d / %d       MP: %d\n\n", adv_cnt, ADV_LIMIT, mp);

	return read_cCmd();
}
void display_deathScreen(int name_idx, int death_mp){
	printf("\n\n          돌      연      사\n");
	print_deadMola(name_idx);
	printf("  %dMP 획득!!!\n\n\n", death_mp);
	printf("  계속하려면 Enter를 누르세요\n\n");

	read_cCmd();
}

int display_advScreen(char (*adv)[MAX_ADV_NAME_LEN + 1], double *adv_weight,
					  double weight_w, int adv_idx, int adv_cnt){
	printf("\n  모험 포인트: %d / %d\n\n\n", adv_cnt, ADV_LIMIT);
	for(int i = 0; i < adv_idx; ++i){
		printf("  %d. %s (%.1lfkg)\n", i + 1, adv[i], adv_weight[i]*weight_w);
	}
	printf("\n\n  0. 뒤로\n\n");

	return read_dCmd();
}


char display_shopMenu(){
	printf("\n  < 상 점 >\n\n\n");
	printf("  a. 먹이 업그레이드\n");
	printf("  b. 먹이 개수 업그레이드\n");
	printf("  c. 모험 해금\n\n\n");
	printf("  q. 뒤로\n\n");

	return read_cCmd();
}

int display_shopScreen_food(char (*food)[MAX_FOOD_NAME_LEN + 1], int *food_mpCost,
							int food_idx, int mp){
	printf("\n  < 먹이 업그레이드 >\n\n");
	printf("  MP: %d\n\n", mp);
	for(int idx = 0; idx <= food_idx; ++idx){
		printf("  %d. 완료\n", idx + 1);
	}
	for(int idx = food_idx + 1; idx < FOOD_CNT; ++idx){
		printf("  %d. %-6s | %dMP\n", idx + 1, food[idx], food_mpCost[idx]);
	}
	printf("\n\n  0. 뒤로\n\n");

	return read_dCmd();
}
int display_shopScreen_foodCnt(int *foodCnt_mpCost, int food_cnt, int mp){
	printf("\n  < 먹이 개수 업그레이드 >\n\n");
	printf("  MP: %d\n\n\n", mp);
	food_cnt -= 7;
	for(int idx = 0; idx < FOODCNT_CNT; ++idx){
		if(idx <= food_cnt){
			printf("  완료%13s", "");
		}
		else{
			printf("  %2d개 | %5dMP   ", idx + 7, foodCnt_mpCost[idx]);
		}

		if(idx%3 == 2){
			printf("\n\n");
		}
	}
	printf("\n  0. 뒤로\n\n\n");

	return read_dCmd();
}
int display_shopScreen_adv(char (*adv)[MAX_ADV_NAME_LEN + 1], int *adv_mpCost, int adv_idx,
						   int mp){
	printf("\n  < 모험 해금 >\n\n");
	printf("  MP: %d\n\n", mp);
	for(int idx = 0; idx < adv_idx; ++idx){
		printf("  %d. 완료\n", idx + 1);
	}
	for(int idx = adv_idx; idx < ADV_CNT; ++idx){
		printf("  %d. %-24s / %dMP\n", idx + 1, adv[idx], adv_mpCost[idx]);
	}
	printf("\n\n  0. 뒤로\n\n");

	return read_dCmd();
}