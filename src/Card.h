#ifndef __CARD__
#define __CARD__

#include <string>

using namespace std;

#define SUITSIZE 4 
#define CARDVALUESIZE 13

class Card { 

public:
	static string const SuitString[SUITSIZE];
	static string const ValueString[CARDVALUESIZE];

	enum Suit { Diamonds, Hearts, Clubs, Spades };
	enum CardValue { Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,Ace };

	Card( Suit new_suit, CardValue new_value ){ 

		setSuit( new_suit ); setValue( new_value); 
	}; 

	Suit getSuit(){ return suit; };
	void setSuit(Suit new_suit){ suit = new_suit; };

	CardValue getValue(){ return value; };
	void setValue(CardValue new_value){ value = new_value; };

	string toString(){ return ValueString[value] + SuitString[suit]; }; 

private:
	Suit suit; 
	CardValue value;
};

#endif
