//=======================================================================//
//																		 //
//					Blackjack[21] console application					 //
//				Last edited by: Jack Magnay		20/02/2018				 //
//																		 //
//=======================================================================//

#include "UserInterface.h"
#include "Game.h"
#include "RandomNumberGenerator.h"
using namespace std;

int main()
{
	UserInterface ui;
	RandomNumberGenerator rng;
	Game blackjack(&ui, &rng);

	cout << "\n";
	system("pause");
	return(0);
}