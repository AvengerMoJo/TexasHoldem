#include <iostream>
#include "Deck.h"

using namespace std;

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
	myDeck.getRandomSeed(); 
	return 0;
}
