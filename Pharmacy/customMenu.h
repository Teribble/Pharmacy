#pragma once
#include <string>
#include "StaticTable.h"
#include <conio.h>
class customMenu
{
public:
	customMenu();

	virtual ~customMenu();

	void addButtons(std::string newButton);

	std::string getNameButtons(int count) const;

	int choiceMenu( int x , int y );

	void setDirection( int num );
	void deleteMenu( int x , int y );
private:

	void moveVertically( int x , int y ) const;

	void moveHorizontally( int x , int y ) const;

	
	bool isEmpty();

	std::string* buttons;

	int choice;
	int counter;

	int maxSizeStr;

	int direction;
};

