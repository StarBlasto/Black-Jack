//imported libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int Cards[] = {1,2, 3, 4, 5, 6, 7, 8, 9, 10, 10};
int YourHand = 0;
int DealerHand = 0;

//hit me function
int HitMe(int WhosHand){
  //selects a random card
  int n = sizeof(Cards) / sizeof(Cards[0]);
  srand(time(NULL));
  int random_int = Cards[rand() % n];

  //adds card to hand
  if (WhosHand == 1){
    YourHand += random_int;
  } else if (WhosHand == 2){
    DealerHand += random_int;
  }
  return 0;
}

//fold function
int Fold(void){

  return 0;
}

int main(void) { // main function
  //sets up he game
  HitMe(1);
  HitMe(1);

  printf("------------------------------------\n[Dealer]: Welcome to Black Jack, when it is your turn, please type either: \"hit\" or \"stand\"\n------------------------------------\n");
  printf("Your hand - %d\n", YourHand);

  //variables
  char response[100];

  //infinite loop until player loses the game or stands
  while (strcmp(response, "stand") != 0 & YourHand <= 21){
    printf("[You]: ");
    scanf("%s", response);

    if (strcmp(response, "hit")==0){
      HitMe(1);
      printf("Your hand - %d\n", YourHand);
    } else if (strcmp(response, "Fold")){
      Fold();
    } else {
      printf("-Unknown command-");
    }
  }

  //Quick check if you busted
  if (YourHand == 21){
    printf("[BLACKJACK!!! YOU WIN!]\n");
    return 0;
  } else if (YourHand > 21){
    printf("[Dealer]: YOU BUSTED, LOSER!!!\n[YOU LOSE]\n");
    return 0;
  } else {
    printf("[You Stand]\n");
  }

  //infinite loop until dealer busts or beats player
  while (DealerHand <= YourHand & DealerHand < 21){
    HitMe(2);
  }

  //Final results
  if (DealerHand > 21){
    printf("[Dealer busted with %d!]\n[YOU WIN!]\n", DealerHand);
  } else if (DealerHand > YourHand) {
    printf("[Dealer wins with %d!]\n[YOU LOSE]\n", DealerHand);
  } else if (YourHand > DealerHand){
   printf("[Dealer loses with %d!]\n[YOU WIN]\n", DealerHand);
  }
  
  return 0;
}
