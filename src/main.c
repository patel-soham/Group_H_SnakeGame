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
    length=0;
    turn_no=0;
    len=0;
    flg=0;
    level=0;
    game();
    return 0;
}

/**
* @brief This function calls the major functions and helps in the actual game play.
*
* The game flow is taken care of here.
*
*/
void game(void){
    int i;
    if(flg==1){
       flg=0;
       system("cls");
       turn_no = 0;
       len = 0;
       for(i=0;i<500;i++){
           turn[i].x =0;
           turn[i].y =0;
           turn[i].direction =0;
       }
       for(i=0;i<30;i++){
           body[i].x =0;
           body[i].y =0;
           body[i].direction =0;
       }
    }
    int option;
    l1:option = main_menu();
    if(option==4){
        exit(0);
    }
    else if(option==2){
        instructions();
        goto l1;
    }
    else if(option==3){
        display_scorecard();
        goto l1;
    }
    /* option = 1, i.e User wants to play game */
    else{
        system("cls");
        username();
        printf("\n%s",name);
        system("cls");
        level=level_select();
        system("cls");
        load();
        length=5;
        Head.x=25;
        Head.y=20;
        Head.direction=RIGHT;
        wall();
        score_display();
        user_display();
        /* Generates food coordinates initially */
        food();
        /* Initialing starting turn coordinate */
        turn[0]=Head;
        snake();
    }
}

/**
* @brief The function displays the game's main menu.
*
* @param[out] option The user selected choice.
*
*/
int main_menu(void){
    int option;
    /* Max number of trials for the invalid input by the user */
    int max_trials=3;
    do{
        system("cls");
        printf("/////////////Welcome to the SNAKE GAME\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
        printf("               Main Menu\n");
        printf("1. Play\n");
        printf("2. Instructions\n");
        printf("3. Scorecard\n");
        printf("4. Exit\n\n\n");
        printf("    Please enter choice number : ");
        scanf(" %d",&option);
        if(option==1 || option==3 || option==2 || option==4 ){
            return option;
        }
    }while(max_trials--);
    system("cls");
    printf("\n\tGame exit because of consecutive invalid inputs!\n\n");
    exit(0);
}

/**
* @brief Function prints the loading screen.
*/
void load(void){
    int r,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=30;r++){
        for(q=0;q<=10000000;q++);
        printf("%c",177);
    }
}

