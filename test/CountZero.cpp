#include <iostream>
#include <inttypes.h>
#include <stdlib.h>     // for random number


using namespace std;

static const int Mod37BitPosition[] = // map a bit value mod 37 to its position
{
  32, 0, 1, 26, 2, 23, 27, 0, 3, 16, 24, 30, 28, 11, 0, 13, 4,
  7, 17, 0, 25, 22, 31, 15, 29, 10, 12, 6, 0, 21, 14, 9, 5,
  20, 8, 19, 18
};

int countzero( unsigned int v )
{
	float f = (float)(v & -v); // cast the least significant bit in v to a float
	return  (*(uint32_t *)&f >> 23) - 0x7f;
}

int countzero2( unsigned int v )
{
	return Mod37BitPosition[(-v & v) % 37];
}


int main()
{
	//for( int i=0; i< 5000000; i++) {
	//	int temp = rand();
		//int out = countzero(temp);
	//	int out2 = countzero2(temp);
		//cout << temp << " - Result one "<< out<< " Result two "<< out2 << endl;
		//if( out != out2 )
			//cout << temp << " - Result one "<< out<< " Result two "<< out2 << endl;
			//cout << " shit"<<endl;
		//cout << temp << " how many zero "<< countzero( temp ) << endl;
		//cout << temp << " how many zero "<< countzero2( temp ) << endl;
	//}
	cout << "0 - Result one "<< countzero2(0) << " Result two "<< countzero(0) << endl;
	return 0;
}
