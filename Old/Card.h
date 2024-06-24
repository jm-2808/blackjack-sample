#ifndef CardH
#define CardH

#define CardSize 14										// Number of line the card occupies in the console

#include <sstream>
#include <string>
using namespace std;

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

class Card
{
public:
	Card();
	Card(Suit s, int v);
	~Card();
	const int GetValue() const;							// Get the card's value
	const string GetName() const;						// Get the card's name

	void Flip();										// Flip the card over

	const bool IsVisible() const;						// Is the card's face visible?

	const void GetCardAppearence(string[14]) const;		// Get card's appearence
	ostream& Render(ostream&);							// Output the card's appearence
private:
	Suit suit_;								// The card's suit
	int value_;								// The card's value (1 = [Ace], 11 = [Jack], 12 = [Queen], 13 = [King])
	string name_;

	bool faceVisible_;						// Is the card's face visible?
};

ostream& operator<<(ostream&, Card&);

#endif