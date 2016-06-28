#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define TRUE 1;
#define FALSE 0;

//Mastermind Variables
int num[] = { 1, 2, 3, 4, 5, 6, 7,};
int guess[] = { 1, 2, 3, 4, 5, 6, 7,};
int right = 0;
int chances, option, choice;
int length;
int codeSolved;
int i = 0, x = 0, y = 0;

int MAX_EASY_CHANCES = 15;
int MAX_NORMAL_CHANCES = 10;
int MAX_HARD_CHANCES = 5;

void help(void);

int main()
{

	printf("\n\t\t\t  MASTERMIND GAME\n\n\t\t - Created by Andrew Blankley - G00313312\n");
	printf("==========================================================================\n");
	printf("\n");

	char name[50];
	printf("Please enter your name: ");
	fgets(name, 50, stdin);
	printf("\n\t\t\t\tHello:\n\t\t\t\t%s\n\t\t\tWELCOME TO MASTERMIND!\n", name);

	printf("\n\tEnter 1 to Play, Enter 2 for Instructions on how to Play!: ");
	scanf_s(" %d", &choice);

	//error handling 
	while (choice != 1 || choice != 2)
	{
		if (choice == 1)
		{
			menu();
		}// end if
		else if (choice == 2)
		{
			help();
		}// end else if
		else
		{
			printf("Im sorry, that isn't a Valid Option!\nPlease pick again!");
		}// end else

		printf("\n");
		scanf_s(" %d", &choice);

	} // While
	
} // main()

// How hard the game can be!
int Difficulty(int difficulty)
{
	struct diff
	{
		int playerchances;
		int codeLength;
	};

	//structure of game modes
	struct diff easy;
	struct diff normal;
	struct diff hard;

	//Difficulty options if Statements
	if (difficulty == 1)
	{
		easy.codeLength = 3;
		length = easy.codeLength;
	} // end if

	if (difficulty == 2)
	{
		normal.codeLength = 3;
		length = normal.codeLength;
	} // end if

	if (difficulty == 3)
	{
		hard.codeLength = 3;
		length = hard.codeLength;
	} // end if

	//Ability to choose how many goes player has.
	if (difficulty == 1)
	{
		printf("Please Enter how many chances you want to take!\nMAX 15:	 ");
		scanf_s(" %d", &easy.playerchances);
	
			while (easy.playerchances > MAX_EASY_CHANCES)
			{	
				//chances = easy.playerchances;
				if (easy.playerchances > MAX_EASY_CHANCES)
				{
					printf("I'm sorry... Please Enter a valid number of Chances!: ");
					
				}
	
				scanf_s(" %d", &easy.playerchances);
			
			}//while
			chances = easy.playerchances;
		

	}// end if

	if (difficulty == 2)
	{
		printf("Please Enter how many chances you want to take!\nMAX 10:	");
		scanf_s(" %d", &normal.playerchances);

		while (normal.playerchances > MAX_NORMAL_CHANCES)
		{
			//chances = normal.playerchances;
			if (normal.playerchances > MAX_NORMAL_CHANCES)
			{
				printf("I'm sorry... Please Enter a valid number of Chances!: ");

			}

			scanf_s(" %d", &normal.playerchances);

		}//while
		chances = normal.playerchances;

	} // end if

	if (difficulty == 3)
	{
		printf("Please Enter how many chances you want to take!\nMAX 5:	");
		scanf_s(" %d", &hard.playerchances);
		
		while (hard.playerchances > MAX_HARD_CHANCES)
		{
			//chances = hard.playerchances;
			if (hard.playerchances > MAX_HARD_CHANCES)
			{
				printf("I'm sorry... Please Enter a valid number of Chances!: ");

			}

			scanf_s(" %d", &hard.playerchances);

		}//while
		chances = hard.playerchances;

	} // end if
	return length;
	
} // Difficulty()

