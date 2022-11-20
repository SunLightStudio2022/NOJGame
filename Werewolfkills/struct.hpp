//The game struct
#include <bits/stdc++.h>
using namespace std; 
struct IDname { 
	int geshu;
	string NAME; 
} jue_se[100]; 
struct ID { 
	int num; bool life; string name; int know; int how; 
} player[21];
struct tou { 
	int xxx,num,toupiaoquan; 
} TOU[13];
int n, MY, kill1, kill2; 
char a;
bool jieyao = 1, duyao = 1;
int lieren, shouwei = 0;
int van[10] = {7,4,6,43,35,1,2,8,20,19 };
