//Day and night cycle with game over
//昼夜循环与游戏结束
bool game_over() {
	int pingmin = 0;
	int langren = 0;
	int shenzhi = 0;
	for (int i = 1; i <= n; i++) {
		if (player[i].life == 0) continue;
		if (player[i].name == "狼人 ") langren++;
		else if (player[i].name == "村民 ") pingmin++;
		else if (player[i].name == "女巫 " || player[i].name == "预言家 " || player[i].name == "猎人 ") shenzhi++;
	}
	if (shenzhi == 0 || langren == 0 || pingmin == 0) return 1;
	return 0;
}
void night() {
	system("cls");
	system("color 0f");
	print(1, 1);
	cout << "天~黑~请~闭~眼~" << endl;
	if (n >= 12) shoushui(1, 1);
	Sleep(3000); 
	system("cls"); 
	print(1, 1);
	cout << "狼~人~请~睁~眼~" << endl;
	if (player[MY].name == "狼人 ") {
		Sleep(1000);
		cout << "你的同伴有:";
		for (int i = 1; i <= n; i++) {
			if (i == MY) continue;
			if (player[i].name == "狼人 ") {
				cout << player[i].num << "号 ";
				player[i].know = 2;
			}
		}
		Sleep(3000);
		cout << endl << "请问你们要杀谁:" << endl << "输入:";
		cin >> kill1; Sleep(1500); system("cls"); print(1, 1);
		cout << "今晚你们要杀的是" << kill1 << "号玩家" << endl;
	} else {
		Sleep(4000);
		system("cls");
		print(1, 1);
		cout << "请问你们要杀谁?" << endl;
		do {
			Sleep(rand() % 18);
			srand(time(0));
			int x = rand() % n + 1;
			if (player[x].name != "狼人 " && player[x].life == 1) {
				kill1 = x;
				break;
			}
		}
		while(1) ;Sleep(5000); 
	}
	Sleep(3000);
	system("cls");
	print(1, 1);
	cout << "狼~人~请~闭~眼~" << endl;
	Sleep(2000);
	system("cls");
	print(1, 1);
	cout << "女~巫~请~睁~眼~" << endl;
	Sleep(2000);
	system("cls");
	print(1, 1);
	if (player[MY].name == "女巫 " && player[MY].life == 1) {
		Sleep(1000);
		if (jieyao == 1) {
			cout << "今晚" << kill1 << "号玩家被杀" << endl;
			Sleep(500);
			cout << "请问你要救吗???" << endl << "A. 救 B.不救" << endl << "输入:";
			cin >> a;
			if (a == 'A') {
				system("cls");
				print(1, 1);
				cout << "请问你要毒吗???" << endl;
				Sleep(2000);
				system("cls");
				print(1, 1);
				cout << "今晚" << kill1 << "号玩家被你解救" << endl;
				jieyao = 0;
				if (shou != kill1) kill1 = 0;
			} else {
				if (shou == kill1) kill1 = 0;
				Sleep(2000);
				system("cls");
				print(1, 1);
				cout << "请问你要毒吗???" << endl << "A. 毒 B.不毒" << endl << "输入:";
				cin >> a;
				if (a == 'A') {
					cout << "请问你要毒谁???" << endl << "输入:";
					cin >> kill2;
					while (player[kill2].life != 1) {
						cout << "输入错误,请重新输入:" << endl;
						cin >> kill2;
					}
					duyao = 0;
				}
			}
		} else {
			if (shou == kill1) kill1 = 0;
			Sleep(2000);
			system("cls");
			print(1, 1);
			cout << "请问你要毒吗???" << endl << "A. 毒 B.不毒" << endl << "输入:";
			cin >> a;
			if (a == 'A') {
				cout << "请问你要毒谁???" << endl << "输入:";
				cin >> kill2;
				while (player[kill2].life != 1) {
					cout << "输入错误,请重新输入:" << endl;
					cin >> kill2; } duyao = 0; 
			}
		}
	} else {
		bool b = 0;
		cout << "请问你是否要用解药???" << endl;
		int FFF = 0, kkkk;
		for (int i = 1; i <= n; i++) {
			if (player[i].life == 1 && player[i].name == "村民 ") FFF++;
			if (player[i].name == "女巫 ") kkkk = i;
		}
		if (jieyao == 1 && player[kkkk].life == 1) {
			if (FFF == 1) {
				if (shou == kill1) jieyao = 1;
				else jieyao = 0;
				kill1 = 0;
				b = 1;
			} else for (int i = 1; i <= n; i++) {
				if (player[i].name == "女巫 " && kill1 == i) {
					kill1 = 0;
					if (shou == kill1) jieyao = 1;
					else jieyao = 0;
					b = 1;
					break;
				} else if (player[i].name == "预言家 " && kill1 == i) {
					kill1 = 0;
					if (shou == kill1) jieyao = 1;
					else jieyao = 0; b = 1;
					break;
				}
			}
		}
		Sleep(3000);
		if (b == 0 && duyao == 1 && player[kkkk].life == 1) {
			system("cls");
			print(1, 1);
			cout << "请问你是否要用毒药???" << endl;
			srand(time(0));
			int x = rand() % 2;
			Sleep(1500);
			cout << "请问你要毒谁???" << endl;
			if (x == 1) {
				duyao = 0;
				int y = rand() % n + 1;
				while ((player[y].name == "女巫 " || player[y].name == "预言家 " || y == kill1) || player[y].life == 0)
					y = rand() % n + 1; kill2 = y;
			}
		
		} else {
			Sleep(3000);
			system("cls");
			print(1, 1);
			cout << "请问你是否要用毒药???" << endl;
			Sleep(3000);
			cout << "请问你要毒谁???" << endl;
			Sleep(3000);
		}
	}
	Sleep(3000);
	system("cls");
	print(1, 1);
	cout << "女~巫~请~闭~眼~" << endl;
	if (n > 6) {
		Sleep(3000);
		system("cls");
		print(1, 1);
		cout << "预~言~家~请~睁~眼~" << endl;
		if (player[MY].name == "预言家 ") {
			Sleep(3000);
			cout << "请问你想查验谁???" << endl << "输入:";
			int x;
			cin >> x;
			player[x].know = 1;
			Sleep(2000);
			system("cls");
			print(1, 1);
			cout << "他的身份是:";
			if (player[x].name == "狼人 ") cout << "狼人" << endl;
			else cout << "好人" << endl; Sleep(3000);
		} else {
			Sleep(3000);
			cout << "请问你想查验谁???" << endl;
			Sleep(3000);
			system("cls");
			print(1, 1);
			cout << "他的身份是:......";
			Sleep(3000);
		}
		Sleep(3000);
		system("cls");
		print(1, 1);
		cout << "预~言~家~请~闭~眼~" << endl;
	}
	Sleep(3000);
	if (kill1 != 0) player[kill1].life = 0;
	if (kill2 != 0) player[kill2].life = 0;
	player[kill1].how = 1;
	player[kill2].how = 3;
	system("cls");
	system("color F0");
	print(2, 0);
}
void night2(int hhh, int hhhh) {
	system("cls");
	system("color 0f"); 
	print(hhh, hhhh); 
	cout << "天~黑~请~闭~眼~" << endl; 
	if (n >= 12) shoushui(hhh, hhhh); 
	Sleep(3000); 
	system("cls"); 
	print(hhh, hhhh); 
	cout << "狼~人~请~睁~眼~" << endl;
	if (player[MY].name == "狼人 " && player[MY].life == 1) { 
		Sleep(3000); 
		cout << endl << "请问你们要杀谁:" << endl << "输入:"; 
		cin >> kill1; Sleep(1500); 
		system("cls"); print(hhh, hhhh); 
		cout << "今晚你们要杀的是" << kill1 << "号玩家" << endl;
	} else { 
		Sleep(4000); 
		system("cls"); 
		print(hhh, hhhh); 
		cout << "请问你们要杀谁?" << endl; 
		do { 
			srand(time(0)); 
			int x = rand() % n + 1; 
			if (player[x].name != "狼人 " && player[x].life == 1) {
				kill1 = x; 
				break; 
			} 
		} while (1); 
		Sleep(5000); 
	} 
	Sleep(3000); 
	system("cls"); 
	print(hhh, hhhh); 
	cout << "狼~人~请~闭~眼~" << endl; 
	Sleep(2000); 
	system("cls"); 
	print(hhh, hhhh); 
	cout << "女~巫~请~睁~眼~" << endl; 
	Sleep(2000); 
	system("cls"); 
	print(hhh, hhhh); 
	if (player[MY].name == "女巫 " && player[MY].life == 1) { 
		Sleep(1000); 
		if (jieyao == 1) { 
			cout << "今晚" << kill1 << "号玩家被杀" << endl;
			Sleep(500); cout << "请问你要救吗???" << endl << "A. 救 B.不救" << endl << "输入:"; 
			cin >> a; 
			if (a == 'A') { 
				system("cls"); 
				print(hhh, hhhh); 
				cout << "请问你要毒吗???" << endl; 
				Sleep(2000); 
				system("cls"); 
				print(hhh, hhhh); 
				cout << "今晚" << kill1 << "号玩家被你解救" << endl; 
				jieyao = 0; 
				if (shou != kill1) kill1 = 0; 
			} else { 
				if (shou == kill1) kill1 = 0; 
				Sleep(2000); 
				system("cls"); 
				print(hhh, hhhh); 
				cout << "请问你要毒吗???" << endl << "A. 毒 B.不毒" << endl << "输入:"; 
				cin >> a; 
				if (a == 'A') { 
					cout << "请问你要毒谁???" << endl << "输入:"; 
					cin >> kill2; 
					while (player[kill2].life != 1) { 
						cout << "输入错误,请重新输入:" << endl; 
						cin >> kill2; 
					} 
					duyao = 0; 
				} 
			} 
		} else if (duyao == 1) { 
			if (shou == kill1) kill1 = 0; 
			Sleep(2000); 
			system("cls"); 
			print(hhh, hhhh); 
			cout << "请问你要毒吗???" << endl << "A. 毒 B.不毒" << endl << "输入:"; 
			cin >> a; 
			if (a == 'A') { 
				cout << "请问你要毒谁???" << endl << "输入:"; 
				cin >> kill2; 
				while (player[kill2].life != 1) { 
					cout << "输入错误,请重新输入:" << endl; 
					cin >> kill2; 
				} 
				duyao = 0;
			} 
		} else { 
			Sleep(2000); 
			system("cls"); 
			print(hhh, hhhh); 
			cout << "请问你要毒吗???" << endl; 
		} 
	} else { 
		bool b = 0; 
		cout << "请问你是否要用解药???" << endl; 
		int FFF = 0, kkkk; 
		for (int i = 1; i <= n; i++) { 
			if (player[i].life == 1 && player[i].name == "村民 ") FFF++; 
			if (player[i].name == "女巫 ") kkkk = i; 
		} 
		if (jieyao == 1 && player[kkkk].life == 1) { 
			if (FFF == 1) { 
				if (shou == kill1) jieyao = 1; 
				else jieyao = 0; 
				kill1 = 0; 
				b = 1; 
			} else for (int i = 1; i <= n; i++) { 
				if (player[i].name == "女巫 " && kill1 == i) { 
					kill1 = 0; 
					if (shou == kill1) jieyao = 1; 
					else jieyao = 0; 
					b = 1; 
					break; 
				} else if (player[i].name == "预言家 " && kill1 == i) { 
					kill1 = 0; 
					if (shou == kill1) jieyao = 1; 
					else jieyao = 0; 
					b = 1; 
					break; 
				} 
			} 
		} 
		Sleep(3000); 
		if (b == 0 && duyao == 1 && player[kkkk].life == 1) { 
			system("cls"); 
			print(hhh, hhhh); 
			cout << "请问你是否要用毒药???" << endl; 
			srand(time(0)); 
			int x = rand() % 2; 
			Sleep(1500); 
			cout << "请问你要毒谁???" << endl; 
			if (x == 1) { 
				duyao = 0; 
				int y = rand() % n + 1; 
				while ((player[y].name == "女巫 " || player[y].name == "预言家 " || y == kill1) || player[y].life == 0) y = rand() % n + 1; 
				kill2 = y; 
			} 
		} else { 
			Sleep(3000); 
			system("cls"); 
			print(hhh, hhhh); 
			cout << "请问你是否要用毒药???" << endl; 
			Sleep(3000); 
			cout << "请问你要毒谁???" << endl; 
			Sleep(3000); 
		} 
	} 
	Sleep(3000); 
	system("cls"); 
	print(hhh, hhhh); 
	cout << "女~巫~请~闭~眼~" << endl; 
	if (n > 6) { 
		Sleep(3000); 
		system("cls"); 
		print(hhh, hhhh); 
		cout << "预~言~家~请~睁~眼~" << endl; 
		if (player[MY].name == "预言家 " && player[MY].life == 1) { 
			Sleep(3000); 
			cout << "请问你想查验谁???" << endl << "输入:"; 
			int x; cin >> x; player[x].know = 1; 
			Sleep(2000); 
			system("cls"); 
			print(hhh, hhhh); 
			cout << "他的身份是:"; 
			if (player[x].name == "狼人 ") cout << "狼人" << endl; 
			else cout << "好人" << endl; 
			Sleep(3000); 
		} else { 
			Sleep(3000); 
			cout << "请问你想查验谁???" << endl; 
			Sleep(3000); 
			system("cls"); 
			print(hhh, hhhh); 
			cout << "他的身份是:......"; 
			Sleep(3000); 
		} 
		Sleep(3000); 
		system("cls"); 
		print(hhh, hhhh); 
		cout << "预~言~家~请~闭~眼~" << endl; 
	} 
	Sleep(3000); 
	if (kill1 != 0) player[kill1].life = 0; 
	if (kill2 != 0) player[kill2].life = 0; 
	player[kill1].how = 1; 
	player[kill2].how = 3; 
	system("cls"); 
	system("color F0"); 
	print(hhh + 1, 0); 
}
