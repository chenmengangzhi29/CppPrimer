#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <string>

class Screen {
public:
	typedef std::string::size_type pos;
	//Window_mgr::clear������Screen��֮ǰ������
	friend class Window_mgr;
	Screen() = default;//��ΪScreen����һ�����캯��
						//���б������Ǳ����
	//cursor�������ڳ�ʼֵ��ʼ��Ϊ0
	Screen(pos ht, pos wd, char c):height(ht),width(wd),
		contents(ht * wd, c){ }
	Screen(pos ht, pos wd):height(ht),width(wd){ }
	//���ݶ����Ƿ���const������display����
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
	mutable size_t access_ctr;//��ʹ��һ��const������Ҳ�ܱ��޸�
	//�ú���������ʾScreen������
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
	contents[r*width + col] = ch;//���ø���λ�õ���ֵ
	return *this;//��this������Ϊ��ֵ����
}

void Screen::some_member() const
{
	++access_ctr;//����һ������ֵ�����ڼ�¼��Ա���������õĴ���
	//�ó�Ա��Ҫ��ɵ���������
}

inline Screen &Screen::move(pos r, pos c)//�����ں����Ķ��崦ָ��inline
{
	pos row = r * width;//�����е�λ��
	cursor = row + c;//�����ڽ�����ƶ���ָ������
	return *this;//����ֵ����ʽ���ض���
}
char Screen::get(pos r, pos c)const//������ڲ�������inline
{
	pos row = r * width;//�����е�λ��
	return contents[row + c];//���ظ����е��ַ�
}
#endif // !SCREEN_H

