#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>

int getUserChoice() {
    
  int sticks;
  printf("Player 1: How many sticks do you take (1-3)?\n");
  scanf("%d", &sticks);
  if(0<sticks<4){
    return sticks;
  }
  else{
    printf("Invalid input\n");
    getUserChoice();
  }

}

int getComputerChoice(int current_sticks) {

    /* get a pseudo-random integer between 1 and 3 (inclusive) */
    int rand_choice = rand() % 3 + 1;
    if(1<current_sticks<5){
      switch (current_sticks){
            case 2 : return 1;
                      break;
            case 3: return 2;
                      break;
            case 4: return 3;
                      break;
    }
  }


    if (rand_choice > current_sticks) return current_sticks;

    return rand_choice;
}


int main(int argc, char** argv) 
{
    int user, computer, number_sticks;


    srand (time(NULL)); /* for reproducible results, you can call srand(1); */

    printf("Welcome to the game of sticks!\n");
    printf("How many sticks are there on the table initially (10-100)? \n");
    scanf("%d", &number_sticks);
    if(10<=number_sticks<=100){
      //Main game loop
      while(number_sticks>0)
      {
        user=getUserChoice();
        if((number_sticks-user)<1){
          printf("You lost the game\n");
          break;
        }
        else{
        number_sticks=number_sticks-user;
        printf("There are %d sticks on the board\n", number_sticks);
      }
        computer=getComputerChoice(number_sticks);
        if((number_sticks-computer)<1){
          printf("The computer took %d sticks \n", computer);
          printf("The computer lost the game\n");
          break;
        }
        else{
        number_sticks=number_sticks-computer;
        printf("The computer took %d sticks \n", computer);
        printf("There are %d sticks on the board\n", number_sticks);
      }
      }



    }

    else
      printf("Error, input is not between 10 and 100, Progam Terrminated\n");

    return 0;
}