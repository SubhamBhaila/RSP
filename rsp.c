#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int game(char p1, char p2)
{
    if (p1 == p2)
        return -1;

    else if (p1 == 's' && p2 == 'p')
        return 0;
    else if (p1 == 'p' && p2 == 's')
        return 1;

    else if (p1 == 's' && p2 == 'c')
        return 1;
    else if (p1 == 'c' && p2 == 's')
        return 0;

    else if (p1 == 'p' && p2 == 'c')
        return 0;
    else if (p1 == 'c' && p2 == 'p')
        return 1;

    return -2;
}

int main()
{
    int mode;
    char p1, p2, computer;
    char ch;
    int result;

    int match = 1;
    int win = 0, loss = 0, draw = 0;

    printf("==== Stone Paper Scissors Game ====\n");
    printf("Choose Mode:\n");
    printf("1. Single Player (vs Computer)\n");
    printf("2. Multiplayer (Player vs Player)\n");
    printf("Enter choice: ");
    scanf("%d", &mode);

    printf("\nPress ENTER to start, Q to quit anytime\n");

    while (1)
    {
        ch = _getch();
        if (ch == 'q' || ch == 'Q')
            break;

        printf("\n\nGame %d\n", match);

        if (mode == 1)
        {
            // SINGLE PLAYER MODE
            srand(time(NULL));
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
            // MULTIPLAYER MODE
            printf("Player 1 (s/p/c): ");
            scanf(" %c", &p1);

            printf("Player 2 (s/p/c): ");
            scanf(" %c", &p2);

            result = game(p1, p2);
        }

        // RESULT DISPLAY
        if (result == 1)
        {
            printf("\nPlayer 1 Wins!\n");
            win++;
        }
        else if (result == 0)
        {
            printf("\nPlayer 2 Wins!\n");
            loss++;
        }
        else if (result == -1)
        {
            printf("\nGame Draw!\n");
            draw++;
        }
        else
        {
            printf("\nInvalid Input!\n");
        }

        match++;

        printf("\nPress ENTER to continue or Q to quit\n");
    }

    printf("\n===== FINAL SCORE =====\n");
    printf("Wins: %d\nLosses: %d\nDraws: %d\n", win, loss, draw);
    printf("Thank you for playing!\n");

    return 0;
}