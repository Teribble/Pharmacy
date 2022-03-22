#pragma once
#include <iostream>
#include "iHelper.h"
#include <string>

#define coordEnter 1, 9

// Товар
class Product
{
public:

	// Конструктор
	Product();

	// Ручной ввод
	Product manualInput();

#pragma region setters

	// Задать наименование товара
	void setName(const std::string name);

	// Задать форму выпуска
	void setForm( const std::string form);

	// Задать наименование компании
	void setCompany( const std::string company);

	// Задать цену товара(за шт)
	void setPrice( const float price);

	// Задать кол-во товара
	void setAmount( const int amount);

#pragma endregion setters

	// Перегрузка оператора равно
	Product operator=(const Product &right );

#pragma region 

	// Вернет наименование товара
	std::string getName() const;

	// Вернет форму выпуска
	std::string getForm() const;

	// Вернет наименование компании
	std::string getCompany() const;

	// Вернет цену(за шт)
	float getPrice() const;

	// Вернет кол-во товара
	int getAmount() const;

#pragma endregion getters

	void printProduct();

private:

	// Наименование товара
	std::string name;

	// Форма выпуска товара
	std::string form;

	// Наименование производителя товара
	std::string company;

	// Цена товара за шт
	float price;

	// Кол-во товара
	int amount;

};

