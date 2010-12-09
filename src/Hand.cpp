#include "Hand.h"

const int Hand::SuitShift[SUITSIZE] = { 0, 3, 6, 9 };

Hand::Hand()
{
	init();
}

inline void Hand::init()
{
	stage = Start;
	flush = 0;
	straightflush = false;
	fourofakind   = false;
	fullhouse     = false;
	threeofakind  = false;
	straight[0]=0;
	straight[1]=0;
	straight[2]=0;
	straight[3]=0;
	handvalue = 0;
	hole[0]=NULL;
	hole[1]=NULL;
	flop[0]=NULL;
	flop[1]=NULL;
	flop[2]=NULL;
	turn=NULL;
	river=NULL;
}

void Hand::setHole( Card* c1, Card* c2 )
{
	flush += 1 << SuitShift[c1->getSuit()];
	flush += 1 << SuitShift[c2->getSuit()];
	straight[c1->getSuit()] |= 1 << ( c1->getValue() + 1 ); 
	straight[c2->getSuit()] |= 1 << ( c2->getValue() + 1 );
	hole[0]=c1;
	hole[1]=c2;
	handvalue |= (1 << ( c1->getValue() + 1) );
	handvalue |= (1 << ( c2->getValue() + 1) );
	stage = Hole;
}

void Hand::setFlop( Card* c1, Card* c2, Card* c3 )
{
	flush += 1 << SuitShift[c1->getSuit()];
	flush += 1 << SuitShift[c2->getSuit()];
	flush += 1 << SuitShift[c3->getSuit()];
	straight[c1->getSuit()] |= 1 << ( c1->getValue() + 1 ); 
	straight[c2->getSuit()] |= 1 << ( c2->getValue() + 1 );
	straight[c3->getSuit()] |= 1 << ( c3->getValue() + 1 );
	flop[0]=c1;
	flop[1]=c2;
	flop[2]=c3;
	handvalue |= (1 << ( c1->getValue() + 1) );
	handvalue |= (1 << ( c2->getValue() + 1) );
	handvalue |= (1 << ( c3->getValue() + 1) );
	stage = Flop;
}

void Hand::setTurn( Card* c1 )
{
	flush += 1 << SuitShift[c1->getSuit()];
	straight[c1->getSuit()] |= 1 << ( c1->getValue() + 1 ); 
	turn=c1;
	handvalue |= (1 << ( c1->getValue() + 1) );
	stage = Turn;
}

void Hand::setRiver( Card* c1 )
{
	flush += 1 << SuitShift[c1->getSuit()];
	straight[c1->getSuit()] |= 1 << ( c1->getValue() + 1 ); 
	river=c1;
	handvalue |= (1 << ( c1->getValue() + 1) );
	stage = River;
}

bool Hand::isStraightFlush()
{
	uint64_t allvalue = straight[0] | straight[1] << 16 | (int64_t)straight[2] << 32 | (int64_t)straight[3] << 48;
	allvalue |= (straight[0] >> 13) | (straight[1] >> 13) << 16  | (int64_t)(straight[2] >> 13) << 32  | (int64_t)(straight[3] >> 13) << 48;
	straightflush = allvalue & (allvalue << 1) & (allvalue << 2) & (allvalue << 3) & (allvalue << 4);
	return straightflush;
}

bool Hand::isFourOfAKind()
{
	fourofakind = straight[0] & straight[1] & straight[2] & straight[3] ;
	if( fourofakind ){
		highcard = lowBit( fourofakind ); 
	}
	return fourofakind;
}

bool Hand::isFullHouse()
{
	int lowthree=0,highthree=0,tmp=0;
	unsigned int a = straight[0] & straight[1] & straight[2];
	unsigned int b = straight[0] & straight[1] & straight[3];
	unsigned int c = straight[0] & straight[2] & straight[3];
	unsigned int d = straight[1] & straight[2] & straight[3];
	if( (tmp = a | b | c | d ) == 0 ){ 
		return false;
	} else {
		threeofakind = true;
		lowthree = 1+lowBit( tmp ); 
		highthree = lowBit( tmp >> lowthree ); 
		if( highthree >= 0 )
			highcard = highthree + lowthree - 1;
		else
			highcard = highthree = lowthree - 1;
		if( highthree != lowthree ) {
			fullhouse = true;
			return true;
		} else {
			if( ~tmp & (straight[0] & straight[1]) | ~tmp & (straight[0] & straight[2]) |
			    ~tmp & (straight[0] & straight[3]) | ~tmp & (straight[1] & straight[2]) |
			    ~tmp & (straight[1] & straight[3]) | ~tmp & (straight[2] & straight[3]) ) {
				fullhouse = true; 
			}
			return fullhouse; 
		}
	}
}

bool Hand::isFlush()
{
	if( straightflush ) return true;
	if( fourofakind ) return false;
	int tem = 0;
	switch(stage){
		case Flop:
			tem = flush & 2340; 
			return (flush & (tem >> 2));
		case Turn:
		case River:
			tem = flush & 2340; 
			return (flush & (tem >> 1)) | (flush & tem>>2); 
		case Hole:	// unknown
		default:
			return false;
	}
}

bool Hand::isStraight()
{
	if( straightflush ) return true;
	if( fourofakind ) return false;
	int allvalue = straight[0] | straight[1] | straight[2] | straight[3];
	allvalue |= straight[0] >> 13 | straight[1] >> 13 | straight[2] >> 13 | straight[3] >> 13;
	return allvalue & (allvalue << 1) & (allvalue << 2) & (allvalue << 3) & (allvalue << 4);
}

inline int Hand::lowBit( unsigned int v )
{
        float f = (float)(v & -v); // cast the least significant bit in v to a float
        return  (*(uint32_t *)&f >> 23) - 0x7f;
}

