#ifndef UiH
#define UiH

#include <iostream>
#include <sstream>
#include <string>
#include "Player.h"
using namespace std;

class UserInterface
{
public:
	UserInterface();
	~UserInterface();

	const int GetPlayerChoice(const int) const;			// Get the player's selection
	const int GetNumberOfPlayers() const;				// Get the number of players in the game
	const string GetPlayerName(const int) const;		// Get the player's name

	void DisplayMainMenu() const;						// Output main menu to the console
	void DisplayRules() const;							// Output the game's rules to the console
	void DisplaySetupTitle() const;						// Output the title for the setup screen to the console
	void DisplayRoundTitle(int) const;					// Output round title to the console
	void DisplayPlayer(Player) const;					// Output each player's cards to the console
	void DisplayPlayerActions() const;					// Output the player's actions to the console
	void DisplayWinnerTitle(string) const;					// output winner title to the console
	
	void DisplayMessage(string) const;					// Output a message (error handling/warnings) to the console

	void ClearScreen();									// Clear the console window to redraw
private:

};

#endif