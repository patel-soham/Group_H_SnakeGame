/**
* @file snake.c
*
* Author          : Aditi Biswas 101193708
*                   Tharun Merapala 101192727
*   	            Soham Patel 101184663
*                   Siddharth Ashish Upadhyaya 101207911
* GitHub ID       : aditi-21, tharunmerapala, patel-soham, Siddharth-104.
* Repository link : https://github.com/patel-soham/Group_H_SnakeGame.git
* Language        : C
*
*/

/* Includes the header file */
#include "../include/snake.h"

/**
* @brief Initializing global variable and runs the 'game' function.
*/
int main(void){
	game();
	return 0;
}

/**
* @brief This function calls the major functions and helps in the actual game play.
*
* The game flow is taken care of here.
*
*/
void game(void)
{
    int i;
    if(ret ==1)
    {
       system("cls");
       turn_no = 0;
       len =0;
       for(i=0;i<500;i++)
       {
           turn[i].x =0;
           turn[i].y =0;
           turn[i].direction =0;
       }
       for(i=0;i<30;i++)
       {
           body[i].x =0;
           body[i].y =0;
           body[i].direction =0;
       }
    }
   int mm;
   l1:mm = main_menu();
   if(mm == 3)
		exit(0);
    else if(mm == 2){
            instructions();
            goto l1;
    }

    else 
    {
    system("cls");

    load();

    length=5;

    Head.x=25;

    Head.y=20;

    Head.direction=RIGHT;

    Wall();
    Score_display();

    Food(); 

    turn[0]=Head;

    Snake();   
    }

}

/**
* @brief Function displays the Walls for the play area and
* the Obstacles within it depending upon the various levels.
*
*/
void Wall(void)
{
   system("cls");
   int i;
   GotoXY(food.x,food.y); 
       printf("O");
   for(i=GA_XL;i<=GA_XR;i++)
   {
       GotoXY(i,GA_YT);
           printf("%c",176);
       GotoXY(i,GA_YB);
           printf("%c",176);
   }
   for(i=GA_YT+1;i<=GA_YB;i++)
   {
       GotoXY(GA_XL,i);
           printf("%c",176);
       GotoXY(GA_XR,i);
       printf("%c",176);
   }
}

/**
* @brief The function displays the game's main menu.
*
* @param[out] option The user selected choice.
*
*/
int main_menu(void){
    int ch;
    int i=3; 
    do{
        system("cls");
        printf("/////////////Welcome to the SNAKE GAME\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
        printf("               Main Menu\n");
        printf("1. Play\n");
        printf("2. Instructions\n");
        printf("3. Exit\n\n\n");
        printf("    Please enter choice number : ");
        scanf(" %d",&ch);
        if(ch==1 || ch==3 || ch==2)
            return ch;
    }while(i--);
    system("cls");
    printf("\n\tGame exit because of consecutive invalid inputs!\n\n");
    exit(0);
}

/**
* @brief Function prints the loading screen.
*/
void load(){
    int r,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=30;r++){
    for(q=0;q<=10000000;q++);
    printf("%c",177);}
}

/**
* @brief Function prints the game play instructions for the User.
*/
void instructions()
{
    system("cls");
    printf("/////////////Welcome to the SNAKE GAME\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
    printf("\t\tInstructions:\n");
    printf("\n-> Use arrow keys to navigate the snake.\n\n-> Food is provided at various locations of the screen which you have to eat.\n\n-> Eating the food increases the length of the snake by 1 element and also the score.\n\n-> Your GAME will finish as you hit the wall or snake's body.\n\n-> Game can be paused in middle by pressing any key and will continued by pressing any key once again\n\n-> Game can be exited by pressing esc. \n");
    printf("\n\nPress any key to return main menu...");
    getch();
}

/**
* @brief Function places cursor at given coordinate position and takes Input parameters as x-coordinate and y-coordinate
*
* @param[in] x X-coordinate
* @param[in] y Y-coordinate
*/
void gotoxy(int x, int y)
{

 COORD temp;

 temp.X = x;

 temp.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);

}

/**
* @brief Function places cursor at given coordinate position and takes Input parameters as x-coordinate and y-coordinate
*
* @param[in] x X-coordinate
* @param[in] y Y-coordinate
*/
void GotoXY(int x, int y) // to avoid game lag issues
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }

/**
* @brief Function controls the speed of the snake in various levels.
* Depending upon the levels, we have defined different speed for each which can be changed by the developer.
*/
void Delay(void)
{
    long double i;
    for(i=0;i<=(Game_delay);i++);// to slow down the game play
}

