#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include <vector>
#include "Screen.h"

class Window_mgr
{
public:
	//������ÿ����Ļ�ı��
	using ScreenIndex = std::vector<Screen>::size_type;
	//�򴰿����һ��Screen���������ı��
	ScreenIndex addScreen(const Screen&);
	//���ձ�Ž�ָ����Screen����Ϊ�հ�
	void clear(ScreenIndex);

private:
	//���Window_mgr׷�ٵ�Screen
	//Ĭ������£�һ��Window_mgr����һ����־�ߴ�Ŀհ�Screen
	std::vector<Screen> screens{ Screen(24,80,' ') };

};
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

void Window_mgr::clear(ScreenIndex i)
{
	//s��һ��Screen�����ã�ָ����������յ��Ǹ���Ļ
	Screen &s = screens[i];
	//���Ǹ�ѡ����Screen����Ϊ�հ�
	s.contents = std::string(s.height * s.width, ' ');
}


#endif
