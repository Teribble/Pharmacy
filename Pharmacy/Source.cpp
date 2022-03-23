#include "Warehouse.h"
#include "iHelper.h"
#include "customMenu.h"
#include <cstdlib>

int main()
{
	system( "title Аптека твоей мечты" );
	iHelper::SizeConsole( 1081 , 500 );
	iHelper::ShowConsoleCursor( false );
	setlocale( 0 , "rus" );
	SetConsoleCP( 1251 );
	SetConsoleOutputCP( 1251 );
	srand( time( NULL ) );

	std::string names[ 10 ]{
		"Омепразол","Тантумверде","Мебеверин","Бисакодил","Лоперамид",
		"Панкреатин","Нафтизин","Инсулин","Морфий","Марихуанна" };
	std::string forms[ 10 ]{
		"капли","настойка","сироп","суспензия","драже",
		"мазь","капсула","таблетка","порошки","карамель" };
	std::string companys[ 10 ]{
		"Р-Фарм","Биокад","Генериум","Валента-Фарм","Фармасинтез",
		"Канонфарма-Продакшн","Фармстандарт-Уфавита","Вертекс","Синтез","Эс-Джи-Биотех" };
	Warehouse warehouse;

	for(int i = 0; i < 11; i++)
	{
		Product buffer;
		buffer.setName( names[ iHelper::randomInt( 0 , 9 ) ] );
		buffer.setForm( forms[ iHelper::randomInt( 0 , 9 ) ] );
		buffer.setCompany( companys[ iHelper::randomInt( 0 , 9 ) ] );
		buffer.setPrice( iHelper::randomFloat( 12 , 300 ));
		buffer.setAmount( iHelper::randomInt( 120 , 1600 ) );
		warehouse.addNewProduct( buffer );
	}
	warehouse.showWarehouse();
	//g.read(PATH);
	return 0;
}