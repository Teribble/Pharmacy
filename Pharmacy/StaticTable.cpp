#include "StaticTable.h"
#define TWO 2

void StaticTable::topPart( const int width )
{
	std::cout << ( char )201;
	for(int i = 0; i < width + TWO; i++)
	{
		std::cout << ( char )205;
	}
	std::cout << ( char )187 << std::endl;
}

void StaticTable::middlePart( const std::string str, const int numberOfLetters )
{
	std::cout << ( char )199;
	std::cout << std::setw( numberOfLetters  + TWO) << std::left <<str;
	std::cout << ( char )182 << std::endl;
}

void StaticTable::bottomPart( const int width )
{
	std::cout << ( char )200;
	for(int i = 0; i < width + TWO; i++)
	{
		std::cout << ( char )205;
	}
	std::cout << ( char )188 << std::endl;
}