/**
* @brief Function places food at random places within the play area.
* There will be only one Food at a particular moment.
*/
void Food(void)
{
    if(Head.x==food.x&&Head.y==food.y)
    {
        length++;
        food.x=rand()%GA_XR;
        if(food.x<=GA_XL)
            food.x+=11;
        food.y=rand()%GA_YB;
        if(food.y<=GA_YT)
            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time */
    {
        food.x=rand()%GA_XR;
        if(food.x<=GA_XL)
            food.x+=11;
        food.y=rand()%GA_YB;
        if(food.y<=GA_YT)
            food.y+=11;
    }
}

/**
* @brief Function displays the score while in the game at the top.
*
* @param[out] score Current game score
*/
int Score_display(void)
{
   int score;
   GotoXY(GA_XR/2 -5,GA_YT-1);
   score=length-5;
   if(score>=0)
    printf("SCORE : %d",score);
   else
    printf("INVALID SCORE ");
   score=length-5;
   return score;
}

/**
* @brief Function displays the exit menu and final score of that game.
* The game will be exited, when the snake hits the Wall, Obstacles or even itself.
*/
void ExitGame(void)
{
    int i,check=0;
    for(i=4;i<length;i++)   //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of Head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(Head.x<=GA_XL||Head.x>=GA_XR||Head.y<=GA_YT||Head.y>=GA_YB||check!=0)
    {

            system("cls");
            printf("GAME OVER!!! You crashed... :(\n");
            printf("Your high score is %d\n",(length-5));
            printf("Press any key to return to Main Menu\n");
            getch();
            ret = 1;
            //Loop_main();
            game();

    }
}

/**
* @brief Function controls the UP side movement of the Snake.
*/
void Go_Up()
{
   int i;
   for(i=0;i<=(turn[turn_no].y-Head.y)&&len<length;i++)
   {
       GotoXY(Head.x,Head.y+i);
       {
           if(len==0)
               printf("^");
           else
               printf("*");
       }
       body[len].x=Head.x;
       body[len].y=Head.y+i;
       len++;
   }
   Turn();
   if(!kbhit())
       Head.y--;
}

/**
* @brief Function controls the DOWN side movement of the Snake.
*/
void Go_Down()
{
    int i;
    for(i=0;i<=(Head.y-turn[turn_no].y)&&len<length;i++)
    {
        GotoXY(Head.x,Head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=Head.x;
        body[len].y=Head.y-i;
        len++;
    }
    Turn();
    if(!kbhit())
        Head.y++;
}

/**
* @brief Function controls the LEFT side movement of the Snake.
*/
void Go_Left()
{
    int i;
    for(i=0;i<=(turn[turn_no].x-Head.x)&&len<length;i++)
    {
        GotoXY((Head.x+i),Head.y);
       {
                if(len==0)
                    printf("<");
                else
                    printf("*");
        }
        body[len].x=Head.x+i;
        body[len].y=Head.y;
        len++;
    }
    Turn();
    if(!kbhit())
        Head.x--;

}

/**
* @brief Function controls the Right side movement of the Snake.
*/
void Go_Right()
{
    int i;
    for(i=0;i<=(Head.x-turn[turn_no].x)&&len<length;i++)
    {
        //GotoXY((Head.x-i),Head.y);
        body[len].x=Head.x-i;
        body[len].y=Head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        /*body[len].x=Head.x-i;
        body[len].y=Head.y;*/
        len++;
    }
    Turn();
    if(!kbhit())
        Head.x++;
}
/**
* @brief Function controls the turn movements of the Snake.
*/
void Turn()
{
    int i,j,diff;
    for(i=turn_no;i>=0&&len<length;i--)
    {
            if(turn[i].x==turn[i-1].x)
            {
                diff=turn[i].y-turn[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)
                    {
                        body[len].x=turn[i].x;
                        body[len].y=turn[i].y+j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)
                    {
                        /*GotoXY(turn[i].x,(turn[i].y-j));
                        printf("*");*/
                        body[len].x=turn[i].x;
                        body[len].y=turn[i].y-j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
            }
        else if(turn[i].y==turn[i-1].y)
        {
            diff=turn[i].x-turn[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&len<length;j++)
                {
                    /*GotoXY((turn[i].x+j),turn[i].y);
                    printf("*");*/
                    body[len].x=turn[i].x+j;
                    body[len].y=turn[i].y;
                    GotoXY(body[len].x,body[len].y);
                        printf("*");
                   len++;
                   if(len==length)
                           break;
               }
           else if(diff>0)
               for(j=1;j<=diff&&len<length;j++)
               {
                   /*GotoXY((turn[i].x-j),turn[i].y);
                   printf("*");*/
                   body[len].x=turn[i].x-j;
                   body[len].y=turn[i].y;
                   GotoXY(body[len].x,body[len].y);
                       printf("*");
                   len++;
                   if(len==length)
                       break;
               }
       }
   }
}

/**
* @brief Function manages the overall movement of the snake.
* It also call the other functions for the movement.
*/
void Snake()
{
    int a,i;

    do{

        Food();
        fflush(stdin);

        len=0;

        for(i=0;i<30;i++)

        {

            body[i].x=0;

            body[i].y=0;

            if(i==length)

            break;

        }

        Delay();

        Wall();
        Score_display();

        if(Head.direction==RIGHT)

            Go_Right();

        else if(Head.direction==LEFT)

            Go_Left();

        else if(Head.direction==DOWN)

            Go_Down();

        else if(Head.direction==UP)

            Go_Up();

        ExitGame();

    }while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    key=getch();

    if((key==RIGHT&&Head.direction!=LEFT&&Head.direction!=RIGHT)||(key==LEFT&&Head.direction!=RIGHT&&Head.direction!=LEFT)||(key==UP&&Head.direction!=DOWN&&Head.direction!=UP)||(key==DOWN&&Head.direction!=UP&&Head.direction!=DOWN))

    {

        turn_no++;

        turn[turn_no]=Head;

        Head.direction=key;

        if(key==UP)

            Head.y--;

        if(key==DOWN)

            Head.y++;

        if(key==RIGHT)

            Head.x++;

        if(key==LEFT)

            Head.x--;

        Snake();

    }

    else if(key==27)

    {

        system("cls");

        exit(0);

    }

    else

    {

        printf("\a");// for making beep sound

        Snake();

    }
}