/**
* @brief Function prints the game play instructions for the User.
*/
void instructions(void){
    system("cls");
    printf("/////////////Welcome to the SNAKE GAME\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
    printf("\t\tInstructions:\n");
    printf("\n-> Use arrow keys to navigate the snake.\n\n-> Food is provided at various locations of the screen which you have to eat.\n\n-> Eating the food increases the length of the snake by 1 element and also the score.\n\n-> Your GAME will finish as you hit the wall or snake's body.\n\n-> Game can be paused in middle by pressing any key and will continued by pressing any key once again\n\n-> Game can be exited by pressing esc. \n");
    printf("\n\nPress any key to return main menu...");
    getch();
}

/**
* @brief Function displays the Walls for the play area and
* the Obstacles within it depending upon the various levels.
*
*/
void wall(void){
    system("cls");
    int i;
    /* Displaying Food */
    goto_xy(food_location.x,food_location.y);
    printf("O");
    for(i=GA_XL;i<=GA_XR;i++){
        goto_xy(i,GA_YT);
        printf("%c",176);
        goto_xy(i,GA_YB);
        printf("%c",176);
    }
    for(i=GA_YT+1;i<=GA_YB;i++){
        goto_xy(GA_XL,i);
        printf("%c",176);
        goto_xy(GA_XR,i);
        printf("%c",176);
    }
    /* Design for level 2 */
    if(level==2){
        for(i=24;i<=56;i++){
            goto_xy(i,11);
            printf("%c",'$');
            goto_xy(i,24);
            printf("%c",'$');
        }
    }
    /* Design for level 3 */
    if(level==3){
        for(i=25;i<=60;i++){
            goto_xy(i,10);
            printf("%c",'$');
            goto_xy(i,23);
            printf("%c",'$');
        }
        for(i=15;i<=18;i++){
            goto_xy(18,i);
            printf("%c",'$');
            goto_xy(67,i);
            printf("%c",'$');
        }
    }
}

/**
* @brief Function places food at random places within the play area.
* There will be only one Food at a particular moment.
*/
void food(void){
    l2:
    if(Head.x==food_location.x&&Head.y==food_location.y){
        length++;
        food_location.x=rand()%GA_XR;
        if(food_location.x<=GA_XL){
            food_location.x+=11;
        }
        food_location.y=rand()%GA_YB;
        if(food_location.y<=GA_YT){
            food_location.y+=11;
        }
    }
    /* To create food for the first time */
    else if(food_location.x==0){
        food_location.x=rand()%GA_XR;
        if(food_location.x<=GA_XL){
            food_location.x+=11;
        }
        food_location.y=rand()%GA_YB;
        if(food_location.y<=GA_YT){
            food_location.y+=11;
        }
    }
    if ((level==2 && food_location.x>=24 && food_location.x<=56 && (food_location.y==11 || food_location.y==24)) || (level==3 && food_location.x>=25 && food_location.x<=60 && (food_location.y==10 || food_location.y==23))|| (level==3 && food_location.y>=15 && food_location.y<=18 && (food_location.x==18 || food_location.x==67))){
        goto l2;
    }
}

/**
* @brief Function manages the overall movement of the snake.
* It also call the other functions for the movement.
*/
void snake(void){
    int ch,i;
    do{
        food();
        fflush(stdin);
        len=0;
        for(i=0;i<30;i++){
            body[i].x=0;
            body[i].y=0;
            if(i==length){
                break;
            }
        }
        delay();
        wall();
        score_display();
        user_display();
        if(Head.direction==RIGHT){
            go_right();
        }
        else if(Head.direction==LEFT){
            go_left();
        }
        else if(Head.direction==DOWN){
            go_down();
        }
        else if(Head.direction==UP){
            go_up();
        }
        exit_game();
    }while(!kbhit());
    ch=getch();
    if(ch==27){
        system("cls");
        exit(0);
    }
    key=getch();
    if((key==RIGHT&&Head.direction!=LEFT&&Head.direction!=RIGHT)||(key==LEFT&&Head.direction!=RIGHT&&Head.direction!=LEFT)||(key==UP&&Head.direction!=DOWN&&Head.direction!=UP)||(key==DOWN&&Head.direction!=UP&&Head.direction!=DOWN)){
        turn_no++;
        turn[turn_no]=Head;
        Head.direction=key;
        if(key==UP){
            Head.y--;
        }
        if(key==DOWN){
            Head.y++;
        }
        if(key==RIGHT){
            Head.x++;
        }
        if(key==LEFT){
            Head.x--;
        }
        snake();
    }
    else if(key==27){
        system("cls");
        exit(0);
    }
    /* For making the Beep sound */
    else{
        printf("\a");
        snake();
    }
}

/**
* @brief Function places cursor at given coordinate position and takes Input parameters as x-coordinate and y-coordinate
*
* @param[in] x X-coordinate
* @param[in] y Y-coordinate
*/
void gotoxy(int x, int y){
    COORD temp;
    temp.X = x;
    temp.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),temp);
}

