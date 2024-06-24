#include "Player.h"

//========== Public functions ==========//
Player::Player(string n)
	: name_(n), stand_(false), out_(false)
{}
Player::~Player()
{}

const string Player::GetName() const
{
	return name_;
}
void Player::SetName(const string n) 
{
	name_ = n;
}

void Player::DealCard(const Card c)
{
	hand_.push_back(c);
}
const bool Player::IsHandEmpty() const
{
	return (hand_.size() == 0);
}
const int Player::GetNumberOfCards() const
{
	return hand_.size();
}
const int Player::HandTotal() const
{
	int total = 0;
	if (!IsHandEmpty())
	{
		for (int i = 0; i < hand_.size(); i++)
		{
			if (hand_[i].IsVisible())					// Only add to total if card is visible
			{
				int value = hand_[i].GetValue();		// Get the card's value

				if (value > 10)							// Face cards (11 [Jack], 12 [Queen], 13 [King]) are worth 10
					value = 10;
				else if (value == 1)					// [Ace] is 1 or 11, assumed 11 in this program
					value = 11;

				total += value;							// Add to the running total
			}
		}

		if (total > 21)
		{
			for (int i = 0; i < hand_.size(); i++)		// check if hand is over 21 but has an ace that can be counted as a 1
			{
				if (hand_[i].GetValue() == 1)
					total -= 10;
			}
		}
	}
	return total;
}
void Player::FlipHand()
{
	for (int i = 0; i < hand_.size(); i++)
	{
		hand_[i].Flip();
	}
}
void Player::FlipCard(int pos)
{
	if(pos <= hand_.size())
		hand_[pos].Flip();
}
ostream& Player::RenderHand(ostream& os)
{
	if (!IsHandEmpty())
	{
		os << " " << GetName() << "'s hand: \n";

		vector<string> output;

		for each (Card c in hand_)						// For each card in a player's hand, get it's appearence and add it to the vector
		{
			string cardAppearence[CardSize];
			c.GetCardAppearence(cardAppearence);
			for (int i = 0; i < CardSize; i++)
			{
				output.push_back(cardAppearence[i]);
			}
		}

		for (int i = 0; i < CardSize; i++)				// Display the cards in the vector in a row
		{
			os << output[i] << " ";
			for (int cardNo = 1; cardNo < hand_.size(); cardNo++)
			{
				int c = (CardSize * cardNo);
				os << output[i + c] << " ";
			}
			os << "\n";
		}
		for (int cardNo = 0; cardNo < hand_.size(); cardNo++)		// Display card names
		{
			int c = (CardSize * cardNo);
			if (hand_[cardNo].IsVisible())
				os << hand_[cardNo].GetName() << " ";
		}
		os << "\n\n"  << " Hand total: " << HandTotal() << "\n";
		os << "\n";
	}
	else
		os << "Empty hand";
	return os;
}

void Player::Stand()
{
	stand_ = true;
}
const bool Player::IsStanding() const
{
	return stand_;
}

void Player::Out()
{
	out_ = true;
}
const bool Player::IsOut() const
{
	return out_;
}

//========== Private functions ==========//

//========== External functions ==========//
ostream& operator<<(ostream& os, Player& p)
{
	return p.RenderHand(os);
}