
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include<windows.h>


int game(char you, char computer)
{
    if (you == computer)
        return -1;


    else if (you == 's' && computer == 'p')
        return 0;


    else if (you == 'p' && computer == 's')
        return 1;


    else if (you == 's' && computer == 'c')
        return 1;


    else if (you == 'c' && computer == 's')
        return 0;


    else if (you == 'p' && computer == 'c')
        return 0;


    else if (you == 'c' && computer == 'p')
        return 1;
    if (you != 's' && you != 'p' && you != 'c')
        return -2; 


}
int main()
{
	int n, a;
	char you, computer, result;
	int i;
	
	int match = 1;
	int win = 0, loss = 0, draw = 0;
	char ch;
	printf("press enter to start");
	while (1)
	{
		ch = _getch();

		if (ch == 'q' || ch == 'Q') {
			break;
		}

		
		printf("\n\n\ngame %d\n", match);
		srand(time(NULL));
		n = rand() % 100;
		if (n < 33)
			computer = 's';
		else if (n > 33 && n < 66)
			computer = 'p';
		else
			computer = 'c';   
		printf("\n\n\n\n\t\t\t\tEnter s for stone, p for paper and c for scissor\n\t\t\t\t\t\t\t");
		scanf(" %c", &you);
		result = game(you, computer);
		if (you == 's') {
			Sleep(1000);
			printf("\n\t\t\t\t\tyou choosed stone ");
		}
		else if (you == 'p')
		{
			Sleep(1000);
			printf("\n\t\t\t\t\tyou choosed paper ");
		}
		else if (you != 'p' && you != 's' && you != 'c')
		{
			printf("\n\t\t\t\t\tyou choosed the wrong letteer");
		}
		else
		{
			printf("\n\t\t\t\t\tyou choosed scissor  ");
		}

		if (n < 33) {
			Sleep(1000);
			printf("\n\t\t\t\t\tcomputer choosed stone ");
		}
		else if (n > 33 && n < 66) {
			Sleep(1000);
			printf("\n\t\t\t\t\tcomputer choosed paper ");
		}
		else {
			Sleep(1000);
		 	printf("\n\t\t\t\t\tcomputer choosed scissor ");
		}
		
		if (result == -1) {
			Sleep(1000);
			printf("\n\n\t\t\t\t\t\tGame Draw\n");
		}
		else if (result == 1) {
			Sleep(1000);
			printf("\n\n\t\t\t\t\t\tYou Win\n");
		}
		else if (result == -2) {
			
			printf("\n\n\t\t\t\t\t\tInvalid Input\n");
		}
		else {
			Sleep(1000);
			printf("\n\n\t\t\t\t\t\tYou Lose\n");
		}

		if (result == 1) {
			win++;



		}
		if (result == 0)
		{
			loss++;

		}
		if (result == -1) {
			draw++;

		}
		Sleep(1000);
		printf("\n\n\t\t\t\tpress q  to end the game or press enter to continue\n");


		match++;


	}
	Sleep(1000);
	printf("\n\t\t wins \t\t\t loss\t\t\t\tdraw \n\t\t%d \t\t\t\t%d\t\t\t\t%d\n\n\n  ", win,loss,draw);
	Sleep(1000);
	
	printf("\t\t\t\t\t\t\tThank you for playing\n\n\n\n");
	Sleep(1000);

	return 0;
}


