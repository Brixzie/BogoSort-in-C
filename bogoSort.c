#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>


/*
Use: Enter data through console
Create function and makefile
*/

void shuffleMessage(){
  printf("\nGetting ready to shuffle..");
  sleep(2);
  printf(".");
  sleep(2);
  printf(".\n");
}

void shuffleAction(int elements[]){
  int takenSlots[8];
  int shuffledCard;
  int holder;
  for(int n=0;n<8;n++){
    shuffledCard = rand() % 8;
    if(takenSlots[shuffledCard] != 1){
      holder = elements[n];
      elements[n] = elements[shuffledCard];
      elements[shuffledCard] = holder;
      takenSlots[shuffledCard] = 1;
      takenSlots[n] = 1;
    }else{
      for(int z=0;z<8;z++){
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
/*
//Return 0 for unsorted and 1 for sorted
//O(N)
int checkSort(int elements[]){
  int sortCheck = 0;
  int lowest = elements[0];
  int k = 0;
  int breaky = 0;
  for(int n=0;n<4;n++){
    if(elements[n]>elements[n+1]){
      printf("%d is greater than %d", elements[n], elements[n+1]);
      return 0;
    }
  }
return 1;
}*/
//O(N)
//Returns 0 if unsorted, 1 if sorted
int checkSort(int size, char *elements[]){
  int n;
  for(n=0;n<size-1;n++){
    if(atoi(elements[n])>atoi(elements[n+1])){
      printf("%d is greater than %d", atoi(elements[n]), atoi(elements[n+1]));
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

    //Populate array
    for(int n=0;n<8;n++){
      elements[n] = rand() % 100;
    }
    printf("Elements unsorted:        ");
    for(int n=0;n<8;n++){
      printf("%d ", elements[n]);
    }

    shuffleAction(elements);
    printf("\nElements after shuffle:   ");
    for(int n=0;n<8;n++){
      printf("%d ", elements[n]);
    }
    printf("\n");

    while(checkSort(argc, argv) == 0){

      printf("\nElements unsorted:        ");
      for(int n=0;n<8;n++){
        printf("%d ", elements[n]);
      }
      shuffleAction(elements);
      iterations++;
    }
    printf("\nElements sorted:          ");
    for(int n=0;n<8;n++){
      printf("%d ", elements[n]);
    }
    printf("\n%d number of shuffles required\n", iterations);
    return 0;
}
