#pragma once
#include "Product.h"

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

