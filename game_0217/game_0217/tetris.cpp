#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include<string>
#include<ctime>

using namespace std;


#define MAGIC_KEY 224
#define SPACE 32
#define MAX_N 20

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




void drawmap_tetris() {

    gotoxy(0, 0);
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            gotoxy(j, i);
            if (i == 0) {
                if (j == 0)
                    printf("¦£");
                else if (j == MAX_N - 1)
                    printf("¦¤");
                else
                    printf("¦¡");
            }
            else if (j == 0) {
                if (i == MAX_N - 1)
                    printf("¦¦");
                else
                    printf("¦¢");
            }
            else if (j == MAX_N - 1) {
                if (i == MAX_N - 1)
                    printf("¦¥");
                else
                    printf("¦¢");
            }
            else if (i == MAX_N - 1) {
                printf("¦¡");
            }

        }
        printf("\n");
    }

}

void block(int shape) {

    gotoxy(MAX_N / 2, 0);


    switch (shape) {
    case 0:
        cout << "¡á¡á¡á¡á";
        break;
    case 1:
        cout << "¡á¡á";
        gotoxy(MAX_N / 2, 1);
        cout << "¡á¡á";
        break;
    case 2:
        cout << "¡á¡á";
        gotoxy(MAX_N / 2 + 1, 1);
        cout << "¡á¡á";
        break;
    case 3:
        cout << "¡á";
        gotoxy(MAX_N / 2 - 1, 1);
        cout << "¡á¡á¡á";
        break;
    case 4:
        cout << "¡á";
        gotoxy(MAX_N / 2, 1);
        cout << "¡á¡á¡á";
        break;
    }
}

void visitmap(int visit[][MAX_N]) {

    for (int i = 0; i < MAX_N; i++) {// ¿­
        for (int j = 0; j < MAX_N; j++) {//Çà
            gotoxy(i, j);
            if (visit[j][i] == 1) {
                cout << "¡á";
            }
        }
    }
}


void block(int&x,int&y,int shape) {

    gotoxy(MAX_N / 2 + x, 0 + y);


    switch (shape) {
    case 0:
        cout << "¡á¡á¡á¡á";
        break;
    case 1:
        cout << "¡á¡á";
        gotoxy(MAX_N / 2 + x, 1 + y);
        cout << "¡á¡á";
        break;
    case 2:
        cout << "¡á¡á";
        gotoxy(MAX_N / 2 + 1 + x, 1 + y);
        cout << "¡á¡á";
        break;
    case 3:
        cout << "¡á";
        gotoxy(MAX_N / 2 - 1 + x, 1 + y);
        cout << "¡á¡á¡á";
        break;
    case 4:
        cout << "¡á";
        gotoxy(MAX_N / 2 + x, 1 + y);
        cout << "¡á¡á¡á";
        break;
    }
}

void DrawUserCursor(int& x, int& y, int shape)
{
    if (x <= -(MAX_N / 2))
    {
        x = -(MAX_N / 2);
    }
    else if (x >= MAX_N / 2)
    {
        x = (MAX_N / 2);
    }
    if (y <= 1)
    {
        y = 1;
    }
    else if (y >= MAX_N )
    {
        y = MAX_N ;
    }
    gotoxy((MAX_N / 2) + x,   y);

    block(x, y, shape);
}
    






int main(void)
{
    int visited[MAX_N][MAX_N] = { 0, };
    srand(time(NULL));
    int shape;


    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            if (i == MAX_N - 1) {
                visited[i][j] = 3;
            }
        }    
    }
    
    
    while (true) {
        int input = 0, x = 0, y = 0;
        
        shape = 0;
            //rand() % 5;
        block(shape);
        while (true) {
            visitmap(visited);
            input = _getch();

            if (input == MAGIC_KEY)
            {
                system("cls");
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

            if (visited[y][ x] == 0) {
                DrawUserCursor(x, y, shape);

            }
            else {
                switch (shape) {
                case 0:
                    for (int i = 0; i < 4; i++) {
                        visited[y][(MAX_N / 2) + x+i] = 1;
                    }
                    
                    //cout << "¡á¡á¡á¡á";
                    break;
                case 1:
                    visited[((MAX_N / 2) - 1) + y, 2][(MAX_N / 2) + x, 2] = 1;
                    /*cout << "¡á¡á";
                    gotoxy(MAX_N / 2 + x, 1 + y);
                    cout << "¡á¡á";*/
                    break;
                case 2:
                    visited[((MAX_N / 2) - 1) + y][(MAX_N / 2) + x, 2] = 1;
                    /*cout << "¡á¡á";
                    gotoxy(MAX_N / 2 + 1 + x, 1 + y);
                    cout << "¡á¡á";*/
                    visited[((MAX_N / 2) - 1) + y + 1][(MAX_N / 2) + x + 1, 2] = 1;
                    break;
                case 3:
                    visited[((MAX_N / 2) - 1) + y][(MAX_N / 2) + x] = 1;

                    /* cout << "¡á";
                     gotoxy(MAX_N / 2 - 1 + x, 1 + y);
                     cout << "¡á¡á¡á";*/
                    visited[((MAX_N / 2) - 1) + y + 1][(MAX_N / 2) + x - 1, 3] = 1;
                    break;
                case 4:
                    visited[((MAX_N / 2) - 1) + y][(MAX_N / 2) + x] = 1;
                    /*cout << "¡á";
                    gotoxy(MAX_N / 2 + x, 1 + y);
                    cout << "¡á¡á¡á";*/
                    visited[((MAX_N / 2) - 1) + y][(MAX_N / 2) + x - 1, 3] = 1;
                    break;
                }
                break;
            }


        }
    }
    
    cout << "snvjankv";
}
