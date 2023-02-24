#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include<string>
#include<ctime>

using namespace std;


#define MAGIC_KEY 224
#define SPACE 32
#define MAX_N 19

enum MENU
{
    Baseball = 0,
    Omok,
    QUIT
};

enum KEYBOARD
{
    UP = 72,
    LEFT = 75,
    RIGHT = 77,
    DOWN = 80
};

//Cursor move
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//title, console size
void SetConsoleView()
{
    system("mode con:cols=60 lines=100");
    system("title Yonho_Game");
}

//-----------Draw-----------------
void DrawReadyGame()
{
    system("cls");
    gotoxy(5, 2);
    cout << "******************************";
    gotoxy(5, 3);
    cout << "*             Game           *";
    gotoxy(5, 4);
    cout << "******************************";
    gotoxy(10, 8);
    cout << "BASEBALL";
    gotoxy(10, 9);
    cout << "OMOK";
    gotoxy(10, 10);
    cout << "Quit" << endl;
}

void drawmap() {

    gotoxy(0, 0);
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            gotoxy(j, i);
            if (i == 0) {
                if (j == 0)
                    printf("┌");
                else if (j == MAX_N - 1)
                    printf("┐");
                else
                    printf("┬");
            }
            else if (j == 0) {
                if (i == MAX_N - 1)
                    printf("└");
                else
                    printf("├");
            }
            else if (j == MAX_N - 1) {
                if (i == MAX_N - 1)
                    printf("┘");
                else
                    printf("┤");
            }
            else if (i == MAX_N - 1) {
                printf("┴");
            }
            else
                printf("┼");
        }
        printf("\n");
    }

}





void visitmap(int visit[][MAX_N]) {

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            gotoxy(i , j );
            if (visit[j][i]==1) {
                cout << "○";
            }
            else if (visit[j][i] == 2) {
                cout << "●";
            }
            
      
        }
    }
}
int win(int visit[][MAX_N]) {
    int dx[] = { 0,1,1,-1 };
    int dy[] = { 1, 0, 1,1 };
    for (int x = 0; x < MAX_N; x++) {
        for (int y = 0; y < MAX_N; y++) {
            if (visit[x][y] != 0) {
                
                int focus = visit[x][y];

                for (int i=0; i < 4; i++) {
                    int cnt = 1 ;
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    while (0 <= nx && nx < MAX_N && 0 <= ny && ny < MAX_N) {
                       
                        if (visit[nx][ny] == focus) {
                            cnt++;
                            nx += dx[i];
                            ny += dy[i];
                            
                            if (cnt == 5) {
                                return 1;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}



//게임 오버 그리기
void DrawGameOver()
{
    gotoxy(8, 8);
    cout << "-------------------";
    gotoxy(8, 10);
    cout << "| G A M E O V E R |";
    
    gotoxy(8, 12);
    cout << "-------------------";
    system("pause>null");
}

//커서 움직이는것 출력
void DrawUserCursor(int& y)
{
    if (y <= 0)
    {
        y = 0;
    }
    else if (y >= 2)
    {
        y = 2;
    }

    gotoxy(9, 8 + y);
    cout << ">";
}
void DrawUserCursor(int& x,int& y, int flag)
{
    if (x <= -(MAX_N/2))
    {
        x = -(MAX_N / 2);
    }
    else if (x >= MAX_N/2)
    {
        x = (MAX_N / 2);
    }
    if (y <= -(MAX_N/2-1))
    {
        y = -(MAX_N / 2)-1;
    }
    else if (y >= MAX_N/2+1)
    {
        y = (MAX_N / 2)+1;
    }
    gotoxy((MAX_N / 2) +x, (MAX_N / 2)-1 + y);

    if (flag ==1)cout << "○";
    else cout << "●";
    
    
}


MENU ReadyGame()
{
    int y = 0;
    int input = 0;
    while (true)
    {
        DrawReadyGame();
        DrawUserCursor(y);
        input = _getch();
        //→←↑↓
        if (input == MAGIC_KEY)
        {
            switch (_getch())
            {
            case UP:
                --y;
                break;
            case DOWN:
                ++y;
                break;
            }
        }
        else if (input == SPACE)
        {
            switch (y)
            {
            case 0:
                return Baseball;
            case 1:
                return Omok;
            case 2:
                return QUIT;
            }
        }
    }
}




void baseball() {
    srand(time(NULL));
    //int num = 3;// n개의 야구게임
    //int num = rand();	// 1~25 사이의 난수
    int num = 3;
    int *Com_num=new int[num];
    int* Player_num = new int[num];
    int cnt = 1;


    for (int i = 0; i < num; i++) {
        Com_num[i] = rand() % 9 + 1;
        for (int j = 0; j < i; j++) {
            if (Com_num[i] == Com_num[j]) {
                i--;
            }
        }
    }
    while (1) {
        int cnt_strike = 0;
        int cnt_ball = 0;

        cout << "1~9 까지의 숫자 3개를 입력해주세요. (이외의 숫자 : 종료) \n";
        for (int i = 0; i < num; i++) {

            cin >> Player_num[i];

            if (Player_num[i] > 9 || Player_num[i] < 1) {
                system("cls"); 
                cout << "\n\n"<<"           게임을 종료하셨습니다.\n";

                DrawGameOver();
                return;
            }
            if (Player_num[i] == Com_num[i]) {
                cnt_strike += 1;
            }
            else {
                for (int j = 0; j < num; j++) {
                    if (Player_num[i] == Com_num[j]) {
                        cnt_ball += 1;
                    }
                }
            }

        }
    
        if (cnt_strike == num) {
            system("cls");
            cout << cnt << "번만에 맞췄습니다!!\n";
            DrawGameOver();
            return ;
        }
        cout << "Strike : " << cnt_strike << "  Ball : " << cnt_ball << "\n" << endl;

        cnt++;
    }


}


void omok() {

    int visited[MAX_N][MAX_N] = { 0, };
    int flag = 1; //1 흑돌 2 백돌
    
    int game = 2;// 2 omok
    int y = 0;
    int x = 0;
    int input = 0;
    while (true)
    {
        if (win(visited)) {
            
            if (flag == 1) {
                system("cls");
                gotoxy(((MAX_N / 2)-1), 6);
                cout << "백돌의 승리입니다.";
                DrawGameOver();
                return;
            }
            else {
                system("cls");
                gotoxy(((MAX_N / 2)-1), 6);
                cout << "흑돌의 승리입니다.";
                DrawGameOver();
                return;
            }

        }
        drawmap();

        visitmap(visited);
        DrawUserCursor(x, y, flag);
        input = _getch();
        //→←↑↓


        if (input == MAGIC_KEY)
        {
            switch (_getch())
            {
            case UP:
                --y;
                break;
            case DOWN:
                ++y;
                break;
            case RIGHT:
                ++x;
                break;
            case LEFT:
                --x;
                break;
            }
        }
        else if (input == SPACE)
        {
            if (visited[((MAX_N / 2)-1) + y][(MAX_N / 2) + x] == 0) {
                visited[((MAX_N / 2)-1) + y][(MAX_N / 2) + x] = flag;
            }
            if (flag == 1) {
                flag = 2;
            }
            else {
                flag = 1;
            }
        }
    }    
}

int main(void)
{
    SetConsoleView();
    while (true)
    {
        
        switch (ReadyGame())
        {
        case Baseball:
            system("cls");
            baseball();
            break;
        case Omok:
            system("cls");
            omok();
            break;

        case QUIT:
            return 0;
        }
    }
    return 0;
}
