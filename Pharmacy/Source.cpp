#include "Warehouse.h"
#include "iHelper.h"
#include <fstream>
#include "customMenu.h"

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
	c.setForm( "brma" );
	c.setCompany( "Talka" );
	c.setPrice( 3.34f );
	c.setAmount( 300 );
	b.setForm( "I" );
	Warehouse g;
	g.addNewProduct( a );
	for(int i = 0; i < 20; i++)
	{
		g.addNewProduct( a );
		g.addNewProduct( c );
		g.addNewProduct( b );
	}
	//g.showWarehouse();

	return 0;
}