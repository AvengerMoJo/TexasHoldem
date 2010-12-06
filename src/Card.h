#include <string>

#define SUITSIZE 4 
#define CARDVALUESIZE 13

enum Suit { Diamonds, Hearts, Clubs, Spades };
String[] SuitString = { "Diamonds", "Hearts", "Clubs", "Spades" };
enum CardValue { Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,Ace };
String[] ValueString = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };

class Card { 

public:
	Card( CardValue new_value, Suit new_suit ){ setValue( new_value); setSuit( new_suit ); };
	CardValue getValue(){ return value; };
	void setValue(CardValue new_value):value(new_value){};

	Suit getSuit(){ return suit; };
	void setSuit(Suit new_suit):suit(new_suit){};

	String toString(){ return ValueString[value] + SuitString[suit]; }; 

private:
	Suit suit; 
	CardValue value;
}
