# LearnAPI 1026

creatWindow( ) 윈도우 만들기 

```cpp
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam) {

	switch (uMsg)
	{
	case WM_CREATE:
		CreateWindow(L"Button",L"Click me", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			20,20,100,25,hWnd,(HMENU)ID_CON_BUTTON_1,_hInst,NULL);  //윈도우에 이미 버튼이 등록되어 있음
		break;
	case WM_COMMAND: {
		int id = LOWORD(wParam);
		switch (id)
		{
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_CON_BUTTON_1:
			SetWindowText(hWnd, L"버튼을 눌렀어요 ");
		default:
			break;
		}
		break;

	}

	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return (DefWindowProc(hWnd, uMsg, wParam, IParam));
}

```

