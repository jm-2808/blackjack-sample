#include "Card.h"

//========== Public functions ==========//
Card::Card()
	: faceVisible_(false)
{}
Card::Card(Suit s, int v)
	: suit_(s), value_(v), faceVisible_(true)
{}
Card::~Card()
{}

const int Card::GetValue() const
{
	return value_;
}

const string Card::GetName() const
{
	ostringstream name;
	switch (suit_)	// Determine card's suit					// Spacing guide
	{
	case CLUBS:
	{
		if (value_ == 1) // Determine card's value				//".------------------."
			name << "   Ace" << " of " << "Clubs     ";			//"   Ace of Clubs     "
		else if (value_ == 11)
			name << "  Jack" << " of " << "Clubs     ";			//"  Jack of Clubs     "
		else if (value_ == 12)					     
			name << " Queen" << " of " << "Clubs     ";			//" Queen of Clubs     "
		else if (value_ == 13)					     
			name << "  King" << " of " << "Clubs     ";			//"  King of Clubs     "
		else if (value_ == 10)
			name << "   " << value_ << " of " << "Clubs      ";	//"   10 of Clubs      "
		else
			name << "    " << value_ << " of " << "Clubs      ";//"    5 of Clubs      "

		break;
	}
	case DIAMONDS:
	{
		if (value_ == 1) // Determine card's value				//".------------------."
			name << "   Ace" << " of " << "Diamonds  ";			//"   Ace of Diamonds  "
		else if (value_ == 11)					     
			name << "  Jack" << " of " << "Diamonds  ";			//"  Jack of Diamonds  "
		else if (value_ == 12)					     
			name << " Queen" << " of " << "Diamonds  ";			//" Queen of Diamonds  "
		else if (value_ == 13)					     
			name << "  King" << " of " << "Diamonds  ";			//"  King of Diamonds  "
		else if (value_ == 10)
			name << "   " << value_ << " of " << "Diamonds   ";	//"   10 of Diamonds   "
		else
			name << "    " << value_ << " of " << "Diamonds   ";//"    5 of Diamonds   "

		break;
	}
	case HEARTS:
	{
		if (value_ == 1) // Determine card's value				//".------------------."
			name << "   Ace" << " of " << "Hearts    ";			//"   Ace of Hearts    "
		else if (value_ == 11)					     
			name << "  Jack" << " of " << "Hearts    ";			//"  Jack of Hearts    "
		else if (value_ == 12)					     
			name << " Queen" << " of " << "Hearts    ";			//" Queen of Hearts    "
		else if (value_ == 13)					     
			name << "  King" << " of " << "Hearts    ";			//"  King of Hearts    "
		else if (value_ == 10)
			name << "   " << value_ << " of " << "Hearts     ";	//"   10 of Hearts     "
		else
			name << "    " << value_ << " of " << "Hearts     ";//"    5 of Hearts     "

		break;
	}
	case SPADES:
	{
		if (value_ == 1) // Determine card's value				//".------------------."
			name << "   Ace" << " of " << "Spades    ";			//"   Ace of Spades    "
		else if (value_ == 11)
			name << "  Jack" << " of " << "Spades    ";			//"  Jack of Spades    "
		else if (value_ == 12)
			name << " Queen" << " of " << "Spades    ";			//" Queen of Spades    "
		else if (value_ == 13)
			name << "  King" << " of " << "Spades    ";			//"  King of Spades    "
		else if (value_ == 10)
			name << "   " << value_ << " of " << "Spades     ";	//"   10 of Spades     "
		else
			name << "    " << value_ << " of " << "Spades     ";//"    5 of Spades     "

		break;
	}
	}
	return name.str();
}

void Card::Flip()
{
	faceVisible_ = !faceVisible_;
}

const bool Card::IsVisible() const
{
	return faceVisible_;
}

const void Card::GetCardAppearence(string c[CardSize]) const // Build the card's appearence into a string vector
{	
	if (faceVisible_)					// Card face up
	{
		char valueSymbol;				// Set the symbol to represent the card's value
		if (value_ == 1)
			valueSymbol = 'A';
		else if (value_ == 11)
			valueSymbol = 'J';
		else if (value_ == 12)
			valueSymbol = 'Q';
		else if (value_ == 13)
			valueSymbol = 'K';
		else
			valueSymbol = value_ + '0';

		if (value_ == 10)
		{
			c[0] = ".------------------.";
			c[1] = "| 10               |";
			c[2] = "|                  |";
		}
		else
		{
			ostringstream topLine;
			c[0] = ".------------------.";
			topLine << "| " << valueSymbol << "                |";
			c[1] = topLine.str();
			c[2] = "|                  |";
		}
		switch (suit_)
		{
		case CLUBS:
		{
			c[3] =	"|      .-~~-.      |";
			c[4] =	"|     {      }     |";
			c[5] =	"|  .-~-.    .-~-.  |";
			c[6] =	"| {              } |";
			c[7] =	"|  `.__.'||`.__.'  |";
			c[8] =	"|        ||        |";
			c[9] =	"|       '--`       |";
			c[10] = "|                  |";
			break;
		}
		case DIAMONDS:
		{
			c[3] =	"|        /\\        |";
			c[4] =	"|      .'  `.      |";
			c[5] =	"|     '      `.    |";
			c[6] =	"|   <          >   |";
			c[7] =	"|    `.      .'    |";
			c[8] =	"|      `.  .'      |";
			c[9] =	"|        \\/        |";
			c[10] = "|                  |";
			break;
		}
		case HEARTS:
		{
			c[3] =	"|                  |";
			c[4] =	"|  .-~~~-__-~~~-.  |";
			c[5] =	"| {              } |";
			c[6] =	"|  `.          .'  |";
			c[7] =	"|    `.      .'    |";
			c[8] =	"|      `.  .'      |";
			c[9] =	"|        \\/        |";
			c[10] = "|                  |";
			break;
		}
		case SPADES:
		{
			c[3] =	"|        /\\        |";
			c[4] =	"|      .'  `.      |";
			c[5] =	"|     '      `.    |";
			c[6] =	"|  .'          `.  |";
			c[7] =	"| {              } |";
			c[8] =	"|  ~-...-||-...-~  |";
			c[9] =	"|        ||        |";
			c[10] = "|       '--`       |";
			break;
		}
		}
		if (value_ == 10)
		{
			c[11] = "|                  |";
			c[12] = "|               10 |";
			c[13] = "'------------------'";
		}
		else
		{
			ostringstream bottomLine;
			c[11] = "|                  |";
			bottomLine << "|                " << valueSymbol << " |";
			c[12] = bottomLine.str();
			c[13] = "'------------------'";
		}
	}
	else								// Card face down
	{
		c[0] =	".------------------.";
		c[1] =	"|##################|";
		c[2] =	"|##################|";
		c[3] =	"|##################|";
		c[4] =	"|##################|";
		c[5] =	"|##################|";
		c[6] =	"|##################|";
		c[7] =	"|##################|";
		c[8] =	"|##################|";
		c[9] =	"|##################|";
		c[10] = "|##################|";
		c[11] = "|##################|";
		c[12] = "|##################|";
		c[13] = "'------------------'";
	}
}
ostream& Card::Render(ostream& os)
{
	string cardAppearence[CardSize];
	GetCardAppearence(cardAppearence);

	for (int i = 0; i < CardSize; i++)
	{
		os << cardAppearence[i] << "\n";
	}

	return os;
}

//========== Private functions ==========//


//========== External functions ==========//
ostream& operator<<(ostream& os, Card& c)
{
	return c.Render(os);
}
