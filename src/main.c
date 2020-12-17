#include "All_Variables.h"
int main()
{
	game();
	return 0;
}
int game()
{
    int i;
    if(ret)
    {
       ret=0;
       system("cls");
       turn_no = 0;
       len = 0;
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
   if(mm == 4)
		exit(0);
    else if(mm == 2){
            instructions();
            goto l1;
    }
    else if(mm==3){
        display_scorecard();
        goto l1;
    }
    else // mm = 1 i.e User wants to play game
    {
    system("cls");
    username();
    printf("\n%s",name);
    system("cls");
    level=levelSelect();
    system("cls");
    load();

    length=5;

    Head.x=25;

    Head.y=20;

    Head.direction=RIGHT;

    Wall();
    Score_display();
    user_display();

    Food(); //to generate food coordinates initially

    turn[0]=Head;

    Snake();   //initialing initial turn coordinate
    }

}
int main_menu(void){
    int ch;
    int i=3; // Max number of trials for input
    do{
        system("cls");
        printf("/////////////Welcome to the SNAKE GAME\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
        printf("               Main Menu\n");
        printf("1. Play\n");
        printf("2. Instructions\n");
        printf("3. Scorecard\n");
        printf("4. Exit\n\n\n");
        printf("    Please enter choice number : ");
        scanf(" %d",&ch);
        if(ch==1 || ch==3 || ch==2 || ch==4 )
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
    for(q=0;q<=10000000;q++);//to display the character slowly
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
void Wall()
{
   system("cls");
   int i;
   GotoXY(food.x,food.y);   /*displaying food*/
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
void Food()
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
        user_display();

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
void Delay()
{
    long double i;
    int level_wise_delays[]={5000000,5000000,50000000};//Change If you add new levels or delete existing levels
    for(i=0;i<=(level_wise_delays[level-1]);i++);// to slow down the game play
}
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
int Score_display()
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

void ExitGame()
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
    if(Head.x<=GA_XL||Head.x>=GA_XR||Head.y<=GA_YT||Head.y>=GA_YB||(level==2 && Head.x>=24 && Head.x<=56 && (Head.y==11 || Head.y==24)) || (level==3 && Head.x>=25 && Head.x<=60 && (Head.y==10 || Head.y==23))|| (level==3 && Head.y>=15 && Head.y<=18 && (Head.x==18 || Head.x==67))||check!=0)
    {
            system("cls");
            printf("GAME OVER!!! You crashed... :(\n");
            printf("Your score is %d\n",(length-5));

            update_data();
            printf("Press any key to return to Main Menu\n");
            getch();
            ret = 1;
            game();

    }
}

void username(){
printf("\nEnter Player Name: ");
scanf("%s",&name);

}

void user_display()
{

   GotoXY(GA_XR/2 -20,GA_YT-1);
   printf("user:%s",name);

}
char * readline(FILE *fp, char *buffer)
{
    int ch;
    int i = 0;
    size_t buff_len = 0;

    buffer = malloc(buff_len + 1);
    if (!buffer) return NULL;  // Out of memory

    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
    {
        buff_len++;
        void *tmp = realloc(buffer, buff_len + 1);
        if (tmp == NULL)
        {
            free(buffer);
            return NULL; // Out of memory
        }
        buffer = tmp;

        buffer[i] = (char) ch;
        i++;
    }
    buffer[i] = '\0';

    // Detect end
    if (ch == EOF && (i == 0 || ferror(fp)))
    {
        free(buffer);
        return NULL;
    }
    return buffer;
}
void update_data(){
    int MAX=255;
    FILE * fp1;
    FILE * fp2;

    char temp[] = "temp.txt";
    char src[] = "data.txt";
    fp1 = fopen(src, "r");
    fp2= fopen(temp, "w");
    if (fp1 == NULL || fp2==NULL)
        exit(EXIT_FAILURE);
    //current_line=0;


    int finding_name_flag=1;
    char *s;
    while ((s = readline(fp1, 0)) != NULL)
    {
    char ds[MAX];

    strcpy(ds,s);
    //printf("%s",ds);
    char * token = strtok(s, " ");
    //comparing names of players
    if(strcmp(token,name)==0 && finding_name_flag==1){
        //#define MAX_LEVEL 3
        int player_scores[MAX_LEVEL]={0};
        int changed=0;
        for(int i=0;i<MAX_LEVEL;i++){
            token = strtok(NULL, " ");

            if (token!=NULL){
                int x = atoi(token);

                if(i==(level-1) && (length-5)>x){
                    player_scores[i]=length-5;
                    changed=1;
                }
                else{
                    player_scores[i]=x;
                }
            }
            else{
                system("cls");
                printf("Invalid Entry Found while storing Data");
                fclose(fp1);
                fclose(fp2);
                //remove(temp) Should be added after testing
                exit(1);
            }


        }

        //checking if current score is higher
        if(changed==1){
            char newln[MAX];
            strncpy(newln, "", sizeof(newln));
            strcat(newln,name);
            for(int i=0;i<MAX_LEVEL;i++){
                strcat(newln," ");
                char snum[8];//Below conversion depends on this
                itoa(player_scores[i],snum,10);
                strcat(newln,snum);
            }

            fprintf(fp2, "%s", newln);

        }
        else{
            fprintf(fp2, "%s", ds);

        }
        finding_name_flag=0;
    }
    else{
        fprintf(fp2, "%s", ds);
    }


    //puts(s);
    free(s);free(ds);
    fprintf(fp2,"\n");
    //printf("\n");
    }

    if (finding_name_flag==1){
        char newln[MAX];
        strncpy(newln, "", sizeof(s));
        strcat(newln,name);

        //#define MAX_LEVEL 3
        int player_scores[MAX_LEVEL]={0};
        player_scores[level-1]=length-5;
        for(int i=0;i<MAX_LEVEL;i++){
                strcat(newln," ");
                char snum[8];//Below conversion depends on this
                itoa(player_scores[i],snum,10);
                strcat(newln,snum);
            }

        fprintf(fp2, "%s", newln);

    }
    fclose(fp1);
    fclose(fp2);
    remove(src);
    rename(temp, src);

}
void display_scorecard()
{
    system("cls");
    printf("\t\tScorecard:\n");

    show_high_score_by_level(1,"Easy");
    show_high_score_by_level(2,"Medium");
    show_high_score_by_level(3,"Hard");

    printf("\n\n\nPress any key to return to Main Menu...");
    getch();
}
void show_high_score_by_level(int for_level,char levelname[]){

    printf("\n\nLevel-%s\n",levelname);
    int MAX=255;
    FILE * fp1;



    char src[] = "data.txt";
    fp1 = fopen(src, "r");


    if (fp1 == NULL)
        exit(EXIT_FAILURE);
    //current_line=0;

    int indices[depth]={0};



    for (int i=0;i<depth;i++){
    fseek(fp1, 0, SEEK_SET);

    char bestPlayer[MAX];
    int bestScore=-9999;
    int finding_name_flag=0;
    int currentIndex=0;

    char *s;
    int line=0;
    while ((s = readline(fp1, 0)) != NULL)
    {   line++;

        int reject=0;
        for (int j=0;j<i;j++){
                //printf("\n%d ,,,%d\n",indices[j],line);
            if (line==indices[j]){
                free(s);
                reject=1;
                break;

            }
        }
        if (reject){
            continue;
        }

        char currentName[MAX];
        char * token = strtok(s, " ");
        strcpy(currentName,token);

        int extract=for_level;
        while(extract--){
            token = strtok(NULL, " ");
        }

        int currentScore = atoi(token);

        if (currentScore>bestScore){
            strcpy(bestPlayer,currentName);
            bestScore=currentScore;
            indices[i]=line;
            finding_name_flag=1;
        }
        free(s);free(currentName);
    }
    if(finding_name_flag==1){
        printf("\n %s : %d",bestPlayer,bestScore);
    }
    }
    fclose(fp1);
}
