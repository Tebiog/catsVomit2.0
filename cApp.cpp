#include "cApp.h"

wxIMPLEMENT_APP(cApp);//������ ��� �������� ����� ����� � ���������(win main - ������ "main" � WX).


cApp::cApp()
{
}

cApp::~cApp()
{
}

bool cApp::OnInit()//�������������/����� mainFram'a.
{
	_mFrame = new cMain();
	_mFrame->Show();

	return true;
}
