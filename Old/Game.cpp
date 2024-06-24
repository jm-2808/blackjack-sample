#include "Game.h"
//========== Public functions ==========//
Game::Game(UserInterface* ui, RandomNumberGenerator* rng)
	: p_ui_(ui), p_rng_(rng), dealer_("THE DEALER")
{	
	MainMenu();
}
Game::~Game()
{}

//========== Private functions ==========//
void Game::InitialiseDeck()
{
	deck_.clear();
	Suit suit;
	for (int s = 0; s < 4; s++)				// Suit
	{
		if (s == 0)
			suit = CLUBS;
		else if (s == 1)
			suit = DIAMONDS;
		else if (s == 2)
			suit = HEARTS;
		else if (s == 3)
			suit = SPADES;

		for (int c = 0; c < 13; c++)		// Card
		{
			Card card(suit, (c + 1));
			card.Flip();
			deck_.push_back(card);
		}
	}
}

Card Game::DrawCard()
{
	int position = (p_rng_->GetRandomValue(deck_.size()) - 1);
	Card c = deck_[position];
	deck_.erase(deck_.begin() + position);
	return c;
}

void Game::ReturnCard(const Card c)
{
	deck_.push_back(c);
}

void Game::AddPlayer(const Player p)
{
	players_.push_back(p);
}

void Game::MainMenu()
{
	bool quit = false;
	do
	{
		p_ui_->ClearScreen();
		p_ui_->DisplayMainMenu();
		switch (p_ui_->GetPlayerChoice(2))
		{
		case 1:
			p_ui_->ClearScreen();
			SetupGame();
			break;
		case 2:
			p_ui_->ClearScreen();
			p_ui_->DisplayRules();
			break;
		case 0:
			quit = true;
			break;
		}
	} while (!quit);
}

void Game::SetupGame()
{
	InitialiseDeck();
	players_.clear();
	dealer_ = Player("THE DEALER");

	p_ui_->DisplaySetupTitle();
	int noOfPlayers = p_ui_->GetNumberOfPlayers();

	// Players
	for (int i = 0; i < noOfPlayers; i++)
	{
		p_ui_->ClearScreen();
		p_ui_->DisplaySetupTitle();				// Show title

		AddPlayer(p_ui_->GetPlayerName(i + 1));	// Get player's name and add them to the roster
		p_ui_->ClearScreen();
		p_ui_->DisplaySetupTitle();

		players_[i].DealCard(DrawCard());		// Deal the new player 2 cards
		players_[i].DealCard(DrawCard());

		p_ui_->DisplayPlayer(players_[i]);		// Display cards face down
		Sleep(DELAY);
		p_ui_->ClearScreen();

		players_[i].FlipHand();					// Flip cards

		p_ui_->DisplaySetupTitle();
		p_ui_->DisplayPlayer(players_[i]);		// Display cards face up

		system("pause");
	}

	// Dealer
	p_ui_->ClearScreen();
	p_ui_->DisplaySetupTitle();

	dealer_.DealCard(DrawCard());				// Deal the dealer 2 cards
	dealer_.DealCard(DrawCard());

	p_ui_->DisplayPlayer(dealer_);				// Display dealer's cards face down
	Sleep(DELAY);
	
	dealer_.FlipCard(0);						// Flip fist card

	p_ui_->ClearScreen();
	p_ui_->DisplaySetupTitle();
	p_ui_->DisplayPlayer(dealer_);				// Display dealer's cards again
	system("pause");
	Run();
}

