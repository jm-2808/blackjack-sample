#ifndef RngH
#define RngH

#include <ctime>
#include <iostream>

using namespace std;

class RandomNumberGenerator
{
public:
	RandomNumberGenerator();
	int GetRandomValue(int) const;	// Produce a random number in range [1..max]
private:
	void seed();					// Reset the random number generator from the current system time
};

#endif
