#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

class Sales_data{
	//为Sales_data的非成员函数所做的友元声明
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	//其它成员及访问说明符与之前一致
public://新增的构造函数
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p):
		bookNo(s),units_sold(n),revenue(p*n){ }
	explicit Sales_data(const std::string &s):bookNo(s){ }
	explicit Sales_data(std::istream&);
	
	//新成员：关于Sales_data对象的操作
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
private:
	double avg_price() const;
	//数据成员
	std::string bookNo;//书号
	unsigned units_sold = 0;//售出量
	double revenue = 0.0;//销售收入
};
//Sales_data的非成员接口函数
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
	units_sold += rhs.units_sold;//把rhs的成员加到this对象的成员上
	revenue += rhs.revenue;
	return *this;//返回调用该函数的对象
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
	Sales_data sum = lhs; //把lhs的数据成员拷贝给sum
	sum.combine(rhs);//把rhs的数据成员加到sum当中
	return sum;
}

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);//read函数的作用是从is中读取一条交易信息然后存入this对象中
}

#endif