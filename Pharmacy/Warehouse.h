#pragma once
#include "Product.h"

#define TEN 10
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

