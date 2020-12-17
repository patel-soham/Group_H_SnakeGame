#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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
#define MAX_LEVEL 3
#define DEPTH 3 // input the total number of high score to show.
//#define Game_delay 5000000

struct coordinate{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;
coordinate Head, turn[500],food_location,body[30];

int length;
int turn_no;
int len;
int flg;
int level;
char key;
char name[50];

void game(void);
int main_menu(void);
void load(void);
void instructions(void);
void wall (void);
void food(void);
void snake(void);
void gotoxy(int,int);
void goto_xy(int,int);
void delay(void);
void go_up(void);
void go_down(void);
void go_left(void);
void go_right(void);
void steer(void);
int score_display(void);
void exit_game(void);
void username(void);
void user_display(void);
char * read_line(FILE *fp, char *buffer);
void update_data(void);
void display_scorecard(void);
void show_high_score_by_level(int for_level,char levelname[]);
int level_select(void);

#endif /* SNAKE_H_ */
