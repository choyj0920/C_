#include "Ch_Manager.h"

#include "AppWindow.h"
Ch_Manager::Ch_Manager()
{
	finishcount = 0;

}

bool Ch_Manager::add(Character* new_ch)
{
	if (use < CH_COU) {
		charac[use++] = new_ch;
		return true;
	}
	else
		return false;
}

void Ch_Manager::s_start()
{
	for (int i = 0; i < use; i++) {
		charac[i]->work = true;
		charac[i]->randspeed();
	}

}

void Ch_Manager::run()
{
	for (int i = 0; i < use; i++) {
		charac[i]->run();
	}
	check();
}

void Ch_Manager::check()
{
	for (int i = 0; i < use; i++) {
		if (finishline < charac[i]->pos.left+charac[i]->pos.right) {
			if (rank[i] == 0) {
				rank[i] = ++finishcount;
				charac[i]->work = false;
			}
			
		}
	}
	if (finishcount == use) {
		SendMessage(AppWindow::mainWindow->m_hWnd, WM_TIMER, DELETE_TIMER, 0);
	}
}

void Ch_Manager::empty()
{
	for (int i = 0; i < CH_COU; i++) {
		if (charac[i] != NULL)
			delete charac[i];

	}
	finishcount = 0;
	use = 0;
	for (int i = 0; i < CH_COU; i++) {
		rank[i] = 0;
	}
}

void Ch_Manager::randspeed()
{
	for (int i = 0; i < use; i++) {
		if(charac[i]->work)
			charac[i]->randspeed();
	}
}

Ch_Manager::~Ch_Manager()
{
	for (int i = 0; i < CH_COU; i++) {
		if (charac[i] != NULL)
			delete charac[i];

	}
}

void Ch_Manager::draw(HDC hdc)
{
	for (int i = 0; i < use; i++) {
		if (rank[i] != 0) {
			TCHAR ss[MAX_PATH] = { 0, };
			swprintf_s(ss, L"%d µî", rank[i], -1);
			TextOut(hdc, charac[i]->pos.left - 100, charac[i]->pos.top, ss, lstrlenW(ss));
		}
		
		imgdr.PiceDrawImage(hdc, charac[i]->filename, charac[i]->pos, (charac[i]->now_ani % 4) * 135, (charac[i]->now_ani / 4) * 99, 135, 99);
		TCHAR ss[MAX_PATH] = { 0, };
		swprintf_s(ss, L"%d ¹ø¸»", i + 1, -1);
		TextOut(hdc, charac[i]->pos.left , charac[i]->pos.top, ss, lstrlenW(ss));
	}
}


