#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
HANDLE hCon;
enum Color { 
    DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE 
};
void SetColor(Color c) {
    if(hCon == NULL)
       hCon = GetStdHandle(STD_OUTPUT_HANDLE);
       SetConsoleTextAttribute(hCon, c);
    }
    #define sc SetColor
    void SetPos(COORD a) { HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(out, a);
}                          
void SetPos(short i, short j) { 
    COORD pos={i, j};
    SetPos(pos); 
} 
char gm[21][21];
long long start,sk;
char press;
int x,y,score;
bool win;
void chuangzao(){
    srand(time(0));int k;
    for(int i=0;i<21;i++){
        for(int k=0;k<21;k++){
            gm[i][k]=' ';
        }
    }
    for(int i=0;i<21;i++){
        gm[i][0]=gm[0][i]='#';
        gm[i][20]=gm[20][i]='#';
    }
    for(int i=2;i<19;i+=2){
        k=(rand()%19)+1;
        for(int p=1;p<20;p++){
            if(k!=p)gm[i][p]='#';
        }
    }
    gm[1][1]='*';gm[19][19]='$';
    x=1;y=1;win=false;
}
void show(){
    system("cls");
    for(int i=0;i<21;i++){
        for(int k=0;k<21;k++){
            cout<<gm[i][k];
        }
        cout<<endl;
    }
    cout<<"\n砸钱大战。\n";
    cout<<"请按ad键移动,k键下落。\n";
    cout<<"已砸掉金币"<<score<<"个。\n";
    cout<<"已用时"<<((clock()-start)/1000)<<"秒。";
}
void showwin(){
    system("cls");
    srand((unsigned)time(NULL));
    int s=((clock()-start)/1000);
    if (s <= 30){
        score += rand()%100000;
    }else if (s > 30 && s < 100){
        score += rand()% 10000;
    }else{
        score += rand()% 1000;
    }
    cout<<"\n\n\n\n\t\t\t你赢了!";MessageBox(NULL, "你赢了！","提示", NULL);
    cout<<"\n\n\n\t\t\t获得金币！你有金币"<<score<<"枚了！";
    cout<<"\n\n\n\t\t\t用时"<<((clock()-start)/1000)<<"秒!";
    Sleep(2000);
}
void diaoluo(){
    if(gm[x+1][y]=='#')return ;
    Sleep(100);show();
    gm[x][y]=' ';x++;gm[x][y]='*';
    Sleep(100);show();
    gm[x][y]=' ';x++;gm[x][y]='*';
    Sleep(100);show();
    if(x==19&&y==19)win=true;
}
void yidong(){
    gm[x][y]=' ';
    if(press==97){
        if(y!=1)y--;
    }
    if(press==100){
        if(y!=19)y++;
    }
    if(press==107){
        while(gm[x+1][y]==' ')
        diaoluo();
    }
    gm[x][y]='*';
    if(x==19&&y==19)win=true;
}
void loadingBar() 
{
    //system("color 0a");
    SetPos(30, 20);
    cout<<"Loading......";
    SetPos(20, 35);
    cout<<"|";
    for (int i=0;i<40;i++){
        sc(RED);cout<<"-";sc(WHITE);for (int j=i;j<40;j++){cout<<" ";}
        cout<<"|";cout<<" eta ";sc(BLUE);cout<<"00:00:"<<40-i;
        Sleep(100);system("cls");sc(WHITE);SetPos(30, 20);cout<<"Loading......";
        SetPos(20, 35);cout<<"|";sc(RED);for (int k=0;k<i;k++){cout<<"-";}


    }
}
int main(){
    SetConsoleTitle("砸钱大战");
    loadingBar();
    SetColor(WHITE);
    while(1){
        chuangzao();start=clock();
        while(!win){
            show();sk=clock();
            while((clock()-sk)<=1000){
                if(kbhit()){
                    press=getch();
                    yidong();break;
                }
            }
        }
        showwin();
    }
    return 0;
}
