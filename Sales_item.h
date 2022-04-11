#include<string>
class Sales_item
{
public:
	Sales_item(std::string a = "",unsigned b = 0, double c = 0.0)
		:ISBN(a),num(b),average(c)
	{
	};


private:
	std::string ISBN;
	unsigned int num;
	double average;
};

extern const int bufSize;

