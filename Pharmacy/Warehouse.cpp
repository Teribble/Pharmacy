#include "Warehouse.h"

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
		std::cout << "Список пуст\n";
	}
	else
	{
		std::cout << "Некорректный ввод\n";
	}
}

void Warehouse::changeProduct( const int position )
{
	//system( "cls" );
	std::cout <<
		"1: Изменить имя\n" <<
		"2: Изменить форму выпуска\n" <<
		"3: Изменить компанию\n" <<
		"4: Изменить цену\n" <<
		"5: Изменить кол-во товара на складе\n" << std::endl;
	std::string buffer;
	float price;
	int amount;
	int choice;
	choice = _getch( );
	switch(choice)
	{
		case one:
			std::cout << "Введите имя: ";
			std::cin >> buffer;
			this->list[ position ].setName( buffer );
			break;
		case two:
			std::cout << "Введите форму выпуска: ";
			std::cin >> buffer;
			this->list[ position ].setForm( buffer );
			break;
		case three:
			std::cout << "Введите название компании: ";
			std::cin >> buffer;
			this->list[ position ].setCompany( buffer );
			break;
		case fore:
			std::cout << "Введите цену: ";
			std::cin >> price;
			this->list[ position ].setPrice( price );
			break;
		case five:
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
		std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout <<
			std::left << std::setw( 27 ) << "Наименование:" << "|" <<
			std::left << std::setw( 25 ) << "Форма выпуска:" << "|" <<
			std::left << std::setw( 15 ) << "Компания:" << "|" <<
			std::left << std::setw( 15 ) << "Цена(шт):" << "|" <<
			std::left << std::setw( 15 ) << "Кол-во:" << "|" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
		for(int i = 0; i < this->counter; i++)
		{
			std::cout <<i<<" "<<
				std::left << std::setw(25) <<this->list[i].getName() << "|" <<
				std::left << std::setw( 25 ) << this->list[ i ].getForm() << "|" <<
				std::left << std::setw( 15 ) << this->list[ i ].getCompany() << "|" <<
				std::left << std::setw( 15 ) << this->list[ i ].getPrice() << "|" <<
				std::left << std::setw( 15 ) << this->list[ i ].getAmount() <<"|" << std::endl;
		}
		std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
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
		system( "cls" );
		Product buffer;
		int pos = 0;
		std::string bufferstr = "";
		std::cout
			<< "1: Добавить новый продукт\n"
			<< "2: Удалить продукт\n"
			<< "3: Изменить продукт\n"
			<< "4: Поиск продукта по имени\n"
			<< "ESC: Выход из программы\n";
		this->print();
		pos = _getch();
		//std::cout << pos;
		switch(pos)
		{
			case VK_ONE:
				this->addNewProduct(buffer.manualInput());
				break;
			case VK_THREE:
				std::cout << "Введите позицию для изменения: ";
				std::cin >> pos;
				this->changeProduct( pos );
				break;
			case VK_TWO:
				std::cout << "Введите позицию для удаления: ";
				std::cin >> pos;
				this->deleteProduct( pos );
				break;
			case VK_FORE:
				std::cout << "Введите имя: ";
				std::cin >> bufferstr;
				this->search( bufferstr );
				break;
			case VK_ESCAPE:
				exit(1);
				break;
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
