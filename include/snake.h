#ifndef SNAKE_H_
#define SNAKE_H_

/**
* Contains all header files and functions required for the project.
*/

/*Includes the basic header files and libraries*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

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
#define Game_delay 5000000

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

coordinate Head, turn[500],food,body[30];

/* Declaring Global variables */
int length;
int turn_no;
int len;
char key;
int ret;

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
void Wall (void);

/**  @brief Function prototype to add food in the play area.
*
* This Function places food at random places within the play area.
*
*/
void Food(void);

/**  @brief Function prototype calls other functions to move the snake.
*
* This Function manages the overall movement of the snake.
*
*/
void Snake(void);

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
void GotoXY(int,int);

/**  @brief Function prototype to control the game play speed.
*
* This Function controls the speed of the snake in various levels.
*
*/
void Delay(void);

/**  @brief Function prototype to set the movement.
*
* This Function controls the UP side movement.
*
*/
void Go_Up(void);

/**  @brief Function prototype to set the movement.
*
* This Function controls the DOWN side movement.
*
*/
void Go_Down(void);

/**  @brief Function prototype to set the movement.
*
* This Function controls the LEFT side movement.
*
*/
void Go_Left(void);

/**  @brief Function prototype to set the movement.
*
* This Function controls the RIGHT side movement.
*
*/
void Go_Right(void);

/**  @brief Function prototype to turn.
*
* This Function controls movement.
*
*/
void Turn(void);

/**  @brief Function prototype to print the live score.
*
* This Function displays the score while in the game.
*
*/
int Score_display(void);

/**  @brief Function prototype to exit the game.
*
* This Function displays the exit menu and final score of that game.
*
*/
void ExitGame(void);

/**  @brief Function prototype to input the Player name.
*
* This Function asks the user to enter the name.
*
*/

#endif /* SNAKE_H_ */