int menu()
{
	codeSolved = FALSE;
	printf("\n");
	printf("=====================================================================\n");
	printf("\tFind the code within the number of chances given to win the game!!\n");
	printf("\tAny right numbers that you pick are revealed but if you enter\n");
	printf("\tthe wrong number it will stay as '?'.\n");
	printf("\tGood Luck.\n");
	printf("\n");
	printf("Mastermind has 3 levels of difficulty:\n");
	printf("1: Easy ; 4 colours with no repeats or blank spaces\n");
	printf("2: Medium ; 4 colours with repeats, but no blank spaces\n");
	printf("3: Hard ; 4 colours with repeats and blanks spaces as options\n\n");
	printf("\n");
	printf("\tChoose a Difficulty\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("\tFor Easy Press 1 (Enter Number!): \n");
	printf("\n");
	printf("\tFor Normal Press 2 (Enter Number!): \n");
	printf("\n");
	printf("\tFor Hard Press 3 (Enter Number!): \n");
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
		num[i] = rand() %8;
	} // for

	printf("\n\n\t\t\t    Mastermind Code: ");

	for (i = 0; i <= length; i++)
	{
		printf(" ? ");
	} // for

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

		printf("\n\tNumber of chances: %d", chances);
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
				right++;
			}
			else
			{
				printf(" ? ");
			}
		}
		printf("\n");
								//  Easy Win =============================================
		if (option == 1)
		{
			if (guess[0] == num[0] && guess[1] == num[1] && guess[2] == num[2] && guess[3] == num[3])
			{
				printf("=====================================================================\n");
				printf("\n\t   Well done ! you have completed Mastermind on Easy!!\n");
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
				chances--;
			}
		}
		else if (option == 2)			// Normal win ========================================
		{
			if (guess[0] == num[0] && guess[1] == num[1] && guess[2] == num[2] && guess[3] == num[3])
			{
				printf("=====================================================================\n");
				printf("\n\t   Congrats!  you have completed Mastermind on Normal!!\n");
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
				chances--;
			}
		}
		else if (option == 3)		// Hard win ====================================================
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
				chances--;
			}
		}
		if (chances < 1)
		{
			printf("\n");
			printf("\n\t   ===================== GAME OVER!  =====================");
			printf("\n\t   ===================  Out of chances!  ===================");
			printf("\n\t\tThank you for playing Mastermind!");
			printf("\n\t   You found a right number %d times before you ran out of chances!", right);
			printf("\n");
			printf("\n");
			printf("   Enter 1 to Play again, Enter 2 to go to Instruction Menu , or Enter 3 to Exit : ");
			scanf_s(" %d", &choice);

			while (choice != 1 || choice != 2 || choice != 3)
			{

				if (choice == 1)
				{
					menu();
				}

				else if (choice == 2)
				{
					help();
				}

				else if (choice == 3)
				{
					exit(0);
				}
				else
				{
					printf("\nError in your Decision!....\nPlease pick either 1 to Play, 2 to see how to play or 3 to EXIT!");
					printf("\nThank you!\n");
					scanf_s(" %d", &choice);
				}
				printf("=====================================================================\n");
				printf("\n");
			} // while

		} // If
	
		
	} // first menu() While
}

void help(void)
{
	printf("\n");
	printf("\t\t\tMastermind Info Page!\n");
	printf("\t================================================================\n");
	printf("\tMastermind is a game where the user guesses numbers that \n");
	printf("\thave been randomly generated by the computer.\n");
	printf("\tThe code is totally unknown and contains the numbers from 1 - 7.\n");
	printf("\tEach number corresponds to a colour of the rainbow:\n\n");
	printf("\t1 = Red\n\t2 = Orange\n\t3 = Yellow\n\t4 = Green\n\t5 = Blue\n");
	printf("\t6 = Indigo\n\t7 = Violet\n");
	printf("\n\tThere are 3 difficulty levels.\n\tEvery difficulty level allows the player to \n\tenter a MAX amount of trys to play the game!\n");
	printf("\tThe MAX amounts decrease the higher the difficulty!\n");
	printf("\n\tEvery \'?\' you see is an unknown number in the code.\n");
	printf("\tIf a number is right it is then revealed.\n");
	printf("\n");
	printf("To start playing press 1 ");
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
			printf("\nTo bad your Leaving.. Good Bye!");
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
} // help menu