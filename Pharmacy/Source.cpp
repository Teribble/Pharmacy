#include <iostream>
#include "Product.h"
#include "Warehouse.h"
int main()
{
	setlocale( 0 , "rus" );
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
	g.deleteProduct( 2 );
	g.print();
	g.deleteProduct( 1 );
	g.print();

	return 0;
}