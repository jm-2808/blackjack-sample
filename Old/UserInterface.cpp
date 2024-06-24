#include "UserInterface.h"

//========== Public functions ==========//
UserInterface::UserInterface()
{}
UserInterface::~UserInterface()
{}

const int UserInterface::GetPlayerChoice(const int max) const
{
	bool validInput = false;
	int choice(5);
	
	cout << "Enter selection: ";
	do									// Loop until a valid input is provided
	{
		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input, try again: ";
		}
		else
		{
			if ((choice < 0 || choice > max))
				cout << "Invalid input, try again: ";
			else
				validInput = true;
		}
	} while (!validInput);

	cout << "\n";
	return choice;
}
const int UserInterface::GetNumberOfPlayers() const
{
	bool validInput = false;
	int players;

	cout << "Enter the number of players: ";
	do									// Loop until a valid input is provided
	{
		cin >> players;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input, try again: ";
		}
		else
		{
			if (players == 0)
				cout << "There cannot be 0 players, try again: ";
			else if (players > 5)
				cout << "Too many players, try again: ";
			else
				validInput = true;
		}
	} while (!validInput);

	return players;
}
const string UserInterface::GetPlayerName(const int playerNo) const
{
	bool validInput = false;
	string name;

	cout << "Enter Player " << playerNo << "'s name: ";
	cin >> name;
	
	return name;
}

void UserInterface::DisplayMainMenu() const
{
	cout << "                           __ " << "\n";
	cout << "                     _..-''--'----_. " << "\n";
	cout << "                   ,''.-''| .---/ _`-._ " << "\n";
	cout << "                 ,' \\ \\  ;| | ,/ / `-._`-. " << "\n";
	cout << "               ,' ,',\\ \\( | |// /,-._  / / " << "\n";
	cout << "               ;.`. `,\\ \\`| |/ / |   )/ / " << "\n";
	cout << "              / /`_`.\\_\\ \\| /_.-.'-''/ / " << "\n";
	cout << "             / /_|_:.`. \\ |;'`..')  / / " << "\n";
	cout << "             `-._`-._`.`.;`.\\  ,'  / / " << "\n";
	cout << "                 `-._`.`/    ,'-._/ / " << "\n";
	cout << "                   : `-/     \\`-.._/ " << "\n";
	cout << "                   |  :      ;._ ( " << "\n";
	cout << "                   :  |      \\  ` \\ " << "\n";
	cout << "                    \\         \\   | " << "\n";
	cout << "       ____  _            _     _            _     " << "\n";
	cout << "      | __ )| | __ _  ___| | __(_) __ _  ___| | __ " << "\n";
	cout << "      |  _ \\| |/ _` |/ __| |/ /| |/ _` |/ __| |/ / " << "\n";
	cout << "      | |_) | | (_| | (__|   < | | (_| | (__|   <  " << "\n";
	cout << "      |____/|_|\\__,_|\\___|_|\\_\\/ |\\__,_|\\___|_|\\_\\ " << "\n";
	cout << "                             |__/                   21" << "\n";
	cout << "\n" << "\n";
	cout << "                           1. Play" << "\n";
	cout << "                           2. Help" << "\n";
	cout << "                           0. Quit" << "\n\n";
	cout << "                      ";
}
void UserInterface::DisplayRules() const
{
	cout << "=============================================================" << "\n";
	cout << "                        How to play" << "\n";
	cout << "=============================================================" << "\n";
	cout << "\n";
	cout << "The aim of the game is to get as close to 21 as possible" << "\n";
	cout << "without going over it, otherwise you are out." << "\n";
	cout << "\n";
	cout << "At the start of the game, each player is dealt 2 random cards." << "\n";
	cout << "The player then has multiple options: " << "\n";
	cout << "1. Hit       - Draw another card from the deck to add to your " << "\n";
	cout << "2. Stand     - Cease the abilty to draw additional cards, but" << "\n";
	cout << "               keep hand any cards currently held. This may only" << "\n";
	cout << "               be done if the player hand totals at 17 or over" << "\n";
	cout << "3. Surrender - Forfeit the game. This can only be done on the" << "\n";
	cout << "               turn in which the player is dealt their starting" << "\n";
	cout << "               hand" << "\n";
	cout << "\n";
	cout << "=============================================================" << "\n";
	cout << "                          Scoring" << "\n";
	cout << "=============================================================" << "\n";
	cout << "In this game, any face card is worth 10 points (King, Queen " << "\n";
	cout << "and Jack), a numbered card is worth it's face value and an Ace" << "\n";
	cout << "is worth either 1 or 11 depending on the player's choice." << "\n";
	cout << "\n";
	cout << "=============================================================" << "\n";
	cout << "                           Naturals" << "\n";
	cout << "=============================================================" << "\n";
	cout << "If a player is dealt an Ace and a 10 at the start of the game," << "\n";
	cout << "this is a natural or Blackjack. This is essentially an instant" << "\n";
	cout << "win, though the player will still have to wait for other players" << "\n";
	cout << "to finish their set of turns." << "\n";
	cout << "\n";
	system("pause");
}
void UserInterface::DisplaySetupTitle() const
{
	cout << "=============================================================" << "\n";
	cout << "                           SETUP" << "\n";
	cout << "=============================================================" << "\n\n";
}
void UserInterface::DisplayRoundTitle(int round) const
{
	cout << "=============================================================" << "\n";
	cout << "                           ROUND " << round << "\n";
	cout << "=============================================================" << "\n\n";
}
void UserInterface::DisplayPlayer(Player p) const
{
	cout << p;
}
void UserInterface::DisplayPlayerActions() const
{
	cout << " 1. Hit" << "\n";
	cout << " 2. Stand" << "\n";
	cout << " 3. Surrender" << "\n";
	cout << " 0. Quit" << "\n";
	cout << " ";
}
void UserInterface::DisplayWinnerTitle(string winMessage) const
{
	cout << "=============================================================" << "\n";
	cout << winMessage << "\n";
	cout << "=============================================================" << "\n\n";
}

void UserInterface::DisplayMessage(string msg) const
{
	cout << msg << "\n";
}

void UserInterface::ClearScreen()
{
	system("CLS");
}

//========== Private functions ==========//

//========== External functions ==========//