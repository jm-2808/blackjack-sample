#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator()
{
	seed();	
}
void RandomNumberGenerator::seed()
{
	srand(static_cast<unsigned int>(time(0)));
}
int RandomNumberGenerator::GetRandomValue(int max) const
{
	return (rand() % max) + 1; 
}