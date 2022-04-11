#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

class Sales_data{
	//ΪSales_data�ķǳ�Ա������������Ԫ����
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	//������Ա������˵������֮ǰһ��
public://�����Ĺ��캯��
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p):
		bookNo(s),units_sold(n),revenue(p*n){ }
	explicit Sales_data(const std::string &s):bookNo(s){ }
	explicit Sales_data(std::istream&);
	
	//�³�Ա������Sales_data����Ĳ���
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
private:
	double avg_price() const;
	//���ݳ�Ա
	std::string bookNo;//���
	unsigned units_sold = 0;//�۳���
	double revenue = 0.0;//��������
};
//Sales_data�ķǳ�Ա�ӿں���
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

double Sales_data::avg_price()const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;//��rhs�ĳ�Ա�ӵ�this����ĳ�Ա��
	revenue += rhs.revenue;
	return *this;//���ص��øú����Ķ���
}

std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
	Sales_data sum = lhs; //��lhs�����ݳ�Ա������sum
	sum.combine(rhs);//��rhs�����ݳ�Ա�ӵ�sum����
	return sum;
}

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);//read�����������Ǵ�is�ж�ȡһ��������ϢȻ�����this������
}

#endif