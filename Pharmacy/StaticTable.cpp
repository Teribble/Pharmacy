#include "StaticTable.h"
#define TWO 2

#define TOP_LEFT_CORNER 201
#define TOP_MIDDLE_LINE 205
#define TOP_RIGHT_CORNER 187

#define LEFT_LINE 199
#define RIGHT_LINE 182

#define BOTTOM_LEFT_CORNER 200
#define BOTTOM_MIDDLE_LINE 205
#define BOTTOM_RIGHT_CORNER 188

void StaticTable::topPart( const int width )
{
	std::cout << ( char )TOP_LEFT_CORNER;
	for(int i = 0; i < width + TWO; i++)
	{
		std::cout << ( char )TOP_MIDDLE_LINE;
	}
	std::cout << ( char )TOP_RIGHT_CORNER << std::endl;
}

void StaticTable::middlePart( const std::string str, const int numberOfLetters )
{
	std::cout << ( char )LEFT_LINE;
	std::cout << std::setw( numberOfLetters) << std::left <<" " + str + " ";
	std::cout << ( char )RIGHT_LINE << std::endl;
}

void StaticTable::bottomPart( const int width )
{
	std::cout << ( char )BOTTOM_LEFT_CORNER;
	for(int i = 0; i < width + TWO; i++)
	{
		std::cout << ( char )BOTTOM_MIDDLE_LINE;
	}
	std::cout << ( char )BOTTOM_RIGHT_CORNER << std::endl;
}
