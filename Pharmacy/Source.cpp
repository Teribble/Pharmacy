#include "Warehouse.h"


/// <summary>
/// Сделать поиск по полям, фильтрация позиций, сортировка
/// </summary>
/// <returns></returns>
int main()
{
	system( "title Аптека твоей мечты" );
	iHelper::deleteRR();
	iHelper::SizeConsole( 840 , 600 );
	SetConsoleCP( 1251 );
	SetConsoleOutputCP( 1251 );
	Product a , b , c;
	a.setName( "Hello my name" );
	a.setForm( "aa" );
	a.setCompany( "OAO" );
	a.setPrice( 23.6 );
	a.setAmount( 3 );
	b = a;
	b.setAmount( 3333 );
	c = a;
	c.setName( "DELETE" );
	Warehouse g;
	g.addNewProduct( a );
	g.addNewProduct( a );
	g.addNewProduct( a );
	g.addNewProduct( c );
	g.addNewProduct( c );
	g.addNewProduct( c );
	g.addNewProduct( c );
	g.changeProduct(1);
	g.print();
	g.search( "DELETE" );
	system( "PAUSE" );

	return 0;
}