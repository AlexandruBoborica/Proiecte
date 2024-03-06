#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice1, dice2, player1, player2;
    int sum;
    printf("introduce the amount of money to be played (LEI)-");
    scanf("%d", &sum);
    int player1_score=0;
    int player2_score=0;
    int ok1,ok2;
    ok1 = ok2 =0;
    int n;
    char player1_name[50];
    char player2_name[50];
    printf("PLAYER1-");
    scanf("%s",player1_name);
    printf("PLAYER2-");
    scanf("%s",player2_name);
    printf("introduce the number of rounds to be played - ");
    scanf("%d", &n);
    int i=0;
    srand(time(0));
    while (i<n)
    {
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        if(dice1 == dice2)
        {
            ok1 = 1;
        }
        player1 = dice1 + dice2;
        printf("%s  has %d -- %d\n",player1_name,dice1, dice2);
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        player2 = dice1 + dice2;
        if(dice1 == dice2)
        {
            ok2 = 1;
        }
        printf("%s  has %d -- %d\n",player2_name,dice1, dice2);
        if(ok1 == 1 && ok2 == 0 )
            player1_score++;
        else if(ok2 == 1 && ok1 == 0)
            player2_score++;
        else
        {
            if(player1 > player2)
                player1_score++;
            if(player2 > player1)
                player2_score++;
            if(player1 == player2)
                printf("roll the dices again\n");
        }
        printf("%s %d - %d %s\n",player1_name,player1_score, player2_score, player2_name);
        printf("-----------------\n");
        i++;
    }
    if(player1_score > player2_score)
        printf("%s wins", player1_name);
    else if(player1_score < player2_score)
        printf("%s wins", player2_name);
    else
        printf("draw");
    return 0;
}
