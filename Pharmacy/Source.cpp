#include <iostream>
#include "Product.h"
#include "Warehouse.h"
#include <Windows.h>


int main()
{
	SetConsoleCP( 1251 );
	SetConsoleOutputCP( 1251 );
	Product a , b,c;
	a.setName( "sss" );
	a.setForm( "aa" );
	a.setCompany( "OAO" );
	a.setPrice( 23.6 );
	a.setAmount( 3 );
	a.printProduct();
	b = a;
	b.setAmount( 3333 );
	b.printProduct();
	c = a;
	c.setName( "DELETE" );
	Warehouse g;
	g.addNewProduct( a );
	g.addNewProduct( c );
	g.print();
	g.changeProduct( 1 );
	g.print();

	std::cout << _getch();

	return 0;
}