void Game::Run()
{
	bool gameOver = false;
	bool quit = false;
	int round = 1;

	do
	{
		// Player(s)
		for (int i = 0; i < players_.size(); i++)
		{
			Player* currentPlayer = &(players_[i]);									// Pointer to the current player

			p_ui_->ClearScreen();
			p_ui_->DisplayRoundTitle(round);
			p_ui_->DisplayPlayer((*currentPlayer));

			if (!currentPlayer->IsOut() && !currentPlayer->IsStanding())			// Player actions
			{
				p_ui_->DisplayPlayerActions();
				switch (p_ui_->GetPlayerChoice(3))
				{
				case 1:			// Hit
					currentPlayer->DealCard(DrawCard());							// Deal card

					p_ui_->ClearScreen();
					p_ui_->DisplayRoundTitle(round);
					p_ui_->DisplayPlayer((*currentPlayer));							// Display card face down for dramatic effect

					Sleep(DELAY);

					currentPlayer->FlipCard(currentPlayer->GetNumberOfCards() - 1);	// Flip card

					p_ui_->ClearScreen();
					p_ui_->DisplayRoundTitle(round);
					p_ui_->DisplayPlayer((*currentPlayer));							// Display card

					if (currentPlayer->HandTotal() > 21)							// If hand is over 21, player is out [Involuntary]
					{
						p_ui_->DisplayMessage(" Bust!\n");
						currentPlayer->Out();
					}
					system("pause");
					break;
				case 2:			// Stand
					if (currentPlayer->HandTotal() >= 17)
					{
						currentPlayer->Stand();											// Set player to "standing"
						p_ui_->ClearScreen();
						p_ui_->DisplayRoundTitle(round);
						p_ui_->DisplayPlayer((*currentPlayer));							// Display final hand
						p_ui_->DisplayMessage(" Standing!\n");
					}
					else
					{
						p_ui_->ClearScreen();
						p_ui_->DisplayRoundTitle(round);
						p_ui_->DisplayPlayer((*currentPlayer));
						p_ui_->DisplayMessage(" Cannot stand when hand total is under 17!\n");
					}
					system("pause");
					break;
				case 3:			// Surrender
					currentPlayer->Out();											// Set player to out [Voluntary]
					p_ui_->ClearScreen();
					p_ui_->DisplayRoundTitle(round);
					p_ui_->DisplayPlayer((*currentPlayer));							// Display final hand
					p_ui_->DisplayMessage(" Surrendered!\n");
					system("pause");
					break;
				case 0:			// Quit
					quit = true;
					break;
				}
			}
			else																	// Display appropriate message if player cannot act
			{
				if(currentPlayer->IsStanding())
					p_ui_->DisplayMessage(" Standing!\n");
				else
				{
					if (currentPlayer->HandTotal() > 21)
						p_ui_->DisplayMessage(" Bust!\n");
					else
						p_ui_->DisplayMessage(" Surrendered!\n");
				}
				system("pause");
			}

			if (quit) // Quit the game
				break;
		}

		if (!quit)													// Don't show dealer if player wishes to quit
		{
			// Dealer
			p_ui_->ClearScreen();
			p_ui_->DisplayRoundTitle(round);
			p_ui_->DisplayPlayer(dealer_);

			if (round == 1)
			{
				Sleep(DELAY);

				dealer_.FlipCard(dealer_.GetNumberOfCards() - 1);	// Flip hidden card

				p_ui_->ClearScreen();
				p_ui_->DisplayRoundTitle(round);
				p_ui_->DisplayPlayer(dealer_);					// Display card

				Sleep(DELAY);
			}
			if (dealer_.HandTotal() < 17)
			{
				dealer_.DealCard(DrawCard());							// Deal card

				p_ui_->ClearScreen();
				p_ui_->DisplayRoundTitle(round);
				p_ui_->DisplayPlayer(dealer_);							// Display card face down for dramatic effect

				Sleep(DELAY);

				dealer_.FlipCard(dealer_.GetNumberOfCards() - 1);	// Flip card

				p_ui_->ClearScreen();
				p_ui_->DisplayRoundTitle(round);
				p_ui_->DisplayPlayer(dealer_);							// Display card

				if (dealer_.HandTotal() > 21)							// If hand is over 21, player is out [Involuntary]
				{
					p_ui_->DisplayMessage(" Bust!\n");
					dealer_.Out();
				}
			}
			system("pause");
		}
		round++;
		gameOver = IsGameOver();
	} while (!gameOver && !quit);

	if (!quit)
	{
		CheckWinner();
		system("pause");
	}
}

