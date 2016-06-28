#define TRUE 1;
#define FALSE 0;
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

//variables
int num[] = { 1, 2, 3, 4, 5, 6, 7,};
int guess[] = { 1, 2, 3, 4, 5, 6, 7,};
int option;
int choice;
int length;
int codeSolved;
int lives;
int correct = 0;
int i = 0, x = 0, y = 0;

void help(void);

int Difficulty(int difficulty)
{
	struct diff
	{
		int playerLives;
		int codeLength;
	};

	//structure
	struct diff easy;
	struct diff normal;
	struct diff hard;

	//Difficulty options
	if(difficulty == 1)
	{
		easy.codeLength = 3;
		length = easy.codeLength;
	}
	if(difficulty == 2)
	{
		normal.codeLength = 3;
		length = normal.codeLength;
	}
	if(difficulty == 3)
	{
		hard.codeLength = 3;
		length = hard.codeLength;
	}

	//Lives option
	if(difficulty == 1)
	{
		easy.playerLives = 5;
		lives = easy.playerLives;
	}
	if(difficulty == 2)
	{
		normal.playerLives = 4;
		lives = normal.playerLives;
	}
	if(difficulty == 3)
	{
		hard.playerLives = 3;
		lives = hard.playerLives;
	}
	return length;
}

int main()
{
	printf("\t\t\t  MASTERMIND GAME\n\t\t - Created by Andrew Blankley - G00313312\n");
	printf("=======================================================================\n");
	printf("\n");
	printf("\tEnter 1 to Play, Enter 2 for Instructions on how to Play!: ");
	scanf_s(" %d", &choice);
	
	if (choice == 1)
	{
		menu();
	}
	else
	{
		help();
	}
	printf("\n");
}

