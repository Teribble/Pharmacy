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
		std::cout << "������ ����\n";
	}
	else
	{
		std::cout << "������������ ����\n";
	}
}

void Warehouse::changeProduct( const int position )
{
	system( "cls" );
	std::cout <<
		"1: �������� ���\n" <<
		"2: �������� ����� �������\n" <<
		"3: �������� ��������\n" <<
		"4: �������� ����\n" <<
		"5: �������� ���-�� ������ �� ������\n" << std::endl;
	std::string buffer;
	float price;
	int amount;
	int choice;
	choice = _getch( );
	switch(choice)
	{
		case one:
			std::cout << "������� ���: ";
			std::cin >> buffer;
			this->list[ position ].setName( buffer );
			break;
		case two:
			std::cout << "������� ����� �������: ";
			std::cin >> buffer;
			this->list[ position ].setForm( buffer );
			break;
		case three:
			std::cout << "������� �������� ��������: ";
			std::cin >> buffer;
			this->list[ position ].setCompany( buffer );
			break;
		case fore:
			std::cout << "������� ����: ";
			std::cin >> price;
			this->list[ position ].setPrice( price );
			break;
		case five:
			std::cout << "������� ���-�� ������ �� ������: ";
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
		for(int i = 0; i < this->counter; i++)
		{
			std::cout << i << " " << this->list[ i ].getName() << "\n";
		}
	}
	else
	{
		std::cout << "������ ����\n";
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
