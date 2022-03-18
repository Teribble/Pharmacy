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
		std::cout << "Список пуст\n";
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
