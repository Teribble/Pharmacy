#pragma once
#include "Console.h"
#include "iHelper.h"

class StaticTable
{
public:
	static void topPart(const int width);
	static void middlePart( const std::string str , const int numberOfLetters );
	static void bottomPart( const int width );
};

