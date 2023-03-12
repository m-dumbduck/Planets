#include <Windows.h>
#include "Graphics.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE prevInstance, _In_ LPWSTR cmd, _In_ int nCmdShow)
{
	WNDCLASSEX windowclass;
	ZeroMemory(&windowclass, sizeof(WNDCLASSEX));
	windowclass.cbSize = sizeof(WNDCLASSEX);
	windowclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowclass.hInstance = hInstance;
	windowclass.lpfnWndProc = WindowProc;
	windowclass.lpszClassName = (LPWSTR)"MainWindow";
	windowclass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&windowclass);

	RECT rect = { 0, 0, 800, 600 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND windowhandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, (LPWSTR)"MainWindow", (LPWSTR)"Planets", WS_OVERLAPPEDWINDOW,
		100, 100, rect.right, rect.bottom - rect.top, NULL, NULL, hInstance, 0);
	if (!windowhandle)
		return -1;

	ShowWindow(windowhandle, nCmdShow);

	MSG message;
	while (GetMessage(&message, NULL, 0, 0))
	{
		DispatchMessage(&message);

	}


	return 0;
}
