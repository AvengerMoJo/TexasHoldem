#include "Deck.h" 

Deck::Deck()
{
	initilized=false;
	init(); 
}

inline void Deck::init()
{
	if( initilized ) return; 
	for( int i=0; i < SUITSIZE; i++){
		for( int j=0; j < CARDVALUESIZE; j++){
			cards[i*CARDVALUESIZE + j] = new Card( Card::Suit(i), Card::CardValue(j) );
		}
	}
	initilized = true;
}

inline void Deck::spaceTheDeck()
{
	if( ! initilized ) return; 
	for( int i=0; i < DECKSIZE; i++){
		delete cards[i];
	}
	initilized = false;
	init(); 
}


void Deck::RiffleShuffle()
{
}

string Deck::toString()
{
	string buffer;
	for( int i=0; i< DECKSIZE; i++ ){
		buffer = buffer + cards[i]->toString() + "\n";
	}
	return buffer;
}
