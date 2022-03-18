#pragma once
#include "Product.h"
#include <conio.h>

#define one 49
#define two 50
#define three 51
#define fore 52
#define five 53

#define TEN 10
class Warehouse
{
public:

	// �����������
	Warehouse();

	// ����������(�������������)
	virtual ~Warehouse();

	// �������� ����� ������� �� �����
	void addNewProduct(Product newProduct);

	// ������� ��������� ������� �� ������
	void deleteProduct( const int position );

	// �������� ��������� �������
	void changeProduct( const int position );

	// ������ ���-�� ������� �� ������
	int getCounter() const;

	// ������� ������ ������� �� ������
	void print();

private:
	
	// ������ �����?
	bool isEmpty();

	// ������ �����?
	bool isFull();

	// ������ ������� �� ������
	Product *list;

	// ���������� ������� �� ������
	int counter;

	// "������������" ������ ������, ������� ��� ����������� ��� ������������
	int capasity;
};

