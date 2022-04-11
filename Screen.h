#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <string>

class Screen {
public:
	typedef std::string::size_type pos;
	//Window_mgr::clear必须在Screen类之前被声明
	friend class Window_mgr;
	Screen() = default;//因为Screen有另一个构造函数
						//所有本函数是必需的
	//cursor被其类内初始值初始化为0
	Screen(pos ht, pos wd, char c):height(ht),width(wd),
		contents(ht * wd, c){ }
	Screen(pos ht, pos wd):height(ht),width(wd){ }
	//根据对象是否是const重载了display函数
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os)const 
	{
		do_display(os);
		return *this;
	}
	Screen &set(char);
	Screen &set(pos, pos, char);
	void some_member() const;
	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
private:
	mutable size_t access_ctr;//即使在一个const对象内也能被修改
	//该函数负责显示Screen的内容
	void do_display(std::ostream &os) const { os << contents; }
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents = " ";
};

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;//设置给定位置的新值
	return *this;//将this对象作为左值返回
}

void Screen::some_member() const
{
	++access_ctr;//保存一个计数值，用于记录成员函数被调用的次数
	//该成员需要完成的其它工作
}

inline Screen &Screen::move(pos r, pos c)//可以在函数的定义处指定inline
{
	pos row = r * width;//计算行的位置
	cursor = row + c;//在行内将光标移动到指定的列
	return *this;//以左值的形式返回对象
}
char Screen::get(pos r, pos c)const//在类的内部声明成inline
{
	pos row = r * width;//计算行的位置
	return contents[row + c];//返回给定列的字符
}
#endif // !SCREEN_H

