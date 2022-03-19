#include "Warehouse.h"

int main()
{
	system( "title Аптека твоей мечты" );
	iHelper::deleteRR();
	iHelper::SizeConsole( 840 , 600 );
	SetConsoleCP( 1251 );
	SetConsoleOutputCP( 1251 );
	Product a , b , c;
	a.setName( "sss" );
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
	g.print();
	system( "PAUSE" );

	return 0;
}