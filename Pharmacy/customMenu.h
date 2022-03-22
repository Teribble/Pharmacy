#pragma once
#include <string>
#include <conio.h>
#include "iHelper.h"

// Собери сам таблицу
class customMenu
{
public:

	// Конструктор
	customMenu();

	// Деструктор(деконструктор)
	virtual ~customMenu();

	// Добавить новую позицию в таблицу
	void addButtons(std::string newButton);

	// Вернет имя позиции
	std::string getNameButtons(int count) const;

	// Навигация
	int choiceMenu( int x , int y );

	// Указать вертикальная(0) или горизонтальная(1) позиция
	void setDirection( int num );

	// Стирает прошлое меню
	void deleteMenu( int x , int y );

private:

	// Показать вертикальную таблицу
	void moveVertically( int x , int y ) const;

	// Показать горизонтальную таблицу
	void moveHorizontally( int x , int y ) const;

	// Пуста ли таблица
	bool isEmpty();

	// Массив строк таблицы
	std::string* buttons;

	// Выбор
	int choice;

	// Элементы таблицы
	int counter;

	// Максимальная длина элемента таблицы(название в чарах)
	int maxSizeStr;

	// Вертикальная или горизонтальная
	int direction;
};

