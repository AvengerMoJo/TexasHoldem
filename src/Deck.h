#ifndef __DECK__
#define __DECK__

#include <iostream>
#include <string>

#include <sys/types.h>	// size_t
#include <sys/stat.h>	// open
#include <fcntl.h>	// open
#include <stdlib.h>	// for random number
#include <time.h>	// for seeding random number
#include <unistd.h>	// for pid that complicate the seed
#include "Card.h" 

using namespace std;

#define DECKSIZE 52

class Deck { 

public:
	Deck();
	void quickShuffle();
	void riffleShuffle();
	string toString();
	unsigned int getRandomSeed();	// read a byte out of urandom
	
private:
	Card* cards[DECKSIZE]; 
	bool  initilized;

	inline void init();		// initialize the deck 
	inline void spaceTheDeck();	// rebuild a new deck
	inline void swapCards(int,int);	// swaping two card position
		
};

#endif