int menu()
{
	codeSolved = FALSE;
	printf("\n");
	printf("=====================================================================\n");
	printf("\tFind the code within the number of lives given to beat the game!!\n");
	printf("\tAny correct numbers that you get are revealed but if you enter\n");
	printf("\tthe wrong number it will stay as '?'.\n");
	printf("\tBest of Luck and let the game begin!\n");
	printf("\n");
	printf("\tChoose a Difficulty\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("\tFor Easy Press 1: \n");
	printf("\n");
	printf("\tFor Normal Press 2: \n");
	printf("\n");
	printf("\tFor Hard Press 3: \n");
	printf("\n");
	printf("\tEnter Difficulty: ");
	scanf_s(" %d", &option);
	printf("\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("\n");
	Difficulty(option);

	for (i = 0; i <= length - 1; i++)
	{
		num[i] = rand() % 10;
	}

	printf("\t\t\t    Mastermind Code: ");

	for (i = 0; i <= length; i++)
	{
		printf(" ? ");
	}

	printf("\n");

	while (codeSolved == 0)
	{
		printf("\n");
		if (option == 1)
		{
			printf("\tDifficulty: Easy");
		}
		else if (option == 2)
		{
			printf("\tDifficulty: Normal");
		}
		else if (option == 3)
		{
			printf("\tDifficulty: Hard");
		}
		printf("\n\tNumber of lives: %d", lives);
		printf("\n");
		printf("\n");

		for (y = 0; y <= length; y++)
		{
			printf("\tEnter Number %d: ", y + 1);
			scanf_s(" %d", &guess[y]);
		}
		printf(" \n");
		printf("\t\t\t    Mastermind Code: ");

		for (x = 0; x <= length; x++)
		{
			if (guess[x] == num[x])
			{
				printf("%d ", num[x]);
				correct++;
			}
			else
			{
				printf(" ? ");
			}	
		}
		printf("\n");
		if (option == 1)
		{
			if (guess[0] == num[0] && guess[1] == num[1] && guess[2] == num[2] && guess[3] == num[3])
			{
				printf("=====================================================================\n");
				printf("\n\t   Well done you have completed Mastermind on Easy!!\n");
				printf("\n\t\t   Now play on Normal Difficulty!!\n");
				printf("=====================================================================\n");
				codeSolved = TRUE;
				printf("   Enter 1 to Play again, Enter 2 to Exit: ");
				scanf_s(" %d", &choice);

				if (choice == 1)
				{
					menu();
				}
				else
				{
					exit(0);
				}
				printf("=====================================================================\n");
				printf("\n");
			}
			else
			{
				printf("\nPress Enter to try again!\n");
				printf("=====================================================================\n");
				lives--;
			}
		}
		else if (option == 2)
		{
			if (guess[0] == num[0] && guess[1] == num[1] && guess[2] == num[2] && guess[3] == num[3])
			{
				printf("=====================================================================\n");
				printf("\n\t   Congrats! you have completed Mastermind on Normal!!\n");
				printf("\n\t\t   Now play on Hard Difficulty!\n");
				printf("=====================================================================\n");
				codeSolved = TRUE
					printf("   Enter 1 to Play again, Enter 2 to Exit: ");
				scanf_s(" %d", &choice);

				if (choice == 1)
				{
					menu();
				}
				else
				{
					exit(0);
				}
				printf("=====================================================================\n");
				printf("\n");
			}
			else
			{
				printf("\nPress Enter to try again!\n");
				printf("=====================================================================\n");
				lives--;
			}
		}
		else if (option == 3)
		{
			if (guess[0] == num[0] && guess[1] == num[1] && guess[2] == num[2] && guess[3] == num[3])
			{
				printf("=====================================================================\n");
				printf("\n\t   Congrats! you have completed Mastermind on Hard!!\n");
				printf("\n\t\t   You are a true Mastermind Legend!!!\n");
				printf("=====================================================================\n");
				codeSolved = TRUE;
				printf("   Enter 1 to Play again, Enter 2 to Exit: ");
				scanf_s(" %d", &choice);

				if (choice == 1)
				{
					menu();
				}
				else
				{
					exit(0);
				}
				printf("=====================================================================\n");
				printf("\n");
			}
			else
			{
				printf("\nPress Enter to try again!\n");
				printf("=====================================================================\n");
				lives--;
			}
		}
		if (lives < 1)
		{
			printf("\n");
			printf("\n\t   ===================== GAME OVER!  =====================");
			printf("\n\t   ===================  Out of Lives!  ===================");
			printf("\n\t   You found a correct number %d times before you ran out of lives!", correct);
			printf("\n");
			printf("\n");
			printf("   Enter 1 to Play again, Enter 2 to Exit: ");
			scanf_s(" %d", &choice);

			if (choice == 1)
			{
				menu();
			}
			else
			{
				exit(0);
			}
			printf("=====================================================================\n");
			printf("\n");
		}

		_getch();
	}
}

void help(void)
{
	printf("\n");
	printf("\t\t\tMastermind Help Page!\n");
	printf("\t\t=================================================\n");
	printf("\t\tMastermind is a game where the user guesses numbers that \n");
	printf("\t\thave been randomly generated by the computer.\n");
	printf("\t\tThe code is totally unknown and contains the numbers from 1 - 7.\n");
	printf("\t\tEach number corresponds to a colour of the rainbow,\n");
	printf("\t\t1 = Red, 2 = Orange, 3 = Yellow, 4 = Green, 5 = Blue,\n");
	printf("\t\t6 = Indigo and 7 = Violet.\n");
	printf("\t\tThere a 3 difficulty levels. Each have an amount of lives!\n");
	printf("\t\tThe lives that you have, range from 3 to 4 to 5.\n");
	printf("\t\tEvery \'?\' you see is an unknown number in the code.\n");
	printf("\t\tIf a number is correct it is then revealed.\n");
	printf("\n");
	printf("To start playing press 1 ");
	printf("\n");
	printf("\n Or Exit with 9... \n I guess your not a Mastermind After all!\n");
	scanf_s(" %d", &choice);
	printf("\n");
	
	while (choice != 1 || choice != 9)
	{

		if (choice == 1)
		{
			menu();
		}
		else if (choice == 9)
		{
			printf("To bad your Leaving.. Good Bye!");
			printf("\n");
			exit(0);

		}
		else
		{
			printf("\nError in your Decision!....\nPlease pick either 1 to Play or 9 to Exit!");
			printf("\nThank you and enjoy!");
			
		}
		scanf_s(" %d", &choice);
	}
}