#include "Card.h" 

#define DECKSIZE 52

class Deck { 

public:
	Deck(){ init(); };
	

private:
	Card* cards[DECKSIZE]; 

	inline init(){
		for( int i=0; i < SUITSIZE; i++){
			for( int j=0; j < CARDVALUESIZE; j++){
				cards[i*CARDVALUESIZE + j] = new Card( Suit[i], CardValue[j] ); 
			}
		}
	}
}
