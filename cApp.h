#pragma once
#include "wx/wx.h"
#include "cMain.h"

class cApp : public wxApp//wxApp - ������� ����� wx ����������
{
public:

	cApp();
	~cApp();

	virtual bool OnInit();

private:
	cMain* _mFrame = nullptr;

};

