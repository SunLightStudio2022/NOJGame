//Game function
//游戏函数
#include"doing.hpp"
int shou = 0;
void printhhh() { 
	int cm=0,sz=0;
	for (int i = 1; i <= n; i++) {
		if (player[i].life == 0) continue;
		else if (player[i].name == "村民 ") cm++;
		else if (player[i].name == "女巫 " || player[i].name == "预言家 " || player[i].name == "猎人 " || player[i].name == "守卫 ") sz++; 
	} 
	if (sz == 0 || cm == 0) cout << "狼人阵营胜利" << endl; 
	else cout << "好人阵营胜利" << endl; 
	for (int i = 1; i <= n; i++) { 
		cout << left << setw(3) << player[i].num << ": " << player[i].name << " "; 
		if (player[i].life == 0) cout << "死亡" << "\t"; 
		else cout << "存活" << "\t"; 
		if (player[i].how == 0) cout << "最终存活 " << endl;
		else if (player[i].how == 1) cout << "最终被狼人杀死" << endl;
		else if (player[i].how == 2) cout << "最终被投票投死" << endl; 
		else if (player[i].how == 3) cout << "最终被女巫毒死" << endl;
		else if (player[i].how == 4) cout << "最终被猎人射杀" << endl;
	} 
	system("pause");
	system("pause"); 
	system("pause"); 
} 
void print(int day, int ti) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
	cout << "\t\t\t\t第" << day << "天 "; 
	if (ti == 0) cout << "白天" << endl;
	else cout << "夜晚" << endl; 
	cout << "我的位置:" << MY << "号" << endl;
	for (int i = 1; i <= 6; i++) {
		cout << player[i].num << "号位 ";
	} 
	cout << endl;
	for (int i = 1; i <= 6; i++) {
		if (player[i].life == 1) {
			if (ti == 0) SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN); 
			else SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN); 
			cout << "存活 ";
		} else { 
			if (ti == 0) SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED);
			else SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED); 
			cout << "已死亡 "; 
		}
	} 
	if (ti == 0) SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
	else SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << endl;
	for (int i = 1; i <= 6; i++) { 
		if (player[i].know == 0) cout << "未知 ";
		else if (player[i].know == 1) {
			if (player[i].name == "狼人 ") cout << "狼人 "; 
			else cout << "好人 "; 
		}else if (player[i].know == 2) cout << player[i].name << " ";
	} cout << endl << endl; 
	for (int i = 7; i <= n; i++) {
		if (i < 10) cout << player[i].num << "号位 "; 
		else cout << player[i].num << "号位 "; 
	} 
	cout << endl; 
	for (int i = 7; i <= n; i++) {
		if (player[i].life == 1) {
			if (ti == 0) SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN); 
			else SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "存活 "; 
		} else {
			if (ti == 0) SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED);else SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << "已死亡 "; 
		} 
	} 
	if (ti == 0) SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
	else SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << endl; for (int i = 7; i <= n; i++) { 
	if (player[i].know == 0) cout << "未知 "; 
	else if (player[i].know == 1) { 
		if (player[i].name == "狼人 ") cout << "狼人 "; 
		else cout << "好人 "; 
	} else if (player[i].know == 2) cout << player[i].name << " "; } cout << endl << endl;
}
void shoushui(int hhh, int hhhh) {
	int x;
	Sleep(3000);
	system("cls"); 
	print(hhh, hhhh); 
	cout << "守~卫~请~睁~眼~" << endl;
	Sleep(3000); 
	system("cls"); 
	print(hhh, hhhh); 
	if (MY == shouwei && player[MY].life == 1) {
		cout << "请问你要守护谁?" << endl << "输入:";
		cin >> x; 
		while (x == shou || x<1 || x>n || player[x].life == 0) { 
			cout << "输入错误,请重新输入" << endl << "输入:"; 
			cin >> x; 
		} 
		shou = x;
	} else if (player[shouwei].life == 1) {
		cout << "请问你要守护谁?" << endl; Sleep(rand() % 98);
		srand(time(0)); 
		x = rand() % n + 1; 
		while (x == shou || player[x].life == 0) { 
			Sleep(rand() % 98);
			srand(time(0)); 
			x = rand() % n + 1; 
		} 
	shou = x; 
	} else { 
		cout << "请问你要守护谁?" << endl;
		Sleep(3000); shou = -1; 
	}
	Sleep(3000);
	system("cls");
	print(hhh, hhhh);
	cout << "守~卫~请~闭~眼~" << endl; 
}
void toupiao(int ddd, int nnn) {
	int x; 
	Sleep(2000);
	system("cls");
	print(ddd, nnn); 
	cout << "现在大家请投票"; 
	for (int i = 1; i <= 3; i++) { 
		cout << "."; 
		Sleep(500); 
	}
	cout << endl; 
	for (int i = 1; i <= n; i++) { 
		TOU[i].num = i;
 		TOU[i].toupiaoquan = 1; 
 		TOU[i].xxx = 0; 
 	} for (int i = 1; i <= n; i++) { 
 		if (player[i].life == 1) { 
			Sleep(3000); 
			if (i == MY) { 
			 	cout << "请投票...(0弃权)" << endl; 
			 	cin >> x; 
			 	while (player[x].life == 0 && x != 0) { 
			 		cin >> x; 
			 	}
				if (x == 0) cout << MY << "号玩家弃权" << endl; 
			 	else cout << MY << "号玩家投给了" << x << "号玩家" << endl; 
			} else { 
			 	srand(time(0));
				if (player[i].name == "狼人 ") {
				 	x = rand() % (n + 1);
					while (x != 0 && (player[x].life == 0 || player[x].name == "狼人 " || x == i)) {
						Sleep(rand() % 98);
						srand(time(0));
						x = rand() % (n + 1);
					}
					if (x == 0) cout << i << "号玩家弃权" << endl;
					else cout << i << "号玩家投给了" << x << "号玩家" << endl;
				} else if (player[i].name == "预言家 ") {
					x = rand() % (n + 1);
					while (x != 0 && (player[x].life == 0 || player[x].name != "狼人 " || x == i)) {
						Sleep(rand() % 98);
						srand(time(0));
						x = rand() % (n + 1);
					}
					if (x == 0) cout << i << "号玩家弃权" << endl;
					else cout << i << "号玩家投给了" << x << "号玩家" << endl;
				} else {
					x = rand() % (n + 1);
					while (x != 0 && (player[x].life == 0 || x == i)) {
						Sleep(rand() % 98);
						srand(time(0));
						x = rand() % (n + 1);
					}
					if (x == 0) cout << i << "号玩家弃权" << endl;
					else cout << i << "号玩家投给了" << x << "号玩家" << endl;
				}
			} if (x != 0) TOU[x].xxx++;
		}
	}
	Sleep(3000);
	sort(TOU + 1, TOU + n + 1, cmp);
	if (TOU[2].xxx != TOU[1].xxx){ 
		cout << "投票结束," << TOU[1].num << "号投票出局" << endl;
		player[TOU[1].num].life = 0;
		player[TOU[1].num].how = 2;
		Sleep(3000); return;
	} else {
		TOU[1].toupiaoquan = 0;
		TOU[2].toupiaoquan = 0;
		system("cls"); print(ddd, nnn);
		cout << TOU[1].num << "号," << TOU[2].num << "号";
		int i;
		for (i = 3; i <= n; i++) {
			if (TOU[i].xxx == TOU[1].xxx) {
				TOU[i].toupiaoquan = 0;
				cout << "," << TOU[i].num << "号";
			} else break;
		} if (i == n + 1) {
			for (int i = 1; i <= n; i++) TOU[i].toupiaoquan = 1; 
		}cout << "平票" << endl;
	}
	sort(TOU + 1, TOU + n + 1, cmp1);
	cout << "请再次投票";
	for (int i = 1; i <= 3; i++) {
		cout << "."; Sleep(500);
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		if (player[i].life == 1 && TOU[i].toupiaoquan == 1) {
			Sleep(3000);
			if (i == MY) {
				cout << "请投票...(0弃权)" << endl;
				cin >> x;
				while ((player[x].life == 0 || TOU[x].toupiaoquan == 1) && x != 0) {
					cin >> x;
				}
				if (x == 0) cout << MY << "号玩家弃权" << endl;
				else cout << MY << "号玩家投给了" << x << "号玩家" << endl;
			} else {
				srand(time(0));
				if (player[i].name == "狼人 ") {
					x = rand() % (n + 1);
					while (x != 0 && (player[x].life == 0 || player[x].name == "狼人 " || x == i || TOU[x].toupiaoquan == 1)) {
						srand(time(0)); x = rand() % (n + 1);
					}
					if (x == 0) cout << i << "号玩家弃权" << endl;
					else cout << i << "号玩家投给了" << x << "号玩家" << endl;
				} else if (player[i].name == "预言家 ") {
					x = rand() % (n + 1);
					while (x != 0 && (player[x].life == 0 || player[x].name != "狼人 " || x == i || TOU[x].toupiaoquan == 1)) {
						srand(time(0)); x = rand() % (n + 1);
					}
					if (x == 0) cout << i << "号玩家弃权" << endl;
					else cout << i << "号玩家投给了" << x << "号玩家" << endl;
				} else { x = rand() % (n + 1);
					while (x != 0 && (player[x].life == 0 || x == i || TOU[x].toupiaoquan == 1)) {
						srand(time(0)); x = rand() % (n + 1);
					}
					if (x == 0) cout << i << "号玩家弃权" << endl;
					else cout << i << "号玩家投给了" << x << "号玩家" << endl;
				}
			} if (x != 0 && TOU[i].toupiaoquan == 1) TOU[x].xxx++;
		}
	}
	Sleep(3000);
	sort(TOU + 1, TOU + n + 1, cmp);
	if (TOU[2].xxx != TOU[1].xxx) {
		cout << "投票结束," << TOU[1].num << "号投票出局" << endl;
		player[TOU[1].num].life = 0;
		player[TOU[1].num].how = 2;
		Sleep(3000);
		return;
	} else {
		TOU[1].toupiaoquan = 0;
		TOU[2].toupiaoquan = 0;
		system("cls");
		print(ddd, nnn);
		cout << TOU[1].num << "号," << TOU[2].num << "号";
		int i;
		for (i = 3; i <= n; i++) {
			if (TOU[i].xxx == TOU[1].xxx) {
				TOU[i].toupiaoquan = 0;
				cout << "," << TOU[i].num << "号";
			} else break;
		} if (i == n + 1) {
			for (int i = 1; i <= n; i++) TOU[i].toupiaoquan = 1;
		} cout << "平票" << endl;
	} 
	sort(TOU + 1, TOU + n + 1, cmp1);
	cout << "请再次投票";
	for (int i = 1; i <= 3; i++) {
		cout << ".";
		Sleep(500);
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		if (player[i].life == 1 && TOU[i].toupiaoquan == 1) {
			Sleep(3000);
			if (i == MY) {
				cout << "请投票...(0弃权)" << endl;
				cin >> x;
				while ((player[x].life == 0 || TOU[x].toupiaoquan == 1) && x != 0) {
					cin >> x;
				}
				if (x == 0) cout << MY << "号玩家弃权" << endl;
				else cout << MY << "号玩家投给了" << x << "号玩家" << endl;
			} else { 
				srand(time(0));
				if (player[i].name == "狼人 ") {
					x = rand() % (n + 1);
					while (x != 0 && (player[x].life == 0 || player[x].name == "狼人 " || x == i || TOU[x].toupiaoquan == 1)) {
						srand(time(0));
						x = rand() % (n + 1);
					}
					if (x == 0) cout << i << "号玩家弃权" << endl;
					else cout << i << "号玩家投给了" << x << "号玩家" << endl;
				} else if (player[i].name == "预言家 " || player[i].name == "猎人 ") {
					x = rand() % (n + 1);
					while (x != 0 && (player[x].life == 0 || player[x].name != "狼人 " || x == i || TOU[x].toupiaoquan == 1)) {
						srand(time(0));
						x = rand() % (n + 1);
					}
					if (x == 0) cout << i << "号玩家弃权" << endl;
					else cout << i << "号玩家投给了" << x << "号玩家" << endl;
				} else { x = rand() % (n + 1);
					while (x != 0 && (player[x].life == 0 || x == i || TOU[x].toupiaoquan == 1)) {
						srand(time(0));
						x = rand() % (n + 1);
					}
					if (x == 0) cout << i << "号玩家弃权" << endl;
					else cout << i << "号玩家投给了" << x << "号玩家" << endl;
				}
			} 
			if (x != 0 && TOU[i].toupiaoquan == 1) TOU[x].xxx++;
		}
	}
	Sleep(3000);
	sort(TOU + 1, TOU + n + 1, cmp);
	if (TOU[2].xxx != TOU[1].xxx) {
		cout << "投票结束," << TOU[1].num << "号投票出局" << endl;
		player[TOU[1].num].life = 0;
		player[TOU[1].num].how = 2;
	} else {
		cout << "投票结束,无人出局" << endl;
	} 
	Sleep(5000); 
}
