#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		PWSTR pCmdLine, int nCmdShow)
{
	MSG msg = {};
	HWND hwnd = {};
	WNDCLASSW wc = {};

	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.lpszClassName = L"MkBoardsClass";
	wc.hInstance     = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpszMenuName  = NULL;
	wc.lpfnWndProc   = WndProc;
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassW(&wc);
	hwnd = CreateWindowW(wc.lpszClassName,
			L"MKboards",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			100, 100, 800, 640, NULL, NULL, hInstance, NULL);  

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {

		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, 
		WPARAM wParam, LPARAM lParam) {

	switch(msg)
	{
		case WM_DESTROY:
			{
				PostQuitMessage(0);
			} break;
		case WM_KEYDOWN:
			{
				if (wParam == VK_ESCAPE)
				{
					SendMessage(hwnd, WM_CLOSE, 0, 0);
				}
			} break;
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}
