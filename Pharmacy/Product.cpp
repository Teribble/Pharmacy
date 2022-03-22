﻿#include "Product.h"

Product::Product()
{
	this->name = "не указано наименование";
	this->form = "не указана форма выпуска";
	this->company = "не указана компания";
	this->price = 0;
	this->amount = 0; 
}

Product Product::manualInput()
{
	Product buffer;
	std::string buffname;
	float buffprice;
	int buffamount;
	std::cout << "Введите наименование продукта: ";
	std::cin >> buffname;
	buffer.setName( buffname );
	std::cout << "Введите форму продукта: ";
	std::cin >> buffname;
	buffer.setForm( buffname );
	std::cout << "Введите компанию продукта: ";
	std::cin >> buffname;
	buffer.setCompany( buffname );
	std::cout << "Введите цену за штуку продукта: ";
	std::cin >> buffprice;
	buffer.setPrice( buffprice );
	std::cout << "Введите кол-во продукта: ";
	std::cin >> buffamount;
	buffer.setAmount( buffamount );
	return buffer;
}

void Product::setName( const std::string name )
{
	this->name = name;
}

void Product::setForm( const std::string form )
{
	this->form = form;
}

void Product::setCompany( const std::string company )
{
	this->company = company;
}

void Product::setPrice( const float price )
{
	this->price = price;
}

void Product::setAmount( const int amount )
{
	this->amount = amount;
}

Product Product::operator=(const Product &right )
{
	this->name = right.name;
	this->form = right.form;
	this->company = right.company;
	this->price = right.price;
	this->amount = right.amount;
	return *this;
}

std::string Product::getName() const
{
	return this->name;
}

std::string Product::getForm() const
{
	return this->form;
}

std::string Product::getCompany() const
{
	return this->company;
}

float Product::getPrice() const
{
	return this->price;
}

int Product::getAmount() const
{
	return this->amount;
}

void Product::printProduct()
{
	std::cout << this->name << " " << this->form << " " << this->company << " " << this->price << " " << this->amount << "\n";
}
