#include "Warehouse.h"
#include "customMenu.h"


Warehouse::Warehouse()
{
	this->capasity = 10;
	this->counter = 0;
	list = new Product[ capasity ];
}

Warehouse::~Warehouse()
{
	if(!isEmpty())
	{
		delete[] this->list;
	}
}

void Warehouse::addNewProduct( Product newProduct )
{
	if(!isFull())
	{
		this->list[ counter++ ] = newProduct;
	}
	else
	{
		int newCapacity = this->capasity + TEN;
		Product* buffer = new Product[ newCapacity ];
		for(int i = 0; i < this->capasity; i++)
		{
			buffer[ i ] = this->list[ i ];
		}
		delete[] this->list;
		this->list = buffer;
		this->capasity = newCapacity;
		addNewProduct( newProduct );
	}
}

void Warehouse::deleteProduct( const int position )
{
	if(!isEmpty() && position >= 0 && position <= this->counter )
	{

		int newCapasity = this->capasity - 1;
		int bufferCounter = 0;
		Product* buffer = new Product[ newCapasity ];
		for(int i = 0; i < this->capasity; i++)
		{
			if(i == position)
			{
				continue;
			}
			else
			{
				buffer[ bufferCounter++ ] = this->list[ i ];
			}
		}
		delete[] this->list;
		this->list = buffer;
		this->capasity = newCapasity;
		--this->counter;
	}
	else if(this->counter == 0)
	{
		iHelper::setCursor( 60 , 0 );
		std::cout << "Список пуст\n";
	}
	else
	{
		iHelper::setCursor( 60 , 0 );
		std::cout << "Некорректный ввод\n";
	}
}

void Warehouse::changeProduct( const int position )
{
	int x = 60 , y = 0;
	//system( "cls" );
	customMenu h1;
	h1.addButtons( "Изменить имя" );
	h1.addButtons( "Изменить форму выпуска" );
	h1.addButtons( "Изменить компанию" );
	h1.addButtons( "Изменить цену" );
	h1.addButtons( "Изменить кол-во товара на складе" );
	std::string buffer;
	std::string name;
	float price;
	int amount;
	int choice = h1.choiceMenu( x , y );
	switch(choice)
	{
		case NULL:
			iHelper::setCursor( 0 , SIX );
			std::cout << "Введите имя: ";
			getline( std::cin , buffer );
			this->list[ position ].setName( buffer );
			break;
		case ONE:
			iHelper::setCursor( 0 , SIX );
			std::cout << "Введите форму выпуска: ";
			getline( std::cin , buffer );
			this->list[ position ].setForm( buffer );
			break;
		case TWO:
			iHelper::setCursor( 0 , SIX );
			std::cout << "Введите название компании: ";
			getline( std::cin , buffer );
			this->list[ position ].setCompany( buffer );
			break;
		case THREE:
			iHelper::setCursor( 0 , SIX );
			std::cout << "Введите цену: ";
			std::cin >> price;
			this->list[ position ].setPrice( price );
			break;
		case FORE:
			iHelper::setCursor( 0 , SIX );
			std::cout << "Введите кол-во товара на складе: ";
			std::cin >> amount;
			this->list[ position ].setAmount( amount );
			break;
	}
}

int Warehouse::getCounter() const
{
	return this->counter;
}

void Warehouse::print()
{
	if(!isEmpty())
	{
		//system( "cls" );
		std::cout << Terrible::bg_cyan << Terrible::fg_black;
		std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout <<"|"<<
			std::left << std::setw( 28 ) << "Наименование:" << "|" <<
			std::left << std::setw( 25 ) << "Форма выпуска:" << "|" <<
			std::left << std::setw( 15 ) << "Компания:" << "|" <<
			std::left << std::setw( 15 ) << "Цена(шт):" << "|" <<
			std::left << std::setw( 15 ) << "Кол-во:" << "|" << std::endl;
		std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
		for(int i = 0; i < this->counter; i++)
		{
			std::cout <<"|" << i << "> " <<
				std::left << std::setw(25) <<this->list[i].getName() << "|" <<
				std::left << std::setw( 25 ) << this->list[ i ].getForm() << "|" <<
				std::left << std::setw( 15 ) << this->list[ i ].getCompany() << "|" <<
				std::left << std::setw( 15 ) << this->list[ i ].getPrice() << "|" <<
				std::left << std::setw( 15 ) << this->list[ i ].getAmount() <<"|" << std::endl;
		}
		std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << RESET;
	}
	else
	{
		std::cout << "Список пуст\n";
	}

}

void Warehouse::search( std::string name )
{
	Warehouse buffer;
	int sizename = name.size();
	bool flag = false;
	for(int i = 0; i < this->counter; i++)
	{
		if(this->list[ i ].getName().size() == name.size())
		{
			flag = false;
			for(int j = 0; j < sizename; j++)
			{
				if(this->list[ i ].getName()[ j ] == name[ j ]) flag = true;
				else
				{
					flag = false;
					break;
				}
			}
			if(true == flag)
			{
				buffer.addNewProduct( this->list[ i ] );
			}
		}
		else
		{
			continue;
		}
	}
	buffer.print();
	system( "PAUSE" );
}

void Warehouse::menu()
{
	

	while(!_kbhit())
	{
		iHelper::setCursor( 0 , 7 );
		print();
		customMenu h1;
		h1.addButtons( "Изменить" );
		h1.addButtons( "Фильтровать" );
		h1.addButtons( "Упорядочить" );
		h1.setDirection( 1 );
		int hChoice = h1.choiceMenu(0,0);
		int cChoice = 0;
		int pos = 0;
		Product p1;

		customMenu c1;
		c1.addButtons( "Добавить новый продукт" );
		c1.addButtons( "Удалить продукт" );
		c1.addButtons( "Изменить продукт" );
		c1.addButtons( "Шаг назад" );
		switch(hChoice)
		{
			case 0:
				cChoice = c1.choiceMenu(1,1);
				switch(cChoice)
				{
					case 0:
						addNewProduct( p1.manualInput() );
						system( "cls" );
						break;
					case 1:
						std::cout << "Введите позицию продукта: ";
						std::cin >> pos;
						deleteProduct( pos );
						system( "cls" );
						break;
					case 2:
						std::cout << "Введите позицию продукта: ";
						std::cin >> pos;
						changeProduct( pos );
						system( "cls" );
						break;
					case 3:
						system( "cls" );
						break;

				}
		}
	}
}

bool Warehouse::isEmpty()
{
	return 0 == this->counter;
}

bool Warehouse::isFull()
{
	return this->counter == this->capasity;
}
