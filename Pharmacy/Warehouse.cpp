#include "Warehouse.h"
#include "customMenu.h"

#pragma warning(disable : 6385)

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
	if(!isEmpty() && position >= 0 && position < this->counter )
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
		iHelper::errorMessage( "Список пуст!" , coordError);
	}
	else
	{
		iHelper::errorMessage( "Неккоректный ввод", coordError );
		deleteProduct( iHelper::getIntDisappearingInscription( "Введите позицию продукта: " , coordEnter ) );
	}
}

void Warehouse::changeProduct( const int position )
{
	if(position >= counter || position < 0)
	{
		iHelper::errorMessage( "Нет такой позиции" , coordError );
		changeProduct( iHelper::getIntDisappearingInscription( "Введите номер позиции: " , coordEnter ) );
	}
	else
	{
		customMenu h1;
		h1.addButtons( "Изменить имя" );
		h1.addButtons( "Изменить форму выпуска" );
		h1.addButtons( "Изменить компанию" );
		h1.addButtons( "Изменить цену" );
		h1.addButtons( "Изменить кол-во товара на складе" );
		int choice = h1.choiceMenu( coordThree );
		switch(choice)
		{
			case NULL:
				this->list[ position ].setName( iHelper::getStrDisappearingInscription( "Введите имя: " , coordEnter ) );
				break;
			case ONE:
				this->list[ position ].setForm( iHelper::getStrDisappearingInscription( "Введите форму выпуска: " , coordEnter ) );
				break;
			case TWO:
				this->list[ position ].setCompany( iHelper::getStrDisappearingInscription( "Введите название комании: " , coordEnter ) );
				break;
			case THREE:
				this->list[ position ].setPrice( iHelper::getFloatDisappearingInscription( "Введите цену за 1 штуку: " , coordEnter ) );
				break;
			case FORE:
				this->list[ position ].setAmount( iHelper::getIntDisappearingInscription( "Введите кол-во поступления позиций: " , coordEnter ) );
				break;
		}
		h1.deleteMenu( coordThree );
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
		std::cout << Terrible::bg_gray << Terrible::fg_black;
		std::cout << "|--------------------------------------------------------------------------------------------------------|" << std::endl;
		std::cout <<"|"<<
			std::left << std::setw( 30 ) << Terrible::fg_yellow << "Наименование:" <<Terrible::fg_black<< "|" <<
			std::left << std::setw( 25 ) << Terrible::fg_yellow << "Форма выпуска:" << Terrible::fg_black << "|" <<
			std::left << std::setw( 15 ) << Terrible::fg_yellow << "Компания:" << Terrible::fg_black << "|" <<
			std::left << std::setw( 15 ) << Terrible::fg_yellow << "Цена(шт):" << Terrible::fg_black << "|" <<
			std::left << std::setw( 15 ) << Terrible::fg_yellow << "Кол-во:" << Terrible::fg_black << "|" << std::endl;
		std::cout << "|--------------------------------------------------------------------------------------------------------|" << std::endl;
		for(int i = 0; i < this->counter; i++)
		{
			std::cout <<"|" <<std::setw(3) << i << "> " <<
				std::left << std::setw(25) <<this->list[i].getName() << "|" <<
				std::left << std::setw( 25 ) << this->list[ i ].getForm() << "|" <<
				std::left << std::setw( 15 ) << this->list[ i ].getCompany() << "|" <<
				std::left << std::setw( 15 ) << this->list[ i ].getPrice() << "|" <<
				std::left << std::setw( 15 ) << this->list[ i ].getAmount() <<"|" << std::endl;
		}
		std::cout << "|--------------------------------------------------------------------------------------------------------|" << std::endl;
		std::cout << RESET;
		for(int i = 0; i < TEN * TEN + TEN; i++)
		{
			std::cout << " ";
		}
	}
	else
	{
		iHelper::setCursor( coordMainTable );
		std::cout << Terrible::bg_gray << Terrible::fg_black;
		std::cout << "|--------------------------------------------------------------------------------------------------------|" << std::endl;
		std::cout << "|" <<
			std::left << std::setw( 28 ) << Terrible::fg_yellow << "Наименование:" << Terrible::fg_black << "|" <<
			std::left << std::setw( 25 ) << Terrible::fg_yellow << "Форма выпуска:" << Terrible::fg_black << "|" <<
			std::left << std::setw( 15 ) << Terrible::fg_yellow << "Компания:" << Terrible::fg_black << "|" <<
			std::left << std::setw( 15 ) << Terrible::fg_yellow << "Цена(шт):" << Terrible::fg_black << "|" <<
			std::left << std::setw( 15 ) << Terrible::fg_yellow << "Кол-во:" << Terrible::fg_black << "|" << std::endl;
		std::cout << "|--------------------------------------------------------------------------------------------------------|" << std::endl;
		std::cout << "|" << std::setw( 3 ) << "> " <<
				std::left << std::setw( 25 ) << "Список пуст" << "|" <<
				std::left << std::setw( 25 ) << " " << "|" <<
				std::left << std::setw( 15 ) << " " << "|" <<
				std::left << std::setw( 15 ) <<" " << "|" <<
				std::left << std::setw( 15 ) << " " << "|" << std::endl;
		std::cout << "|------------------------------------------------------------------------------------------------------|" << std::endl;
		std::cout << RESET;
	}

}

void Warehouse::search( std::string name )
{
	Warehouse buffer;
	int sizename = (int)name.size();
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
		iHelper::setCursor( coordMainTable );
		print();
		customMenu h1;
		h1.addButtons( "Изменить" );
		h1.addButtons( "Фильтровать" );
		h1.addButtons( "Упорядочить" );
		h1.setDirection( 1 );
		int hChoice = h1.choiceMenu( coordMenu1 );
		int cChoice = 0;
		int pos = 0;
		Product p1;

		customMenu c1;
		c1.addButtons( "Добавить новый продукт" );
		c1.addButtons( "Удалить продукт" );
		c1.addButtons( "Изменить продукт" );
		switch(hChoice)
		{
			case 0:
				cChoice = c1.choiceMenu( coordChangeMenu );
				switch(cChoice)
				{
					case NULL:
						addNewProduct( p1.manualInput() );
						c1.deleteMenu( coordChangeMenu );
						break;
					case ONE:
						deleteProduct( iHelper::getIntDisappearingInscription( "Введите позицию продукта: " , coordEnter ));
						c1.deleteMenu( coordChangeMenu );
						break;
					case TWO:
						changeProduct( iHelper::getIntDisappearingInscription( "Введите позицию продукта: ", coordEnter ) );
						c1.deleteMenu( coordChangeMenu );
						break;
					case VK_ESCAPE:
						c1.deleteMenu( coordChangeMenu );
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
