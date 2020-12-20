#ifndef SNAKE_H_
#define SNAKE_H_

/**
* Contains all header files and functions required for the project.
*/

/*Includes the basic header files and libraries*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>
// new libraries
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>

/**
* @brief Macros constants defined that are used throughout the code.
*
* These defined constants are used for soft coding.
*
*/

/* Macros Definition */
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define GA_XL 5
#define GA_XR 80
#define GA_YT 5
#define GA_YB 30
#define MAX_LEVEL 3
/* Input the total number of high score to show */
#define DEPTH 3

/**  @brief Structure define to store coordinates and direction.
*
*/
struct coordinate{
    int x;
    int y;
    int direction;
};

/* Declaring structure variables */
typedef struct coordinate coordinate;
coordinate Head, turn[500],food_location,body[30];

/* Declaring Global variables */
int length;
int turn_no;
int len;
int flg;
int level;
char key;
char name[50];
char buffer[1];//new

/**  @brief Function prototype to call the major functions and helps in the game play.
*
*  The actual game works here.
*
*/
void game(void);

/**  @brief Function prototype to print main menu.
*
* This Function displays the various options for the user to select.
*
*/
int main_menu(void);

/**  @brief Function prototype to print the loading screen.
*
*/
void load(void);

/**  @brief Function prototype to print insructions
*
* This Function prints the game play instructions for the User.
*
*/
void instructions(void);

/**  @brief Function prototype to display the defined boundary.
*
* This Function displays the walls for the play area and the obstacles within it.
*
*/
void wall (void);

/**  @brief Function prototype to add food in the play area.
*
* This Function places food at random places within the play area.
*
*/
void food(void);

/**  @brief Function prototype calls other functions to move the snake.
*
* This Function manages the overall movement of the snake.
*
*/
void snake(void);

/**  @brief Function prototype to move the cursor to specific position
*
* This Function places cursor at given coordinate position and takes Input parameters as x-coordinate and y-coordinate
*
*/
void gotoxy(int,int);

/**  @brief Function prototype to move the cursor to specific position
*
* This Function places cursor at given coordinate position and takes Input parameters as x-coordinate and y-coordinate
*
*/
void goto_xy(int,int);

/**  @brief Function prototype to control the game play speed.
*
* This Function controls the speed of the snake in various levels.
*
*/
void delay(void);

/**  @brief Function prototype to set the movement.
*
* This Function controls the UP side movement.
*
*/
void go_up(void);

/**  @brief Function prototype to set the movement.
*
* This Function controls the DOWN side movement.
*
*/
void go_down(void);

/**  @brief Function prototype to set the movement.
*
* This Function controls the LEFT side movement.
*
*/
void go_left(void);

/**  @brief Function prototype to set the movement.
*
* This Function controls the RIGHT side movement.
*
*/
void go_right(void);

/**  @brief Function prototype to turn.
*
* This Function controls movement.
*
*/
void steer(void);

/**  @brief Function prototype to print the live score.
*
* This Function displays the score while in the game.
*
*/
int score_display(void);

/**  @brief Function prototype to exit the game.
*
* This Function displays the exit menu and final score of that game.
*
*/
void exit_game(void);

/**  @brief Function prototype to input the Player name.
*
* This Function asks the user to enter the name.
*
*/
void username(void);

/**  @brief Function prototype prints the User name in the game.
*
* This Function displays the Player name while in the game.
*
*/
void user_display(void);

/**  @brief Function prototype to read score data.
*
* This Function reads the score from the score data file.
*
*/
char * read_line(FILE *fp, char *buffer);

/**  @brief Function prototype to write score data.
*
* This Function writes the new score to the score data file.
*
*/
void update_data(void);

/**  @brief Function prototype to print the levels to display score.
*
* This Function displays the various levels for highscore.
*
*/
void display_scorecard(void);

/**  @brief Function prototype to print the score data.
*
* This Function displays the High Score from the score data file by levels.
*
*/
void show_high_score_by_level(int for_level,char levelname[]);

/**  @brief Function prototype to print the levels.
*
* This Function displays the various levels for the user to play.
*
*/
int level_select(void);

int kbhit(void);
int getch(void);
char getch_(int);

#endif /* SNAKE_H_ */
