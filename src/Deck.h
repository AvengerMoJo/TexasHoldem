<<<<<<< HEAD
#ifndef __DECK__
#define __DECK__

#include <string>
#include "Card.h" 

using namespace std;

=======
#include "Card.h" 

>>>>>>> 1080f3791e4f716103edbacae7760f3f9a68c192
#define DECKSIZE 52

class Deck { 

public:
	Deck();
	string toString(){ 
		string buffer;
		for( int i=0; i< DECKSIZE; i++ ){
			buffer = buffer + cards[i]->toString() + "\n"; 
		}
		return buffer; 
	};
	Deck(){ init(); };
	
private:
	Card* cards[DECKSIZE]; 

	inline void init(){
		for( int i=0; i < SUITSIZE; i++){
			for( int j=0; j < CARDVALUESIZE; j++){
				cards[i*CARDVALUESIZE + j] = new Card( Card::Suit(i), Card::CardValue(j) ); 
			}
		}
	};
};

#endif
