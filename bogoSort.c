#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


/*
Use: Enter data through console
Create function and makefile
*/


void shuffleAction(int size, char *elements[]){
  int takenSlots[size];
  int shuffledCard;
  char *holder;
  for(int n=1;n<size;n++){
    shuffledCard = rand() % size;
    if(shuffledCard==0){
      shuffledCard = 1;
    }
    if(takenSlots[shuffledCard] != 1){
      holder = elements[n];
      elements[n] = elements[shuffledCard];
      elements[shuffledCard] = holder;
      takenSlots[shuffledCard] = 1;
      takenSlots[n] = 1;
    }else{
      for(int z=1;z<size;z++){
        if(takenSlots[z]!=1){
          holder = elements[n];
          elements[n] = elements[shuffledCard];
          elements[shuffledCard] = holder;
          takenSlots[shuffledCard] = 1;
          takenSlots[n] = 1;
          break;
        }
      }
    }
  }
}
//O(N)
//Returns 0 if unsorted, 1 if sorted
int checkSort(int size, char *elements[]){
  int n;
  for(n=1;n<size-1;n++){
    if(atoi(elements[n])>atoi(elements[n+1])){
      //printf("%d is greater than %d", atoi(elements[n]), atoi(elements[n+1]));
      return 0;
    }
  }
return 1;
}

int main(int argc, char *argv[]){

    srand(time(0));
    int elements[8];
    int takenSlots[8];
    int shuffledCard;
    int holder;
    int elements2[5] = {1,2,3,4,5};
    int iterations = 0;

    /*
    //Populate array
    for(int n=0;n<8;n++){
      elements[n] = rand() % 100;
    }*/
    printf("Elements in entered order:      ");
    for(int n=1;n<argc;n++){
      printf("%s ", argv[n]);
    }
    printf("\n");
/*
    shuffleAction(argc, argv);
    printf("\nElements after shuffle:   ");
    for(int n=1;n<argc;n++){
      printf("%s ", argv[n]);
    }
    printf("\n");*/

    while(checkSort(argc, argv) == 0){

      printf("\nElements after shuffle:         ");
      for(int n=1;n<argc;n++){
        printf("%s ", argv[n]);
      }
      shuffleAction(argc, argv);
      iterations++;
    }
    printf("\n\nElements sorted:                ");
    for(int n=1;n<argc;n++){
      printf("%s ", argv[n]);
    }
    printf("\n%d number of shuffles required\n", iterations);
    return 0;
}
