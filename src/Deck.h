#ifndef __DECK__
#define __DECK__

#include <string>
#include "Card.h" 

using namespace std;

#define DECKSIZE 52

class Deck { 

public:
	Deck();
	void RiffleShuffle();
	string toString();
	
private:
	Card* cards[DECKSIZE]; 
	bool  initilized;

	inline void init();		// initialize the deck 
	inline void spaceTheDeck();	// rebuild a new deck
		
};

#endif
