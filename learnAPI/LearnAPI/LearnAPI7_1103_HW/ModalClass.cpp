#include "ModalClass.h"
#include "AppWindow.h"
ModalClass* ModalClass::modalwindow = NULL;


ModalClass::ModalClass()
{
	modalwindow = this;
}

ModalClass::~ModalClass()
{

}

int ModalClass::MessageLoop()
{
	return 0;
}

LRESULT ModalClass::ModalProc(HWND mhWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		
	case WM_CREATE:
		

		break;
	case WM_INITDIALOG: {// 왜인지 create 부분에서 하면 제대로 되지 않음
		x_Scrolbar = (HWND)GetDlgItem(mhWnd, IDC_SCROLLBAR1);
		y_Scrolbar = (HWND)GetDlgItem(mhWnd, IDC_SCROLLBAR2);
		SetScrollRange(x_Scrolbar, SB_CTL, 1, 8, TRUE);
		SetScrollPos(x_Scrolbar, SB_CTL, 4, TRUE);
		SetScrollRange(y_Scrolbar, SB_CTL, 1, 8, TRUE);
		SetScrollPos(y_Scrolbar, SB_CTL, 4, TRUE);
	}
	case WM_HSCROLL: {
		
		bool x;
		if ((HWND)lParam == x_Scrolbar)
			x = true;
		else
			x = false;
		int tempPos = GetScrollPos((x ? x_Scrolbar : y_Scrolbar), SB_CTL);
		switch (LOWORD(wParam))
		{
		case SB_LINELEFT:
			tempPos = max(1, tempPos - 1);
			break;
		case SB_LINERIGHT:
			tempPos = min(8, tempPos + 1);
			break;
		case SB_PAGELEFT:
			tempPos = max(1, tempPos - 1);

			break;
		case SB_PAGERIGHT:
			tempPos = min(8, tempPos + 1);
			break;
		case SB_THUMBTRACK:
			tempPos = HIWORD(wParam);
			break;
		default:
			break;
		}
		SetScrollPos((x ? x_Scrolbar : y_Scrolbar), SB_CTL, tempPos, TRUE);
		TCHAR ss[MAX_PATH] = { 0, };

		_stprintf_s(ss, -1, L"가로뱡향 : %d, 세로 방향 : %d", GetScrollPos(x_Scrolbar, SB_CTL), GetScrollPos(y_Scrolbar, SB_CTL));
		SetDlgItemText(mhWnd, IDC_STATIC, ss);
		
		break; 
	}
	case WM_COMMAND:
	{
		
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDOK: {
			
			AppWindow::div_x = GetScrollPos(x_Scrolbar, SB_CTL);
			AppWindow::div_y = GetScrollPos(y_Scrolbar, SB_CTL);
		}

		case IDCANCEL:
		case IDM_EXIT:
			EndDialog(mhWnd, 0);
			break;
		default:
			return DefWindowProc(mhWnd, message, wParam, lParam);
		}
	}
	break;
	
	case WM_DESTROY:
		EndDialog(mhWnd, 0);

		break;
	default:
		return DefWindowProc(mhWnd, message, wParam, lParam);
	}

	return LRESULT();
}

LRESULT ModalClass::statiproc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	return modalwindow->ModalProc(hWnd, iMsg, wParam, lParam);
}

void ModalClass::createModalwindow(HWND shwnd, LPCTSTR resource, HINSTANCE _hInst)
{
	_Inst = _hInst;
	DialogBox(_Inst, resource, shwnd, statiproc);

	return;
}


