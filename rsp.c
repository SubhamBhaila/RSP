#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "game.h"

int main()
{
    int mode;
    char p1, p2, computer;
    char ch;
    int result;

    int match = 1;
    int win = 0, loss = 0, draw = 0;

    FILE *fp;

    fp = fopen("score.txt", "r");

    if (fp != NULL)
    {
        fscanf(fp, "%d %d %d", &win, &loss, &draw);
        fclose(fp);
        printf("Previous Score -> Wins: %d Loss: %d Draw: %d\n\n", win, loss, draw);
    }

    printf("==== Stone Paper Scissors Game ====\n");
    printf("1. Single Player\n2. Multiplayer\nEnter choice: ");
    scanf("%d", &mode);

    if (mode != 1 && mode != 2)
    {
        printf("Invalid Input!\n");
        return 0;
    }

    printf("\nPress ENTER to start, Q to quit\n");

    srand(time(NULL));

    while (1)
    {
        ch = _getch();

        if (ch == 'q' || ch == 'Q')
            break;

        printf("\nGame %d\n", match);

        if (mode == 1)
        {
            int n = rand() % 100;

            if (n < 33)
                computer = 's';
            else if (n < 66)
                computer = 'p';
            else
                computer = 'c';

            printf("Enter s (stone), p (paper), c (scissors): ");
            scanf(" %c", &p1);

            result = game(p1, computer);

            printf("Computer chose: %c\n", computer);
        }
        else
        {
            printf("Player 1 (s/p/c): ");
            p1 = _getch();
            printf("*\n");
            system("cls");

            printf("Player 2 (s/p/c): ");
            p2 = _getch();
            printf("*\n");
            system("cls");

            result = game(p1, p2);
        }

<<<<<<< HEAD
=======

>>>>>>> af5fb7182911c6f5c139c4c82246abad6c95f01a
        if (result == 1)
        {
            if (mode == 1)
                printf("You Win!\n");
            else
                printf("Player 1 Wins!\n");

            win++;
        }
        else if (result == 0)
        {
            if (mode == 1)
                printf("You Lose!\n");
            else
                printf("Player 2 Wins!\n");

            loss++;
        }
        else if (result == -1)
        {
            printf("Draw!\n");
            draw++;
        }
        else
        {
            printf("Invalid Input!\n");
        }

        match++;

        printf("\nPress ENTER to continue or Q to quit\n");
    }

    fp = fopen("score.txt", "w");

    if (fp != NULL)
    {
        fprintf(fp, "%d %d %d", win, loss, draw);
        fclose(fp);
    }

    printf("\nFinal Score:\nWins: %d Loss: %d Draw: %d\n", win, loss, draw);
    printf("Score saved to file (score.txt)\n");

    return 0;
}
