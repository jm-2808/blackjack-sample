#ifndef PlayerH
#define PlayerH

#include <sstream>
#include <string>
#include <vector>
#include "Card.h"
using namespace std;

class Player
{
public:
	Player(string n);
	~Player();

	const string GetName() const;			// Get the player's name
	void SetName(const string);				// Set the player's name

	void DealCard(const Card);				// Add a card to the player's hand
	const bool IsHandEmpty() const;			// Check if the player's hand is empty
	const int GetNumberOfCards() const;		// Get the number of cards in the player's hand
	const int HandTotal() const;			// Get the total value of the player's hand
	void FlipHand();						// Turn over the player's current hand
	void FlipCard(int);						// Turn over a specific card
	ostream& RenderHand(ostream&);			// Output the player's hand

	void Stand();							// Set player to be waiting for game end
	const bool IsStanding() const;			// Is the player standing?

	void Out();								// Set player to be out of the game
	const bool IsOut() const;				// Is the player out of the game?
private:
	string name_;							// The player's name
	vector<Card> hand_;						// The player's hand
	bool stand_;							// True = player has stuck and cannot accept more cards
											// False = player is still in the game
	bool out_;								// True = player is out
											// False = player is still in the game
};

ostream& operator<<(ostream&, Player&);

#endif