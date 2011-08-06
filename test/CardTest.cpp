#include <iostream>
#include "Card.h"

using namespace std;

typedef Card* Card_p; 

void printCard( Card_p* cards ){
	for( int s=0; s<SUITSIZE; s++){
		for( int v=0; v<CARDVALUESIZE; v++){
			cout << cards[s*13+v]->toString();
		}
		cout << endl;
	}
	cout << endl;
}
void printHashValue( Card_p* cards ){
	for( int s=0; s<SUITSIZE; s++){
		for( int v=0; v<CARDVALUESIZE; v++){
			cout << cards[s*13+v]->toString() << cards[s*13+v]->getHashString() << endl;
		}
		cout << endl;
	}
	cout << endl;
}

void inputExpectedValue( Card_p* cards ){
	for( int s=0; s<SUITSIZE; s++){
		for( int v=0; v<CARDVALUESIZE; v++){
			cards[s*13+v]->setSuit(Card::Suit(s+1));
			cards[s*13+v]->setValue(Card::CardValue(v+1));
		}
	}
}
void inputUnexpectedValue( Card_p* cards ){
	for( int s=0; s<SUITSIZE; s++){
		for( int v=0; v<CARDVALUESIZE; v++){
			cards[s*13+v]->setSuit(Card::Suit(-s*2));
			cards[s*13+v]->setValue(Card::CardValue(-v*2));
		}
	}
	printCard(cards);
}

void createExpectedCard( Card_p* cards ){
	for( int s=0; s<SUITSIZE; s++){
		for( int v=0; v<CARDVALUESIZE; v++){
			cards[s*13+v]= new Card(); 
		}
	}
	inputExpectedValue( cards ); 
	printCard(cards);
}



int main(){
	Card_p cards[52];
	createExpectedCard( cards );
	printHashValue( cards );
	inputUnexpectedValue( cards );
	printHashValue( cards );
	Card::Suit(-1);
	Card::CardValue(-1);
	
	return 0; 
}

