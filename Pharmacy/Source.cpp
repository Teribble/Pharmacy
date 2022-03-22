#include "Warehouse.h"
#include "iHelper.h"
#include <fstream>
#include "customMenu.h"
/// <summary>
/// Сделать поиск по полям, фильтрация позиций, сортировка
/// </summary>
/// <returns></returns>
/// 
int main()
{
	system( "title Аптека твоей мечты" );
	iHelper::SizeConsole( 881 , 600 );
	iHelper::ShowConsoleCursor( false );
	setlocale( 0 , "rus" );
	SetConsoleCP( 1251 );
	SetConsoleOutputCP( 1251 );
	Product a , b , c;
	a.setName( "Hello my name" );
	a.setForm( "aa" );
	a.setCompany( "OAO" );
	a.setPrice( (float)23.6 );
	a.setAmount( 3 );
	b = a;
	b.setAmount( 3333 );
	c = a;
	c.setName( "DELETE" );
	c.setForm( "Arma" );
	c.setCompany( "Talka" );
	c.setPrice( 3.34f );
	c.setAmount( 300 );
	Warehouse g;
	g.addNewProduct( a );
	for(int i = 0; i < 5; i++)
	{
		g.addNewProduct( a );
		g.addNewProduct( c );
	}
	//g.changeProduct(1);
	//g.print();
	//g.search( "d" );
	//g.print();
	g.showWarehouse();
	/*customMenu change;
	change.addButtons( "Добавить" );
	change.addButtons( "Удалить" );
	change.addButtons( "Удалить" );
	change.addButtons( "Удалить" );
	change.addButtons( "Изменить" );
	change.setDirection( 1 );
	std::cout<<change.choiceMenu(0,0);*/
	return 0;
}