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

void Deck::quickShuffle()
{
	srand ( getRandomSeed() );
	int cur=0;
	for( int i=0; i < DECKSIZE-1; i++ ){
		int rand_card = i + ( rand() % (DECKSIZE-i) );
		swapCards( i, rand_card );
	}
}

void Deck::riffleShuffle()
{
	srand ( getRandomSeed() );
	int mid =( rand() % DECKSIZE + rand() % DECKSIZE ) / 2 ;
	Card* newcards[DECKSIZE];
	int a = 0; 
	int b = mid; 
	for( int i=0; i < DECKSIZE; i++ ){
		if( rand() % 2 ) {
			if( a >= mid ) { 
				newcards[i] = cards[b++]; 
			} else {
				newcards[i] = cards[a++]; 
			}
		} else { 
			if( b >= DECKSIZE ) { 
				newcards[i] = cards[a++]; 
			} else {
				newcards[i] = cards[b++]; 
			}
		}
	}
	for( int i=0; i < DECKSIZE; i++ ){
		cards[i] = newcards[i]; 
	}
}

unsigned int Deck::getRandomSeed()
{
	char buf[sizeof(int)];
	int fd;
	if( fd = open("/dev/urandom", O_RDONLY | O_NONBLOCK ) == -1 ) {
		if( fd = open("/dev/random", O_RDONLY ) == -1 ){
			return time(NULL)+getpid();
		}
	}
	fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK );
	read(fd, &buf, sizeof(int));
	close(fd);
	return buf[0] | buf[1]<<8 | buf[2] <<16 | buf[3] <<24;
}

inline void Deck::swapCards(int carda, int cardb )
{
	Card* cp = cards[carda]; 
	cards[carda] = cards[cardb]; 
	cards[cardb] = cp; 
}

string Deck::toString()
{
	string buffer;
	string br = ",";
	for( int i=0; i< DECKSIZE; i++ ){
		if( i == DECKSIZE-1) br = "\n";	
		buffer = buffer + cards[i]->toString() + br;
	}
	return buffer;
}
