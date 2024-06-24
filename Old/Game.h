#ifndef GameH
#define GameH

#include <windows.h>
#include <vector>
#include "UserInterface.h"
#include "RandomNumberGenerator.h"
#include "Player.h"
#include "Card.h"

#define DELAY 1000

class Game
{
public:
	Game(UserInterface*, RandomNumberGenerator*);
	~Game();
private:
	UserInterface* p_ui_;					// Pointer to the user interface
	RandomNumberGenerator* p_rng_;			// Pointer to the random number generator

	vector<Card> deck_;						// The deck of cards
	void InitialiseDeck();					// Add Cards to the deck
	Card DrawCard();						// Draw a random card from the deck
	void ReturnCard(const Card);			// Return a card to the deck

	vector<Player> players_;				// The players
	Player dealer_;							// The dealer
	void AddPlayer(const Player);			// Add a new player

	void MainMenu();						// Main menu
	void SetupGame();						// Setup the game
	void Run();								// Run the main game

	const bool IsGameOver() const;			// Check if a player has won

	void CheckWinner();						// Check who has won

	void DEBUG_DeckPrint();					// DEBUG: Print entire deck
};
#endif