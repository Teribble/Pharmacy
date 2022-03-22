#pragma once
#include "Product.h"
#include <conio.h>
#include <iomanip>
#include "iHelper.h"
#include "Navigation.h"

#pragma region define
#define one 49
#define two 50
#define three 51
#define fore 52
#define five 53
#define TEN 10

#define coordMainTable 0, 10
#define coordMenu1 0, 0
#define coordChangeMenu 1, 1
#define coordChangeTwoMenu 14, 1
#define coordChangeThreeMenu 27, 1
#define coordEntered 1, 9
#define coordThree 2, 4
#define coordError 60, 9
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

	// Фильтр имени
	void filterName(std::string name);

	// Фильтр форм
	void filterForm(std::string form);

	// Фильтр компаний
	void filterCompany(std::string company);

	// Фильтр цены
	void filterPrice(float price);

	// Фильтр количества
	void filterAmount(int amount);

	// Показать склад
	void showWarehouse();

	// Соритровка по имени
	void sortName() const;

	// Сортировка по форме выпуска
	void sortForm() const;

	// Соритровка по компании
	void sortCompany() const;

	void sortPrice() const;

	void sortAmount() const;

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

