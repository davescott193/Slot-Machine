#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;


int main() {
	//variables included in the project
	//menu
	int menu = 0, Input, tokens, allowance = 1, confirm;
	//slot machine
	int x = 0, y = 0, z = 0, spinning;

	srand(time(0));
	tokens = 2000;
	while (menu != 4)
	{
		cout << "Player's Tokens: " << tokens << "\n\nChoose an option:  1 - 4" << " \n1] Play Slot Machine \n2] Multipliers and Credits \n3] Top-up\n4] Quit Slot Machine\n";

		cin >> menu;
		system("cls");

		// Checks that the player doesn;t input anything other than 1-4
		if (cin.fail() == 1)
		{
			cin.clear();
			cin.ignore(999, '\n'); //Clears 999 letters to clear the cin
		}


		switch (menu)
		{
		case 1:
			//Slot Machine
			cout << "Enter a bet: ";
			cin >> Input;//recieves player bet
			system("cls");
			if (cin.fail() == 1)//checks validity of bet
			{
				cin.clear();
				cin.ignore(999, '\n');
				break;
			}
			if (Input >= tokens)//check if the player can place a bet
			{
				cout << "Not enough tokens to make bet\n\n";
				break;
			}
			tokens = tokens - Input;

			for (spinning = 0; spinning < 10; spinning++)//animation for the slotmachine
			{
				x = 2 + (rand() % 6);//randomizer making each roll random between 2-7
				y = 2 + (rand() % 6);
				z = 2 + (rand() % 6);
				cout << "| " << " " << " | " << " " << " | " << " " << " |\n";
				cout << "| " << x << " | " << y << " | " << z << " |\n";
				cout << "| " << " " << " | " << " " << " | " << " " << " |\n\n";

				Sleep(300);
				system("cls");
			}
			cout << "You bet " << Input << " on " << tokens << " tokens" << "\n";
			cout << "| " << x << " | " << y << " | " << z << " | " << endl;//user feedback on the round they had

			//REWARDS
			if (x == y && y == z)
			{
				if (x == 7)
				{
					cout << "JACKPOT\n7's IN A ROW!!!!\n\n" << endl;
					Input *= 10; // 10x winnings
					tokens += Input;
				}
				else
				{
					cout << "you Win, Three in a row!\n\n" << endl;
					Input *= 5; // 5x winnings
					tokens += Input;
				}
			}
			else if (x == y || x == z || y == z)
			{
				Input *= 3; //3x winnings
				tokens += Input;
				cout << "You Win, Two in a row!\n\n";


			}
			else
			{
				cout << "You Lose!" << endl;
				cout << "\n";
				if (tokens == 0)//feedback to player that they have no chips
				{
					cout << "You don't have enough tokens to continue playing\nCome again another time";
					return 0;
				}
			}
			break;

		case 2://credits and Multipliers
			cout << "Two of the same number in a row grants a three times multiplier on initial bet\nThree in a row grants a five times multiplier on initial bet\nThree 7s in a row is the JACKPOT and grants a ten time multiplier on the initial bet\n";
			cout << "Code was made by\nDavid Scott" << "\n\n";
			break;

		case 3://A system i created where the player can top up chips if they have run out. on a one time offer
			if (allowance == 1)
			{
				cout << "Do you wish to top up your tokens.\nThe first one is on the house\nEnter  1 for 'Yes' and 0 for 'No'\n";
				cin >> confirm;
				system("cls");
				if (cin.fail() == 1)
				{
					cin.clear();
					cin.ignore(999, '\n');
					break;

				}
				if (confirm == 1)
				{
					cout << "you have topped up your credit successfully!\n";
					tokens += 2000;
					cout << "\n\n";
					allowance -= 1;
				}
				else if (confirm == 0)
				{
					cout << "Carry on then\n\n";
				}
			}
			else
			{
				cout << "Sorry you can not get any more tokens\n\n";
			}


			break;
		case 4://Exit game
			cout << "Thanks for Playing" << endl;
			Sleep(500);

			break;
		default://menu default
			cout << "Please input a number between 1 - 4\n\n";


		}
	}
}







