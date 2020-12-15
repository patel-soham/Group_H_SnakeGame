#include "snake.h"

int main(void){
	return 0;
}

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

void load(){
    int r,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=30;r++){
    for(q=0;q<=10000000;q++);
    printf("%c",177);}
}
void instructions()
{
    system("cls");
    printf("/////////////Welcome to the SNAKE GAME\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
    printf("\t\tInstructions:\n");
    printf("\n-> Use arrow keys to navigate the snake.\n\n-> Food is provided at various locations of the screen which you have to eat.\n\n-> Eating the food increases the length of the snake by 1 element and also the score.\n\n-> Your GAME will finish as you hit the wall or snake's body.\n\n-> Game can be paused in middle by pressing any key and will continued by pressing any key once again\n\n-> Game can be exited by pressing esc. \n");
    printf("\n\nPress any key to return main menu...");
    getch();
}

void gotoxy(int x, int y)
{

 COORD temp;

 temp.X = x;

 temp.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);

}
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

void Delay(void)
{
    long double i;
    for(i=0;i<=(Game_delay);i++);// to slow down the game play
}

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
