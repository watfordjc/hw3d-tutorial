#include <Windows.h>
#include <sstream>

/// <summary>
/// Get applicable window title
/// </summary>
/// <param name="useAlt">Whether the alternative title should be used.</param>
/// <returns>The window title the window should use.</returns>
LPCWSTR GetWindowTitle(bool useAlt = false)
{
	return useAlt ? L"F is pressed!" : L"Main Window";
}

/// <summary>
/// Window procedure
/// </summary>
/// <param name="hwnd">A handle to the window.</param>
/// <param name="uMsg">The message.</param>
/// <param name="wParam">Additional message information. The contents of this parameter depend on the value of the <c>uMsg</c> parameter.</param>
/// <param name="lParam">Additional message information. The contents of this parameter depend on the value of the <c>uMsg</c> parameter.</param>
/// <returns>The result of the message processing; depends on the message sent.</returns>
/// <seealso href="https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms633573(v=vs.85)" />
LRESULT CALLBACK WndProc(
	_In_ HWND hwnd,
	_In_ UINT uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_CLOSE: // Window or application should terminate
		PostQuitMessage(0);
		break;
	case WM_HELP: // F1 (help)
		ShellExecute(0, 0, L"https://github.com/watfordjc/hw3d-tutorial", 0, 0, SW_SHOW);
		break;
	case WM_KEYDOWN: // Key press
		if (wParam == 'F')
		{
			SetWindowText(hwnd, GetWindowTitle(true));
		}
		break;
	case WM_KEYUP: // Key release
		if (wParam == 'F')
		{
			SetWindowText(hwnd, GetWindowTitle());
		}
		break;
	case WM_LBUTTONDOWN: // Left mouse button click
		{
			const POINTS pt = MAKEPOINTS(lParam);
			std::wstringstream wss;
			wss << "(" << pt.x << "," << pt.y << ")";
			SetWindowText(hwnd, wss.str().c_str());
		}
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

/// <summary>
/// The user-provided entry point for a graphical Windows-based application.
/// </summary>
/// <param name="hInstance">A handle to the current instance of the application.</param>
/// <param name="hPrevInstance">A handle to the previous instance of the application. This parameter is always <c>NULL</c>.</param>
/// <param name="lpCmdLine">The command line for the application, excluding the program name.</param>
/// <param name="nCmdShow">Controls how the window is to be shown.</param>
/// <returns>If terminating before the message loop, <c>0</c>. If terminating in response to a <c>WM_QUIT</c> message, that message's <c>wParam</c> parameter value.</returns>
/// <seealso href="https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-winmain" />
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	const LPCWSTR pClassName = L"hw3d";
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
		GetWindowTitle(),
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
	return (int)msg.wParam;
}
