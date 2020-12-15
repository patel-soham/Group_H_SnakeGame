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
