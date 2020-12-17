#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
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
//#define Game_delay 5000000

#define MAX_LEVEL 3
#define depth 3 // input the total number of high score to show.

struct coordinate{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;
coordinate Head, turn[500],food,body[30];

int length;
int turn_no;
int len;
int ret;
int level;
char key;
char name[50];

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
void username(void);
void user_display(void);
char * readline(FILE *fp, char *buffer);
void update_data(void);
void display_scorecard(void);
void show_high_score_by_level(int for_level,char levelname[]);
int levelSelect(void);

#endif /* SNAKE_H_ */