const bool Game::IsGameOver() const
{
	bool gameOver = true;
	for (int i = 0; i < players_.size(); i++)
	{
		if (!players_[i].IsStanding() && !players_[i].IsOut())
			gameOver = false;
	}
	return gameOver;
}

void Game::CheckWinner()
{
	p_ui_->ClearScreen();
	Player highestScoringPlayer("Winner");
	for (int p = 0; p < players_.size(); p++)
	{
		if (!players_[p].IsOut())
		{
			if (players_[p].HandTotal() > highestScoringPlayer.HandTotal())
			{
				highestScoringPlayer = players_[p];
			}
		}
	}

	if (dealer_.IsOut())
	{
		if (highestScoringPlayer.HandTotal() == 21 && highestScoringPlayer.GetNumberOfCards() == 2) // Blackjack
		{
			p_ui_->DisplayWinnerTitle("                         BLACKJACK!");
			p_ui_->DisplayPlayer(highestScoringPlayer);
		}
		else
		{
			string s = "                         " + highestScoringPlayer.GetName() + " WINS";
			p_ui_->DisplayWinnerTitle(s);
			p_ui_->DisplayPlayer(highestScoringPlayer);
		}
	}
	else
	{
		if (highestScoringPlayer.HandTotal() == dealer_.HandTotal())		// Tie with dealer
		{
			p_ui_->DisplayWinnerTitle("                         ITS A TIE!");
			p_ui_->DisplayPlayer(dealer_);
			p_ui_->DisplayPlayer(highestScoringPlayer);
		}
		else if (highestScoringPlayer.HandTotal() < dealer_.HandTotal())	// Dealer wins
		{
			p_ui_->DisplayWinnerTitle("                         DEALER WINS");
			p_ui_->DisplayPlayer(dealer_);
		}
		else																// Player wins
		{
			if (highestScoringPlayer.HandTotal() == 21 && highestScoringPlayer.GetNumberOfCards() == 2) // Blackjack
			{
				p_ui_->DisplayWinnerTitle("                         BLACKJACK!");
				p_ui_->DisplayPlayer(highestScoringPlayer);
			}
			else
			{
				string s = "                         " + highestScoringPlayer.GetName() + " WINS";
				p_ui_->DisplayWinnerTitle(s);
				p_ui_->DisplayPlayer(highestScoringPlayer);
			}
		}
	}
}

//=== DEBUG ===//
void Game::DEBUG_DeckPrint()
{
	for (int c = 0; c < 13; c++)
	{
			string card1Appearence[CardSize];
			deck_[(13 * 0) + c].GetCardAppearence(card1Appearence);
			string card2Appearence[CardSize];
			deck_[(13 * 1) + c].GetCardAppearence(card2Appearence);
			string card3Appearence[CardSize];
			deck_[(13 * 2) + c].GetCardAppearence(card3Appearence);
			string card4Appearence[CardSize];
			deck_[(13 * 3) + c].GetCardAppearence(card4Appearence);

			vector<string> output;
			for (int i = 0; i < CardSize; i++)
			{
				cout << card1Appearence[i] << " ";
				cout << card2Appearence[i] << " ";
				cout << card3Appearence[i] << " ";
				cout << card4Appearence[i] << "\n";
			}
			cout 
				<< deck_[(13 * 0) + c].GetName() << " "
				<< deck_[(13 * 1) + c].GetName() << " " 
				<< deck_[(13 * 2) + c].GetName() << " " 
				<< deck_[(13 * 3) + c].GetName() << "\n";
	}
}

//========== External functions ==========//