/**
* @brief Function places cursor at given coordinate position and takes Input parameters as x-coordinate and y-coordinate
*
* @param[in] x X-coordinate
* @param[in] y Y-coordinate
*/
void goto_xy(int x, int y){
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
void delay(void){
    long double i;
    /* Change if adding new levels or to change speeds for the levels */
    int level_wise_delays[]={8000000,9000000,10000000};
    for(i=0;i<=(level_wise_delays[level-1]);i++);
}

/**
* @brief Function controls the UP side movement of the Snake.
*/
void go_up(void){
    int i;
    for(i=0;i<=(turn[turn_no].y-Head.y)&&len<length;i++){
        goto_xy(Head.x,Head.y+i);
        if(len==0){
            printf("^");
        }
        else{
            printf("*");
        }
        body[len].x=Head.x;
        body[len].y=Head.y+i;
        len++;
    }
    steer();
    if(!kbhit()){
        Head.y--;
    }
}

/**
* @brief Function controls the DOWN side movement of the Snake.
*/
void go_down(void){
    int i;
    for(i=0;i<=(Head.y-turn[turn_no].y)&&len<length;i++){
        goto_xy(Head.x,Head.y-i);
        if(len==0){
            printf("v");
        }
        else{
            printf("*");
        }
        body[len].x=Head.x;
        body[len].y=Head.y-i;
        len++;
    }
    steer();
    if(!kbhit()){
        Head.y++;
    }
}

/**
* @brief Function controls the LEFT side movement of the Snake.
*/
void go_left(void){
    int i;
    for(i=0;i<=(turn[turn_no].x-Head.x)&&len<length;i++){
        goto_xy((Head.x+i),Head.y);
        if(len==0){
            printf("<");
        }
        else{
            printf("*");
        }
        body[len].x=Head.x+i;
        body[len].y=Head.y;
        len++;
    }
    steer();
    if(!kbhit()){
        Head.x--;
    }
}

/**
* @brief Function controls the RIGHT side movement of the Snake.
*/
void go_right(void){
    int i;
    for(i=0;i<=(Head.x-turn[turn_no].x)&&len<length;i++){
        body[len].x=Head.x-i;
        body[len].y=Head.y;
        goto_xy(body[len].x,body[len].y);
        if(len==0){
            printf(">");
        }
        else{
            printf("*");
        }
        len++;
    }
    steer();
    if(!kbhit()){
        Head.x++;
    }
}

/**
* @brief Function controls the turn movements of the Snake.
*/
void steer(void){
    int i,j,diff;
    for(i=turn_no;i>=0&&len<length;i--){
        if(turn[i].x==turn[i-1].x){
            diff=turn[i].y-turn[i-1].y;
                if(diff<0){
                    for(j=1;j<=(-diff);j++){
                        body[len].x=turn[i].x;
                        body[len].y=turn[i].y+j;
                        goto_xy(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length){
                            break;
                        }
                    }
                }
                else if(diff>0){
                    for(j=1;j<=diff;j++){
                        body[len].x=turn[i].x;
                        body[len].y=turn[i].y-j;
                        goto_xy(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length){
                            break;
                        }
                    }
                }
        }
        else if(turn[i].y==turn[i-1].y){
            diff=turn[i].x-turn[i-1].x;
            if(diff<0){
                for(j=1;j<=(-diff)&&len<length;j++){
                    body[len].x=turn[i].x+j;
                    body[len].y=turn[i].y;
                    goto_xy(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length){
                        break;
                    }
               }
            }
            else if(diff>0){
                for(j=1;j<=diff&&len<length;j++){
                    body[len].x=turn[i].x-j;
                    body[len].y=turn[i].y;
                    goto_xy(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length){
                        break;
                    }
               }
            }

        }
    }
}

/**
* @brief Function displays the score while in the game at the top.
*
* @param[out] score Current game score
*/
int score_display(void){
    int score;
    goto_xy(60,4);
    score=length-5;
    if(score>=0){
        printf("SCORE : %d",score);
    }
    else{
        printf("INVALID SCORE ");
    }
    score=length-5;
    return score;
}

/**
* @brief Function displays the exit menu and final score of that game.
* The game will be exited, when the snake hits the Wall, Obstacles or even itself.
*/
void exit_game(void){
    int i,check=0;
    /* Starts with 4 character as it needs minimum 4 elements to touch its own body */
    for(i=4;i<length;i++){
        if(body[0].x==body[i].x&&body[0].y==body[i].y){
            check++;
        }
        if(i==length||check!=0){
            break;
        }
    }
    if(Head.x<=GA_XL||Head.x>=GA_XR||Head.y<=GA_YT||Head.y>=GA_YB||(level==2 && Head.x>=24 && Head.x<=56 && (Head.y==11 || Head.y==24)) || (level==3 && Head.x>=25 && Head.x<=60 && (Head.y==10 || Head.y==23))|| (level==3 && Head.y>=15 && Head.y<=18 && (Head.x==18 || Head.x==67))||check!=0){
        system("cls");
        printf("GAME OVER!!! You crashed... :(\n");
        printf("Your score is %d\n",(length-5));
        update_data();
        printf("Press any key to return to Main Menu\n");
        getch();
        flg = 1;
        game();
    }
}

/**
* @brief Function asks the user to enter the name.
*/
void username(void){
    printf("\nEnter Player Name: ");
    scanf("%s",&name);
}

/**
* @brief Function displays the Player name entered by the user,
* while in the game at the top.
*/
void user_display(void){
    goto_xy(GA_XR/2 -20,GA_YT-1);
    printf("user:%s",name);
}

/**
* @brief Function reads the score from the score data file 'line-by-line'.
*
* @param[in] fp FILE type pointer for the score data file.
* @param[in] buffer FILE type pointer for the score data file.
* @param[out] pointer to the character which points to first character of line.
*/
char * read_line(FILE *fp, char *buffer){
    int ch;
    int i = 0;
    size_t buff_len = 0;
    buffer = malloc(buff_len + 1);
    if (!buffer){
        return NULL;
    }
    while ((ch = fgetc(fp)) != '\n' && ch != EOF){
        buff_len++;
        void *tmp = realloc(buffer, buff_len + 1);
        if (tmp == NULL){
            free(buffer);
            return NULL;
        }
        buffer = tmp;
        buffer[i] = (char) ch;
        i++;
    }
    buffer[i] = '\0';
    if (ch == EOF && (i == 0 || ferror(fp))){
        free(buffer);
        return NULL;
    }
    return buffer;
}

/**
* @brief Function writes the new score to the score data file.
*/
void update_data(void){
    int max=255;
    FILE * fp1;
    FILE * fp2;
    char temp[] = "temp.txt";
    char src[] = "data.txt";
    fp1 = fopen(src, "r");
    fp2= fopen(temp, "w");
    if (fp1 == NULL || fp2==NULL){
        exit(EXIT_FAILURE);
    }
    int finding_name_flag=1;
    char *s;
    while ((s = read_line(fp1, 0)) != NULL){
    char ds[max];
    strcpy(ds,s);
    char * token = strtok(s, " ");
    /* Comparing names of players */
    if(strcmp(token,name)==0 && finding_name_flag==1){
        int player_scores[MAX_LEVEL]={0};
        int changed=0;
        for(int i=0;i<MAX_LEVEL;i++){
            token = strtok(NULL, " ");
            if(token!=NULL){
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
                exit(1);
            }
        }
        /* Checking if current score is higher */
        if(changed==1){
            char newln[max];
            strncpy(newln, "", sizeof(newln));
            strcat(newln,name);
            for(int i=0;i<MAX_LEVEL;i++){
                strcat(newln," ");
                char snum[8];
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
    free(s);free(ds);
    fprintf(fp2,"\n");
    }
    if (finding_name_flag==1){
        char newln[max];
        strncpy(newln, "", sizeof(s));
        strcat(newln,name);
        int player_scores[MAX_LEVEL]={0};
        player_scores[level-1]=length-5;
        for(int i=0;i<MAX_LEVEL;i++){
                strcat(newln," ");
                char snum[8];
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

/**
* @brief Function displays the various levels for highscore.
*/
void display_scorecard(void){
    system("cls");
    printf("\t\tScorecard:\n");
    show_high_score_by_level(1,"Easy");
    show_high_score_by_level(2,"Medium");
    show_high_score_by_level(3,"Hard");
    printf("\n\n\nPress any key to return to Main Menu...");
    getch();
}

/**
* @brief Function displays the High Score from the score data file according to the levels.
*
* @param[in] for_level The level for which you want to display the scores
* @param[in] levelname Name of Level
*/
void show_high_score_by_level(int for_level,char levelname[]){
    printf("\n\nLevel-%s\n",levelname);
    int max=255;
    FILE * fp1;
    char src[] = "data.txt";
    fp1 = fopen(src, "r");

    if (fp1 == NULL){
        exit(EXIT_FAILURE);
    }
    int indices[DEPTH]={0};
    for (int i=0;i<DEPTH;i++){
        fseek(fp1, 0, SEEK_SET);
        char best_player[max];
        int best_score=-9999;
        int finding_name_flag=0;
        int current_index=0;
        char *s;
        int line=0;
        while ((s = read_line(fp1, 0)) != NULL){
            line++;
            int reject=0;
            for (int j=0;j<i;j++){
                if (line==indices[j]){
                    free(s);
                    reject=1;
                    break;
                }
            }
            if (reject){
                continue;
            }
            char current_name[max];
            char * token = strtok(s, " ");
            strcpy(current_name,token);
            int extract=for_level;
            while(extract--){
                token = strtok(NULL, " ");
            }
            int current_score = atoi(token);
            if (current_score>best_score){
                strcpy(best_player,current_name);
                best_score=current_score;
                indices[i]=line;
                finding_name_flag=1;
            }
            free(s);free(current_name);
        }
        if(finding_name_flag==1){
            printf("\n %s : %d",best_player,best_score);
        }
    }
    fclose(fp1);
}

/**
* @brief Function displays the various levels for the user to play.
* The user will have to select from three options of the levels. Namely, Easy, Medium & Hard.
*
* @param[out] option Returns the level choice of the user.
*/
int level_select(void){
    int option;
    /* Max number of trials for the invalid input by the user */
    int max_trials=3;
    do{
        system("cls");
        printf("               Level Selection\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n\n");

        printf("    Please enter choice number : ");
        scanf(" %d",&option);
        if(option==1 || option==3 || option==2 )
            return option;
    }while(max_trials--);
    system("cls");
    printf("\n\tGame exit because of consecutive invalid inputs!\n\n");
    exit(0);
}
