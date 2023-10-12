#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CHAR_MAX 20


void MakeCode(int[],int);
void Guess(int[], int);
void DisplayGuess(int[], int);
int CodeCheck(int[], int[], int);

int main()
{   char selection[CHAR_MAX], again;
    int code[CHAR_MAX], guess[CHAR_MAX];
    srand(time(NULL));
    int i;
    int flag;           /*determines if win or not win*/
    
    printf("WELCOME TO PURBLE SHOP GAME!\n\n");
    
    while(1)            /*repeats to play until user wants to quit*/
    {
    i=0;                /*resets round counter*/
    flag=0;             /*resets win determiner*/

    puts("Please enter the difficulty for your PS Game (advance/beginner): ");
    fflush(stdin);
    gets(selection);
    

    if(strcmp(selection,"advance")==0)    /*checks if advance or not*/
    {
     puts("You have selected the advanced mode. You have 5 types of colors and 5 features.");
     MakeCode(code,5);
     /*printf("%d%d%d%d%d",code[0],code[1],code[2],code[3],code[4]);*/

    while(i++<12)        /*checks if round is bigger than 12*/
     {
     printf("\n\n******\t\t\t    %d. GUESS\t\t\t******\n\n",i);
     Guess(guess,5);
     DisplayGuess(guess,5);
     flag=CodeCheck(code,guess,5);   /*CodeCheck returns 1 if all correct, 0 if not*/
     /*printf("\n flag=%d", flag);*/

     if(flag==1)  /*if win than exits the loop*/
                  break;
     }

    
    }

    else if(strcmp (selection, "beginner")==0)  /*these part is same as advance mode, only 3 for number 5*/
    {
    puts("You have selected the beginner mode. You have 3 types of colors and 3 features.");
    MakeCode(code,3);
    /*printf("%d%d%d",code[0],code[1],code[2]);*/

    while(i++<12)
     {
     printf("\n\n******\t\t\t    %d. GUESS\t\t\t******\n\n",i);
     Guess(guess,3);
     DisplayGuess(guess,3);
    
     flag=CodeCheck(code,guess,3);

     if(flag==1)
                break;
    
     }
    }

    else
        puts("You have chosen invalid difficulty");
    
    
    if(flag==1)           /*announces win/ round count*/
                          printf("\n\nYou win with %d guess\n\n", i);
    else
        printf("\n\nYou lose :(\n\n");
    /*printf("\n%d", flag);*/
        
    puts("\nDo you want to play again");    /*asks user to continue or not*/
    fflush(stdin);
    scanf("%c", &again);

    if(again!='y')      /*checks*/
                        break;

    }
    system("pause");
    
}

void MakeCode(int code[CHAR_MAX],int i) /*takes the empty code array and the difficulty level from main and fills the array with randoms*/
{
     int j;

     for(j=0;j<i;j++)
       code[j]=rand()%i+1;             /*generates random number in bounds of 1 to difficulty level*/
}

void Guess(int guess[CHAR_MAX], int i)           /*takes the empty or not empty guess array and fills it with new guesses according to the input*/
{
     if(i==3)
             {
             printf("\nPlease enter your guess for eyes (1:red 2:green 3:blue): ");
             scanf("%d",&guess[0]);

             printf("Please enter your guess for nose (1:red 2:green 3:blue): ");
             scanf("%d",&guess[1]);

             printf("Please enter your guess for mouth (1:red 2:green 3:blue): ");
             scanf("%d",&guess[2]);
             }
     
     if(i==5)
             {
             printf("\nPlease enter your guess for hat(1:red 2:green 3:blue 4:purple 5:yellow): ");
             scanf("%d",&guess[0]);

             printf("Please enter your guess for eyes(1:red 2:green 3:blue 4:purple 5:yellow): ");
             scanf("%d",&guess[1]);

             printf("Please enter your guess for nose(1:red 2:green 3:blue 4:purple 5:yellow): ");
             scanf("%d",&guess[2]);

             printf("Please enter your guess for mouth(1:red 2:green 3:blue 4:purple 5:yellow): ");
             scanf("%d",&guess[3]);

             printf("Please enter your guess for clothes(1:red 2:green 3:blue 4:purple 5:yellow): ");
             scanf("%d",&guess[4]);
             }
}


void DisplayGuess(int g[], int i)  /*displays..*/
{
     int j;
     printf("\nYour guess is:");

     for(j=0;j<i;j++)     
         printf(" %d", g[j]);

}


int CodeCheck(int code[CHAR_MAX], int guess[CHAR_MAX], int i)
{
     int j,l,color,correct; /*j,l counters for for loops, color and correct are counters for correct f+c check and wrong f correct c check*/
     color=0;               /*must have initial value for each run of function*/
     correct=0;             /*must have initial value for each run of function*/

     for(j=0;j<i;j++)
      {
      if(code[j]==guess[j]) /*if correct position and color, increments correct, else, goes for wrong feature correct color check*/
         correct++;

      else
      for(l=0;l<i;l++)
           {

           if(code[j]==guess[l]) /*if finds one match, it exits in order not to print wrong results (multiple repetitions of same colour)*/
                             {
                             color++;
                             break;
                             }
           }
      }
     
     if(correct==i)         /*if all correct, returns 1 (means win in main) and terminates the function*/
                            return 1;

     else                   /*if not win, announces the scores and returns 0 to make sure it is still not a win*/
     {
         printf("\nRight Colour, Right Feature: %d", correct);
         printf("\nRight Colour, Wrong Feature: %d", color);

         return 0;
     }
}
