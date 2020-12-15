#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define GA_XL 5
#define GA_XR 80
#define GA_YT 5
#define GA_YB 30
#define Game_delay 5000000

void Wall (void);
void load(void);
int main_menu(void);
void instructions(void);
void gotoxy(int,int);
void GotoXY(int,int);
void Food(void);
void Delay(void);
void ExitGame(void);
int Score_display(void);
void game(void);
void Go_Down(void);
void Go_Left(void);
void Go_Up(void);
void Go_Right(void);
void Turn(void);
void Snake(void);


struct coordinate{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate Head, turn[500],food,body[30];

#endif /* SNAKE_H_ */
