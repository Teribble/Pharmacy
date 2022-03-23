#include "customMenu.h"

#pragma warning(disable : 6385)

customMenu::customMenu()
{
	this->buttons = nullptr;
	this->choice = 0;
	this->counter = 0;
	this->maxSizeStr = 0;
	this->direction = 0;
}

customMenu::~customMenu()
{
	if(!isEmpty())
	{
		delete[] this->buttons;
	}
}

void customMenu::addButtons( std::string newButton )
{
	int newSize = counter + 1;
	std::string* buffer = new std::string[ newSize ];
	for(int i = 0; i < counter; i++)
	{
		buffer[ i ] = buttons[ i ];
	}
	buffer[ newSize - 1 ] = " " + newButton + " ";
	buttons = nullptr;
	buttons = buffer;
	if(maxSizeStr + TWO < newButton.size() + TWO)
		maxSizeStr = newButton.size() + TWO;
	counter++;
}

std::string customMenu::getNameButtons( int count ) const
{
	return this->buttons[count];
}

int customMenu::choiceMenu(int x, int y)
{
	while(true)
	{
		//system( "CLS" );
		iHelper::setCursor( x , y );
		if(this->direction == 0)
			moveVertically( x , y );
		else moveHorizontally( x , y );
		int pos;
		pos = _getch();
		switch(pos)
		{
			case VK_ARROW_LEFT://влево 
				if(direction == 1)
				{
					if(choice == 0)
						choice = counter;
					else choice--;
					break;
				}
				else break;
			case VK_ARROW_RIGHT://вправо
				if(direction == 1)
				{
					if(choice == counter)
						choice = 0;
					else choice++;
					break;
				}
				else break;
			case VK_ARROW_UP://вверх
				if(direction == 0)
				{
					if(choice == 0)
						choice = counter;
					else choice--;
					break;
				}
				else break;
			case VK_ARROW_DOWN://вниз
				if(direction == 0)
				{
					if(choice == counter)
						choice = 0;
					else choice++;
					break;
				}
				else break;
			case VK_ENTER:
				return choice;
			case VK_ESCAPE:
				return VK_ESCAPE;
		}
	}
}

void customMenu::setDirection( int num )
{
	this->direction = num;
}

void customMenu::moveVertically(int x, int y) const
{
	for(int i = 0; i < counter; i++)
	{
		if(this->choice == i)
		{
			std::cout << Terrible::bg_green << Terrible::fg_black;
			iHelper::setCursor( x , y );
			std::cout <<std::left<< std::setw(maxSizeStr) << std::left << getNameButtons(i) << std::endl;
			y++;
		}
		else
		{
			std::cout << Terrible::bg_gray << Terrible::fg_white;
			iHelper::setCursor( x , y );
			std::cout << std::left << std::setw( maxSizeStr ) << std::left << getNameButtons( i ) << std::endl;
			y++;
		}
	}
	std::cout << Terrible::bg_black << Terrible::fg_white;
}

void customMenu::moveHorizontally( int x , int y ) const
{
	for(int i = 0; i < counter; i++)
	{
		if(this->choice == i)
		{
			std::cout << Terrible::bg_green << Terrible::fg_black;
			std::cout << std::left <<std::setw( maxSizeStr ) << std::left << getNameButtons( i );
		}
		else
		{
			std::cout << Terrible::bg_gray << Terrible::fg_white;
			std::cout << std::left << std::setw( maxSizeStr ) << std::left << getNameButtons( i );
		}
	}
	std::cout << Terrible::bg_black << Terrible::fg_white;
}

void customMenu::deleteMenu(int x, int y)
{
	for(int i = 0; i < counter; i++)
	{
		iHelper::setCursor( x , y++ );
		for(int i = 0; i < maxSizeStr; i++)
		{
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

bool customMenu::isEmpty()
{
	return counter == 0;
}
