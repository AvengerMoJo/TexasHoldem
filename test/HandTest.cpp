#include <iostream>
#include "Deck.h"
#include "Hand.h"

using namespace std;

void play( Deck* myDeck )
{
	Hand myHand;
	Card* hole[2];
	Card* flop[3];
	Card* turn;
	Card* river;

 	hole[0] = myDeck->popCard();
 	hole[1] = myDeck->popCard();

	std::cout << "My first card " << hole[0]->toString() << endl;
	std::cout << "My second card " << hole[1]->toString() << endl;
	myHand.setHole( hole[0], hole[1] ); 
	std::cout << "My Hands has flush " << boolalpha << myHand.isFlush() << endl;
	std::cout << "My Hands has straight " << boolalpha << myHand.isStraight() << endl;
	std::cout << "My Hands has straight flush " << boolalpha << myHand.isStraightFlush() << endl;

	myDeck->getFlop( flop[0], flop[1], flop[2] );
	std::cout << "Flop Cards " << flop[0]->toString() << flop[1]->toString() << flop[2]->toString() << endl;
	myHand.setFlop( flop[0], flop[1], flop[2] );
	std::cout << "My Hands has flush " << boolalpha << myHand.isFlush() << endl;
	std::cout << "My Hands has straight " << boolalpha << myHand.isStraight() << endl;
	std::cout << "My Hands has full house " << boolalpha << myHand.isFullHouse() << endl;
	std::cout << "My Hands has four of a kind " << boolalpha << myHand.isFourOfAKind() << endl;
	std::cout << "My Hands has straight flush " << boolalpha << myHand.isStraightFlush() << endl;
	std::cout << "My Hands has three of a kind " << boolalpha << myHand.isThreeOfAKind() << endl;
	std::cout << "My Hands has pair " << boolalpha << myHand.isPair() << endl;

	turn = myDeck->getTurn(); 
	std::cout << "Turn card " << turn->toString() << endl;
	myHand.setTurn( turn );
	std::cout << "My Hands has flush " << boolalpha << myHand.isFlush() << endl;
	std::cout << "My Hands has straight " << boolalpha << myHand.isStraight() << endl;
	std::cout << "My Hands has full house " << boolalpha << myHand.isFullHouse() << endl;
	std::cout << "My Hands has four of a kind " << boolalpha << myHand.isFourOfAKind() << endl;
	std::cout << "My Hands has straight flush " << boolalpha << myHand.isStraightFlush() << endl;
	std::cout << "My Hands has three of a kind " << boolalpha << myHand.isThreeOfAKind() << endl;
	std::cout << "My Hands has pair " << boolalpha << myHand.isPair() << endl;

	river = myDeck->getRiver(); 
	std::cout << "River card " << river->toString() << endl;
	myHand.setRiver( river );
	std::cout << "My Hands has flush " << boolalpha << myHand.isFlush() << endl;
	std::cout << "My Hands has straight " << boolalpha << myHand.isStraight() << endl;
	std::cout << "My Hands has full house " << boolalpha << myHand.isFullHouse() << endl;
	std::cout << "My Hands has four of a kind " << boolalpha << myHand.isFourOfAKind() << endl;
	std::cout << "My Hands has straight flush " << boolalpha << myHand.isStraightFlush() << endl;
	std::cout << "My Hands has three of a kind " << boolalpha << myHand.isThreeOfAKind() << endl;
	std::cout << "My Hands has pair " << boolalpha << myHand.isPair() << endl;
}

int main(){
	Deck myDeck; 
	std::cout << "New Deck of Card" << endl;
	std::cout << myDeck.toString() << endl;

	myDeck.quickShuffle();
	std::cout << "Quick Shuffle" << endl;
	std::cout << myDeck.toString() << endl;

	myDeck.riffleShuffle(); 
	std::cout << "Riffle Shuffle" << endl;
	std::cout << myDeck.toString() << endl;
	
	//for( int i=0; i< 100000; i++ ){
	for( int i=0; i< 8; i++ ){
		Deck myDeck2; 
		myDeck2.quickShuffle();
		myDeck2.riffleShuffle(); 
		std::cout << myDeck2.toString() << endl;
		play( &myDeck2 ); 
	}
	
	return 0; 
}

