#pragma once
#include <iostream>

// �����
class Product
{
public:

	// �����������
	Product();

#pragma region setters

	// ������ ������������ ������
	void setName(const std::string name);

	// ������ ����� �������
	void setForm( const std::string form);

	// ������ ������������ ��������
	void setCompany( const std::string company);

	// ������ ���� ������(�� ��)
	void setPrice( const float price);

	// ������ ���-�� ������
	void setAmount( const int amount);

#pragma endregion setters

	// ���������� ��������� �����
	Product operator=(const Product &right );

#pragma region 

	// ������ ������������ ������
	std::string getName() const;

	// ������ ����� �������
	std::string getForm() const;

	// ������ ������������ ��������
	std::string getCompany() const;

	// ������ ����(�� ��)
	float getPrice() const;

	// ������ ���-�� ������
	int getAmount() const;

#pragma endregion getters

	void printProduct();

private:

	// ������������ ������
	std::string name;

	// ����� ������� ������
	std::string form;

	// ������������ ������������� ������
	std::string company;

	// ���� ������ �� ��
	float price;

	// ���-�� ������
	int amount;

};

