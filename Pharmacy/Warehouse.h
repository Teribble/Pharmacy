#pragma once
#include "Product.h"
#include <conio.h>
#include <iomanip>
#include "iHelper.h"

#pragma region define
#define one 49
#define two 50
#define three 51
#define fore 52
#define five 53
#define TEN 10
#pragma endregion define

class Warehouse
{
public:

	// Конструктор
	Warehouse();

	// Деструктор(деконструктор)
	virtual ~Warehouse();

	// Добавить новую позицию на склад
	void addNewProduct(Product newProduct);

	// Удалить выбранную позицию из списка
	void deleteProduct( const int position );

	// Изменить выбранную позицию
	void changeProduct( const int position );

	// Вернет кол-во позиций на складе
	int getCounter() const;

	// Вывести список позиций на складе
	void print();

	// Функция упращает поиск по имени препарата, выводя на экране все совпадения по вводимой позиции
	void search(std::string name);

	void menu();

private:
	
	// Пустой склад?
	bool isEmpty();

	// Полный склад?
	bool isFull();

	// Список товаров на складе
	Product *list;

	// Количество позиций на складе
	int counter;

	// "максимальный" размер склада, который сам расширяется при переполнении
	int capasity;

};

