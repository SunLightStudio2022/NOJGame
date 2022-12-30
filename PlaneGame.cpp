#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>
using namespace std;
HANDLE hCon;
struct phb{
	int score=-1;
	string name="";
};
enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };
void SetColor(Color c) {
if(hCon == NULL)
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hCon, c);
}
phb topten[10]={0};
typedef struct Frame { COORD position[2]; int flag; }Frame;
int d=0;
char bullet_mode='0';
void SetPos(COORD a) { HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(out, a);} 
 void SetPos(short i, short j) { COORD pos={i, j}; SetPos(pos); } 
 void HideCursor() { CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); }
void drawRow(int y, int x1, int x2, char ch) { SetPos(x1,y); for(int i = 0; i <= (x2-x1); i++) cout<<ch; }
void drawRow(COORD a, COORD b, char ch) { if(a.Y == b.Y) drawRow(a.Y, a.X, b.X, ch); 
else { SetPos(0, 25); cout<<"error code 01：无法填充行，因为两个坐标的纵坐标(x)不相等"; system("pause"); } }
void drawCol(int x, int y1, int y2, char ch) 
{ int y=y1; while(y!=y2+1) { SetPos(x, y); cout<<ch; y++; } }
void drawCol(COORD a, COORD b, char ch) { if(a.X == b.X) drawCol(a.X, a.Y, b.Y, ch); 
else { SetPos(0, 25); cout<<"error code 02：无法填充列，因为两个坐标的横坐标(y)不相等"; system("pause"); } }
void drawFrame(COORD a, COORD b, char row, char col) { drawRow(a.Y, a.X+1, b.X-1, row); 
drawRow(b.Y, a.X+1, b.X-1, row); drawCol(a.X, a.Y+1, b.Y-1, col); drawCol(b.X, a.Y+1, b.Y-1, col); } 
void drawFrame(short x1, short y1, short x2, short y2, char row, char col) { COORD a={x1, y1}; COORD b={x2, y2}; 
drawFrame(a, b, row, col); } void drawFrame(Frame frame, char row, char col) { COORD a = frame.position[0]; 
COORD b = frame.position[1]; drawFrame(a, b, row, col); } void drawPlaying() { drawFrame(0, 0, 48, 24, '=', '|');
drawFrame(49, 0, 79, 4, '-', '|');
drawFrame(49, 4, 79, 9, '-', '|'); 
drawFrame(49, 9, 79, 20, '-', '|'); 
drawFrame(49, 20, 79, 24, '-', '|'); 
SetPos(52, 6); cout<<"得分："; SetPos(52, 7); cout<<"称号："; 
SetPos(52,10); cout<<"操作方式："; SetPos(52,12); 
cout<<" a,s,d,w 控制激光枪移动。"; SetPos(52,14); 
cout<<" p 暂停游戏。"; SetPos(52,16); 
cout<<" e 退出游戏。"; SetPos(52,18); 
cout<<" k 发射子弹。"; SetPos(52, 20);
cout<<" 小金泽恺一颗子弹就可以打落，";SetPos(52, 22);
cout<<" 大金泽恺三颗子弹可以打落。"; 
}
int random(short a, short b) { int c=(rand() % (a-b))+ a; return c; }
COORD random(COORD a, COORD b) { short int x=random(a.X, b.X); 
short int y=random(a.Y, b.Y); COORD c={x, y}; return c; } 
bool judgeCoordInFrame(Frame frame, COORD spot) { 
if(spot.X>=frame.position[0].X) if(spot.X<=frame.position[1].X) 
if(spot.Y>=frame.position[0].Y) if(spot.Y<=frame.position[0].Y) return true; return false; } 
void printCoord(COORD a) { cout <<"( "<<a.X<<" , "<<a.Y<<" )"; } 
void printFrameCoord(Frame a) { printCoord(a.position[0]); 
cout <<" - "; printCoord(a.position[1]); } 
string name="";
void returnname(){
	system("cls");
}
void welcome(){
	system("cls");
	SetPos(30, 1);
	cout<<"欢迎，"<<name;
	Sleep(2000); 
}
void drawphb(){
	system("cls");
	SetPos(30, 1);
	cout<<"排行榜"<<endl;
	for (int xxx=0;xxx<10;xxx++){
		SetPos(30, 1+xxx+5);
		if (topten[xxx].name == "" && topten[xxx].score == -1){
			break;
		}
		cout<<topten[xxx].name<<'\t'<<topten[xxx].score; 
	}
}
int drawGuns(){
	system("cls");
	SetConsoleTitle("打金泽恺大战 1.2.2 - 选择武器");
	SetPos(30, 1); cout<<"打金泽恺大战 1.2.2 - 选择武器";drawRow(3, 0, 79, '-');
	drawRow(5, 0, 79, '-'); SetPos(28, 4); cout<<"请输入序号"; 
	SetPos(15, 11); cout<<"1. AK47"; SetPos(15, 13); cout<<"2. RPG"; 
	SetPos(15, 15); cout<<"3. 加特林";
	SetPos(15, 17); cout<<"4. 95式";
	drawRow(20, 0, 79, '-'); drawRow(22, 0, 79, '-');SetPos(24, 21); cout<<" S B S B S B S B S B "; 
	SetPos(50, 15);
	int z;
	cin>>z;
	while (z != 1&&z != 2&&z != 3&&z != 4){
		SetPos(35, 17);
		cout<<"你选择的武器不合法！";
		SetPos(50, 15);
		cout<<"                          ";
		SetPos(50, 15);
		cin>>z;
	}
	if (z == 1){
		bullet_mode = '^';
	}else if (z == 2){
		bullet_mode = 'O';
	}else if (z == 3){
		bullet_mode = '#';
	}else if (z == 4){
		bullet_mode = 'X';
	}
	return 1; 
}
int drawMenu() { system("cls");
SetConsoleTitle("打金泽恺大战 1.2.2 - 选择敌人");
SetPos(30, 1); cout<<"打金泽恺大战 1.2.2 - 选择敌人"; drawRow(3, 0, 79, '-'); 
drawRow(5, 0, 79, '-'); SetPos(28, 4); cout<<"w 和 s 选择， k 确定"; 
SetPos(15, 11); cout<<"1. 金泽恺1级"; SetPos(15, 13); cout<<"2. 金泽恺2级"; 
drawRow(20, 0, 79, '-'); drawRow(22, 0, 79, '-'); SetPos(47, 11); cout<<"金泽恺1级："; 
SetPos(51, 13); cout<<"1级的金泽恺有着较慢的移动速度。"; SetPos(24, 21); cout<<" S B S B S B S B S B "; 
int j=11; SetPos(12, j); cout<<">>"; while(1) { if( _kbhit() ) { char x=_getch();
 switch (x) { case 'w' : { if( j == 13) { SetPos(12, j); cout<<"　"; j = 11; 
 SetPos(12, j); cout<<">>"; SetPos(51, 13); cout<<"　　　　　　　　　　　　"; 
 SetPos(47, 11); cout<<"金泽恺1级："; SetPos(51, 13); cout<<"1级的金泽恺有着较慢的移动速度。"; } break; } 
 case 's' : { if( j == 11 ) { SetPos(12, j); cout<<"　"; j = 13; SetPos(12, j); cout<<">>"; SetPos(51, 13); 
 cout<<"　　　　　　　　　　　　　　"; SetPos(47, 11); cout<<"金泽恺2级："; SetPos(51, 13); 
 cout<<"2级的金泽恺有着较快的移动速度。"; } break; } case 'k' : { if (j == 8) return 1; else return 2; } } } } }
