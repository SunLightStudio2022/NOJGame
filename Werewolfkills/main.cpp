#include <bits/stdc++.h>
#include <windows.h>
#include "init.hpp"
#include "function.hpp"
#include "end&day.hpp"
using namespace std; 
//Note: This game is based on the Windows operating system, some features may go wrong in Unix
//Note: The committers, modifiers and makers live in China, so we don't have a lot of energy to translate the in-game tips, please understand!
//Produced by wuyuhan01              Modified: jinhongkun       Optimized with the source code more readable: guozhenkai
//At present, the source code correction is still in progress, but the game can run normally, but please wait to read and modify the source code
//Annotations are all machine-flipped

int main() {
	cout<<"-----------狼人杀----------\n\n\n\n\n\n"<<"jinhongkun修改 wuyuhan01制作 guozhenkai优化\n\n\n\n\nTips：三人无关系，只是看到对方的代码然后改了而已，原版wuyuhan01制作\n\n\n\n\n\n\n\n\n";
	system("pause"); 
	system("cls");
	cout<<"\n\n\n\n\n\n\n----------狼人杀----------\n\n\n\n\n\n\n浙大noj第二大学生自创游戏";
	system("pause");
	system("cls"); 
	cout << " " << "狼人杀online" << endl; 
	cout << "请输入人数个数:" << endl; 
	scanf("%d", &n); 
	cout << "加载时间长，请耐心等待"; 
	init1(); 
	init2(n); 
	int k = 1; 
	do { 
		srand(time(0)); 
		init3(k); 
		cout << "."; 
		Sleep(17); 
		k++; 
	} while (k <= n); 
	system("cls"); 
	system("color F0"); 
	cout << "游戏即将开始"; 
	for (int i = 1; i <= 6; i++) { 
		cout << "."; 
		Sleep(500);
	} Sleep(1500); 
	cout << endl << endl << "请大家查看身份牌......" << endl; 
	Sleep(45); 
	srand(time(0)); 
	MY = rand() % n + 1; 
	cout << "您的身份是:" << player[MY].name << endl; 
	Sleep(500); 
	cout << "在" << player[MY].num << "号位上" << endl; 
	system("pause"); 
	system("cls"); 
	player[MY].know = 2; 
	print(1, 0); 
	cout << "即将进入夜晚"; 
	for (int i = 1; i <= 6; i++) { 
		cout << "."; 
		Sleep(500); 
	} 
	night(); 
	print1(); 
	if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} 
	if (player[lieren].life == 0 && lr == 0) { 
		panduanlieren(); 
	} 
	if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} 
	toupiao(2, 0); 
	system("cls"); 
	print(2, 0); 
	if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} else if (player[lieren].life == 0 && lr == 0) { 
		panduanlieren(); 
	} 
	cout << "即将进入夜晚"; 
	for (int i = 1; i <= 6; i++) { 
		cout << "."; 
		Sleep(500); 
	} 
	night2(2, 1); 
	print1(); 
	if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh(); return 0; 
	}
	if (player[lieren].life == 0 && lr == 0) { 
		panduanlieren(); 
	} 
	if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} 
	toupiao(3, 0); 
	system("cls"); 
	print(3, 0); 
	if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh();
		return 0;
	} else if (player[lieren].life == 0 && lr == 0) { 
		panduanlieren(); 
	} 
	cout << "即将进入夜晚"; 
	for (int i = 1; i <= 6; i++) { 
		cout << "."; 
		Sleep(500); 
	} 
	night2(3, 1); 
	print1(); 
	if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} if (player[lieren].life == 0) {
		panduanlieren();
	} if (game_over()) {
		Sleep(1000);
		system("cls");
		cout << "游戏结束" << endl;
		printhhh();
		return 0;
	} 
	toupiao(4, 0);
	system("cls");
	print(4, 0);
	if (game_over()) {
		Sleep(1000);
		system("cls");
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} else if (player[lieren].life == 0 && lr == 0) { 
		panduanlieren(); 
	} if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} 
	cout << "即将进入夜晚"; 
	for (int i = 1; i <= 6; i++) { 
		cout << "."; 
		Sleep(500); 
	} 
	night2(4, 1); 
	print1(); 
	if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} 
	if (player[lieren].life == 0) { 
		panduanlieren(); 
	} 
	if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} 
	toupiao(5, 0); 
	system("cls"); 
	print(5, 0); 
	if (game_over()) { 
		Sleep(1000); 
		system("cls"); 
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0;
	} else if (player[lieren].life == 0 && lr == 0) {
		panduanlieren(); 
	} if (game_over()) { 
		Sleep(1000); 
		system("cls");
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} cout << "即将进入夜晚"; 
	for (int i = 1; i <= 6; i++) { 
		cout << "."; 
		Sleep(500); 
	} 
	night2(5, 1); 
	print1();
	if (game_over()) {
		Sleep(1000); 
		system("cls");
		cout << "游戏结束" << endl;
		printhhh(); return 0;
	}
	if (player[lieren].life == 0) {
		panduanlieren();
	} if (game_over()) {
		Sleep(1000);
		system("cls");
		cout << "游戏结束" << endl;
		printhhh();
		return 0;
	} 
	toupiao(6, 0);
	system("cls");
	print(6, 0);
	if (game_over()) {
		Sleep(1000);
		system("cls");
		cout << "游戏结束" << endl;
		printhhh();
		return 0;
	} else if (player[lieren].life == 0 && lr == 0) {
		panduanlieren();
	} 
	if (game_over()) {
		Sleep(1000);
		system("cls");
		cout << "游戏结束" << endl; 
		printhhh(); return 0;
	} 
	cout << "即将进入夜晚"; 
	for (int i = 1; i <= 6; i++) {
		cout << ".";
		Sleep(500);
	} 
	night2(6, 1);
	print1(); 
	if (game_over()) { 
		Sleep(1000);
		system("cls");
		cout << "游戏结束" << endl; 
		printhhh();
		return 0; 
	} 
	if (player[lieren].life == 0) { 
		panduanlieren();
	} 
	if (game_over()) { 
		Sleep(1000); 
		system("cls");
		cout << "游戏结束" << endl;
		printhhh();
		return 0; 
	} 
	toupiao(7, 0); 
	system("cls");
	print(7, 0); 
	if (game_over()) { 
		Sleep(1000);
		system("cls");
		cout << "游戏结束" << endl; 
		printhhh(); 
		return 0; 
	} else if (player[lieren].life == 0 && lr == 0) { 
		panduanlieren();
	} 
	if (game_over()) { 
		Sleep(1000);
		system("cls");
		cout << "游戏结束" << endl;
		printhhh();
		return 0; 
	} while (1) system("pause");
	return 0; 
}
