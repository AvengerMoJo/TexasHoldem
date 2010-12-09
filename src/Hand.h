#ifndef __HAND__
#define __HAND__

#include <iostream>
#include <inttypes.h>
#include "Card.h"

using namespace std;

class Hand {
public:
	enum Stage { Start, Hole, Flop, Turn, River }; 
	static const int SuitShift[SUITSIZE];

	Hand();

	void setHole( Card*, Card* );		// setting cards in Hands
	void setFlop( Card*, Card*, Card* );	// setting cards after Flop
	void setTurn( Card* );			// setting card after Turn
	void setRiver( Card* );			// setting card after River

	//string getHighestValue();
	bool isStraightFlush();
	bool isFourOfAKind();
	bool isFullHouse();
	bool isFlush();
	bool isStraight();

private:
	inline void init();
	inline int lowBit( unsigned int);

	int flush;
	int straight[SUITSIZE];
	int handvalue;

	int highcard;

	bool straightflush; 
	bool fullhouse; 
	bool fourofakind; 
	bool threeofakind; 

	Stage stage;
	Card* hole[2];
	Card* flop[3];
	Card* turn;
	Card* river;
};

#endif
