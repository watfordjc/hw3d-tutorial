#include <Windows.h>

LRESULT CALLBACK WndProc(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (Msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	const auto pClassName = L"hw3d";
	// Register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	// Create window instance
	HWND hWnd = CreateWindowEx(
		0,
		pClassName,
		L"Main Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, // window origin x
		200, // window origin y
		640, // width
		480, // height
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	// Show the window
	ShowWindow(hWnd, SW_SHOW);

	// Message loop
	MSG msg;
	BOOL gResult;
	while (gResult = GetMessage(
		&msg,
		nullptr,
		0,
		0
	) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gResult == -1)
	{
		return -1;
	}
	return msg.wParam;
}