class Game { public: COORD position[10]; 
COORD bullet[10]; Frame enemy1[4]; Frame enemy2[4];int enemy2_nu[4]={0};int  score; int rank; int rankf; string title; int flag_rank; Game ();
void initPlane(); void initBullet(); void initenemy1();
void planeMove(char); void bulletMove(); void enemy1Move();
void drawPlane(); void drawPlaneToNull(); void drawBullet(); 
void drawBulletToNull(); void drawenemy1(); void drawenemy1ToNull();
void drawThisBulletToNull( COORD ); void drawThisenemy1ToNull( Frame ); 
void Pause(); void Playing(); void judgePlane(); void judgeenemy1(); void Shoot(); 
void GameOver(); void printScore(); }; Game::Game() { initPlane(); initBullet(); initenemy1(); 
score = 0; rank = 25; rankf = 0; flag_rank = 0; } void Game::initPlane() { COORD centren={39, 22}; 
position[0].X=position[5].X=position[7].X=position[9].X=centren.X; position[1].X=centren.X-2; 
position[2].X=position[6].X=centren.X-1; position[3].X=position[8].X=centren.X+1; position[4].X=centren.X+2; 
for(int i=0; i<=4; i++) position[i].Y=centren.Y; for(int i=6; i<=8; i++) position[i].Y=centren.Y+1; 
position[5].Y=centren.Y-1; position[9].Y=centren.Y-2; } 
void Game::drawPlane() { for(int i=0; i<9; i++) { 
SetPos(position[i]); if(i!=5) cout<<"H"; else if(i==5) cout<<"|"; } } 
void Game::drawPlaneToNull() { for(int i=0; i<9; i++) { 
SetPos(position[i]); cout<<" "; } } 
void Game::initBullet() { for(int i=0; i<10; i++)
 bullet[i].Y = 30; } void Game::drawBullet() { for(int i=0; i<10; i++) { 
 if( bullet[i].Y != 30) { SetPos(bullet[i]); cout<<bullet_mode; } } } 
 void Game::drawBulletToNull() { for(int i=0; i<10; i++) 
 if( bullet[i].Y != 30 ) { COORD pos={bullet[i].X, bullet[i].Y+1}; 
 SetPos(pos); cout<<" "; } } 
 void Game::initenemy1() { COORD a={1, 1}; COORD b={45, 15}; 
 for(int i=0; i<4; i++) { enemy1[i].position[0] = random(a, b); 
 enemy1[i].position[1].X = enemy1[i].position[0].X + 3; 
 enemy1[i].position[1].Y = enemy1[i].position[0].Y + 2; } 
 for (int i=0;i<4;i++){
 	enemy2[i].position[0] = random(a, b);
 	enemy2[i].position[1].X = enemy2[i].position[0].X+5;
 	enemy2[i].position[1].Y = enemy2[i].position[0].Y + 4; 
 } 
 } 
 void Game::drawenemy1() { for(int i=0; i<4; i++) {
 drawFrame(enemy1[i].position[0], enemy1[i].position[1], 'S', 'B');}
 for (int i=0;i<4;i++){
 	drawFrame(enemy2[i].position[0], enemy2[i].position[1], 'S', 'B');
 }
  } 
 void Game::drawenemy1ToNull() { for(int i=0; i<4; i++) { 
 drawFrame(enemy1[i].position[0], enemy1[i].position[1], ' ', ' '); } 
 for (int i=0;i<4;i++){
 	drawFrame(enemy2[i].position[0], enemy2[i].position[1], ' ', ' ');
 }
 } 
 void Game::Pause() { SetPos(61,2); cout<<" "; SetPos(61,2); 
 cout<<"歇一下再继续打金泽恺"; char c=_getch(); while(c!='p') c=_getch(); SetPos(58,2); cout<<" "; } 
 void Game::planeMove(char x) { if(x == 'a') if(position[1].X != 1) 
 for(int i=0; i<=9; i++) position[i].X -= 2; if(x == 's') 
 if(position[7].Y != 23) for(int i=0; i<=9; i++) 
 position[i].Y += 1; if(x == 'd') if(position[4].X != 47)
  for(int i=0; i<=9; i++) position[i].X += 2; if(x == 'w') if(position[5].Y != 3) 
  for(int i=0; i<=9; i++) position[i].Y -= 1; } 
  void Game::bulletMove() { for(int i=0; i<10; i++) { 
  if( bullet[i].Y != 30) { bullet[i].Y -= 1; if( bullet[i].Y == 1 ) { 
  COORD pos={bullet[i].X, bullet[i].Y+1}; drawThisBulletToNull( pos ); bullet[i].Y=30; } } } } 
  void Game::enemy1Move() { for(int i=0; i<4; i++) { 
    for(int j=0; j<2; j++) enemy1[i].position[j].Y++; if(24 == enemy1[i].position[1].Y) { 
    COORD a={1, 1}; COORD b={45, 3}; enemy1[i].position[0] = random(a, b); 
    enemy1[i].position[1].X = enemy1[i].position[0].X + 3; enemy1[i].position[1].Y = enemy1[i].position[0].Y + 2; } }
	for(int i=0; i<4; i++) { 
	    for(int j=0; j<2; j++) enemy2[i].position[j].Y++; if(24 == enemy2[i].position[1].Y) { 
	    COORD a={1, 1}; COORD b={45, 3}; enemy2[i].position[0] = random(a, b); 
	    enemy2[i].position[1].X = enemy2[i].position[0].X + 5; enemy2[i].position[1].Y = enemy2[i].position[0].Y + 4; } } } 
  void Game::judgePlane() { for(int i = 0; i < 4; i++){ for(int j=0; j<9; j++) {
  if(judgeCoordInFrame(enemy1[i], position[j])) { SetPos(62, 1); 
  SetConsoleTitle("打金泽恺大战 1.2.2 - Game Over");
  cout<<"被金泽恺打死了"; drawFrame(enemy1[i], 'X', 'x'); Sleep(1000); GameOver(); break; }}}
  for(int i = 0; i < 4; i++){ for(int j=0; j<9; j++) {
    if(judgeCoordInFrame(enemy2[i], position[j])) { SetPos(62, 1); 
    cout<<"被金泽恺打死了"; drawFrame(enemy2[i], 'X', 'x'); Sleep(1000); GameOver(); break; }}} }
   void Game::drawThisBulletToNull( COORD c) { SetPos(c); cout<<" "; } 
   void Game::drawThisenemy1ToNull( Frame f ) { drawFrame(f, ' ', ' '); } 
   void Game::judgeenemy1() { for(int i = 0; i < 4; i++){ for(int j = 0; j < 10; j++) {
   if( judgeCoordInFrame(enemy1[i], bullet[j]) ) { score += 5; drawThisenemy1ToNull( enemy1[i] );
    COORD a={1, 1}; COORD b={45, 3}; enemy1[i].position[0] = random(a, b); 
    enemy1[i].position[1].X = enemy1[i].position[0].X + 3; enemy1[i].position[1].Y = enemy1[i].position[0].Y + 2; 
    drawThisBulletToNull( bullet[j] ); bullet[j].Y = 30; } }}
	for(int i = 0; i < 4; i++){ for(int j = 0; j < 10; j++) {
	   if( judgeCoordInFrame(enemy2[i], bullet[j]) ) { enemy2_nu[i]++; if (enemy2_nu[i] == 3){score += 10; 
	   drawThisenemy1ToNull( enemy2[i] );
	    COORD a={1, 1}; COORD b={45, 3}; enemy2[i].position[0] = random(a, b);enemy2_nu[i] = 0; 
	    enemy2[i].position[1].X = enemy2[i].position[0].X + 3; enemy2[i].position[1].Y = enemy2[i].position[0].Y + 2; 
	    drawThisBulletToNull( bullet[j] ); bullet[j].Y = 30; }}}}} 
    void Game::Shoot() { for(int i=0; i<10; i++) if(bullet[i].Y == 30) {
bullet[i].X = position[5].X; bullet[i].Y = position[5].Y-1; break; } }
 void Game::printScore() { if(score == 120 && flag_rank == 0) { rank -= 3; flag_rank = 1; } 
 else if( score == 360 && flag_rank == 1) { rank -= 5; flag_rank = 2; } 
 else if( score == 480 && flag_rank == 2) { rank -= 5; flag_rank = 3; } 
 int x=rank/5; SetPos(60, 6); cout<<score; if( rank!=rankf ) { SetPos(60, 7); 
 if( x == 5) title="高级飞行员"; else if( x == 4) title="打死金泽恺的英雄";
 else if( x == 3){ title="打死24个金泽恺的英雄";system("color 3"); }else if( x == 2 ){ title="打死72个金泽恺的英雄"; system("color 6");}
 else if( x == 1 ){ title="打死100个金泽恺的英雄"; system("color 8");}cout<<title; } rankf = rank; }
  void Game::Playing() {
drawenemy1(); drawPlane(); int flag_bullet = 0; int flag_enemy1 = 0; while(1) { Sleep(8); 
if(_kbhit()) { char x = _getch(); if ('a' == x || 's' == x || 'd' == x || 'w' == x) { 
drawPlaneToNull(); planeMove(x); drawPlane(); judgePlane(); } else if ('p' == x) Pause(); 
else if( 'k' == x) Shoot(); else if( 'e' == x) {
GameOver(); break; } }
if( 0 == flag_bullet ) { 
bulletMove(); drawBulletToNull(); drawBullet(); judgeenemy1(); }
 flag_bullet++; if( 5 == flag_bullet ) flag_bullet = 0;
if( 0 == flag_enemy1 ) {
     drawenemy1ToNull(); enemy1Move(); drawenemy1(); judgePlane(); 
     } flag_enemy1++; if( flag_enemy1 >= rank ) flag_enemy1 = 0; printScore(); } } 
     void Game::GameOver() { system("cls"); 
	 SetConsoleTitle("打金泽恺大战 1.2.2 - Game Over");
	 system("color 0F");rank=25;COORD p1={28,9}; COORD p2={53,15};
      drawFrame(p1, p2, '=', '|'); SetPos(36,12); string str="Game Over!"; 
      for(int i=0; i<str.size(); i++) { Sleep(80); cout<<str[i]; } Sleep(1000); system("cls"); 
      drawFrame(p1, p2, '=', '|'); SetPos(31, 11); cout<<"打死金泽恺："<<score/5<<" 个"; SetPos(31, 12);
       cout<<"得　　分："<<score; SetPos(31, 13); cout<<"获得称号："<<title; SetPos(30, 16); Sleep(1000); 
       cout<<"继续？ 是（y）| 否（n）"; as: char x=_getch(); if (x == 'n') exit(0); else if (x == 'y') { 
       system("cls"); 
				 Game game; int d = drawGuns(); if(d == 2) game.rank = 20; system("cls"); int a = drawMenu(); if(a == 2) game.rank = 20; system("cls"); 
				       drawPlaying(); game.Playing(); 
			} else goto as; }
void loadingBar() 
{
    //system("color 0a");
    SetPos(30, 20);
    cout<<"Loading……";
    SetPos(30, 25);
    SetColor(RED);
    cout<<"正在加载界面";
	char b[] = "......";
	for (int zc=0;zc<6;zc++){
		cout<<b[zc];
		Sleep(100);
	} 
	SetPos(30, 27);
	SetColor(YELLOW);
	cout<<"正在加载信息";
	for (int zc=0;zc<6;zc++){
			cout<<b[zc];
			Sleep(100);
		}
	SetPos(30, 29);
	SetColor(GREEN);
	cout<<"正在初始化";
	for (int zc=0;zc<6;zc++){
			cout<<b[zc];
			Sleep(100);
		}
	Sleep(1500);
    
}
int main() {
loadingBar();
returnname();
welcome();
system("cls");
system("color 0F");
srand((int)time(0));
HideCursor();
Game game; 
d = drawGuns();
int a = drawMenu();
 if(a == 2) game.rank = 20; system("cls"); 
  if(d == 2) game.rank = 20; system("cls"); 
 drawPlaying(); game.Playing(); }
