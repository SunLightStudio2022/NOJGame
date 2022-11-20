//Init gmae.
#include <bits/stdc++.h>
#include "struct.hpp" 
using namespace std; 
void init1() { 
	jue_se[1].NAME = "村民 ";
	jue_se[2].NAME = "狼人 "; 
	jue_se[3].NAME = "女巫 "; 
	jue_se[4].NAME = "预言家 "; 
	jue_se[5].NAME = "猎人 "; 
	jue_se[6].NAME = "守卫 ";
} 
void init2(int nn) { 
	switch (nn) { 
		case 6: 
			jue_se[1].geshu = 3; 
			jue_se[2].geshu = 2; 
			jue_se[3].geshu = 1; 
			jue_se[4].geshu = 0; 
			jue_se[5].geshu = 0; 
			jue_se[6].geshu = 0; 
			break; 
		case 7: jue_se[1].geshu = 3; 
			jue_se[2].geshu = 2; 
			jue_se[3].geshu = 1; 
			jue_se[4].geshu = 1; 
			jue_se[5].geshu = 0; 
			jue_se[6].geshu = 0; 
		break;
		case 8: jue_se[1].geshu = 3; 
			jue_se[2].geshu = 3; 
			jue_se[3].geshu = 1; jue_se[4].geshu = 1;
			jue_se[5].geshu = 0; jue_se[6].geshu = 0;
		break;
		case 9: 
			jue_se[1].geshu = 3; 
			jue_se[2].geshu = 3; 
			jue_se[3].geshu = 1; 
			jue_se[4].geshu = 1; 
			jue_se[5].geshu = 1; 
			jue_se[6].geshu = 0;
		break; 
		case 10: 
			jue_se[1].geshu = 4; 
			jue_se[2].geshu = 3;
			jue_se[3].geshu = 1; 
			jue_se[4].geshu = 1;
			jue_se[5].geshu = 1; 
			jue_se[6].geshu = 0; 
		break; 
		case 11: jue_se[1].geshu = 4; 
			jue_se[2].geshu = 4; 
			jue_se[3].geshu = 1; 
			jue_se[4].geshu = 1; 
			jue_se[5].geshu = 1; 
			jue_se[6].geshu = 0; 
		break;
		case 12: 
			jue_se[1].geshu = 4; 
			jue_se[2].geshu = 4; 
			jue_se[3].geshu = 1; 
			jue_se[4].geshu = 1; 
			jue_se[5].geshu = 1; 
			jue_se[6].geshu = 1;
		break;
		default: 
			cout << "输入错误,再见" << endl; 
			exit(0); 
		break; 
	} 
}
void init3(int nn) { 
	srand(time(0)); 
	Sleep(rand() % 44);
	int x = 10000; 
	int t = rand(); 
	srand(time(NULL));
	int y = van[(rand()%100+van[rand()%10]+t)%10]; 
	if (nn <= 6) x = abs(x * 6 / y) % 3 + 1; 
	else if (nn <= 8) x = abs(x * 7 / y) % 4 + 1; 
	else if (nn <= 11) x = abs(x * 8 / y) % 5 + 1;
	else if (nn <= 14) x = abs(x * 9 / y) % 6 + 1;
	do { 
		if (nn <= 6) x = x % 3 + 1;
		else if (nn <= 8) x = x % 4 + 1; 
		else if (nn <= 11) x = x % 5 + 1;
		else if (nn <= 14) x = x % 6 + 1;
		if (jue_se[x].geshu > 0) { 
			player[nn].name = jue_se[x].NAME;
			if (player[nn].name == "猎人 ") lieren = nn; 
			if (player[nn].name == "守卫 ") shouwei = nn; 
			player[nn].life = 1; player[nn].num = nn; player[nn].know = 0;
			jue_se[x].geshu--; player[nn].how = 0; break;
		} 
	}while (jue_se[x].geshu == 0); 
}
