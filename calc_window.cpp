// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <string>
#include <gdiplus.h>
#include <wingdi.h>

using namespace std;

// Global variables

// The main window class name.
    static TCHAR szWindowClass[] = _T("CalcApp");

// The string that appears in the application's title bar.
    static TCHAR szTitle[] = _T("Simple Calculator App");

    HINSTANCE hInst;

// Forward declarations of functions included in this code module:
    LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow )
{
        WNDCLASSEX wcex;
        wcex.cbSize = sizeof(WNDCLASSEX);
        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WndProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = hInstance;
        wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
        wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
        wcex.lpszMenuName = NULL;
        wcex.lpszClassName = szWindowClass;
        wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
        
        if (!RegisterClassEx(&wcex)) {
            MessageBox (NULL,
                _T("Call to RegisterClassEx failed!"),
                _T("Calculator App"),
                0);

            return 1;
        }

        // Store instance handle in our global variable
        hInst = hInstance;

        // The parameters to CreateWindow explained:
        // szWindowClass: the name of the application
        // szTitle: the text that appears in the title bar

        HWND hWnd = CreateWindow(
            szWindowClass,
            szTitle,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            250, 400,
            NULL,
            NULL,
            hInstance,
            NULL);

        HWND hwnd_add_Button = CreateWindow( 
            _T("BUTTON"), 
            _T("+"),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            180, 
            255, 
            40, 
            40, 
            hWnd, 
            NULL, 
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), 
            NULL
        );

        HWND hwnd_equal_Button = CreateWindow( 
            _T("BUTTON"), 
            _T("="),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            180, 
            300, 
            40, 
            40, 
            hWnd, 
            NULL, 
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), 
            NULL
        );

        HWND hwnd_sub_Button = CreateWindow( 
            _T("BUTTON"), 
            _T("-"),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            180, 
            210, 
            40, 
            40, 
            hWnd, 
            NULL, 
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), 
            NULL
        );

        HWND hwnd_mult_Button = CreateWindow( 
            _T("BUTTON"), 
            _T("x"),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            180, 
            165, 
            40, 
            40, 
            hWnd, 
            NULL, 
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), 
            NULL
        );

        HWND hwnd_divide_Button = CreateWindow( 
            _T("BUTTON"), 
            _T("/"),
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            180, 
            120, 
            40, 
            40, 
            hWnd, 
            NULL, 
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), 
            NULL
        );
        
        if (!hWnd) {
            MessageBox (
                NULL,
                _T("Call to CreateWindow failed!"),
                _T("Calculator App"),
                0);
                
            return 1;
        }

        // The parameters to ShowWindow explained:
        // hWnd: the value returned from CreateWindow
        // nCmdShow: the fourth parameter from WinMain

        ShowWindow(hWnd, nCmdShow);
        UpdateWindow(hWnd);

        // Main message loop:
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        
        return (int) msg.wParam;
}




// FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
// PURPOSE: Processes messages for the main window.
//
// WM_PAINT - Paint the main window
// WM_DESTROY - post a quit message and return


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc;
    //string s = "Old Message!";
    //const wchar_t* greeting = L"Old Message!"; 
    const RECT* structure;
    switch (message) {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            // Here your application is laid out.
            // For this introduction, we just print out "Hello, Windows desktop!"
            // in the top left corner.
            // TextOutW(hdc, 10, 25, greeting, s.length());
            // End application-specific layout section.
            EndPaint(hWnd, &ps);
            break;
        case WM_DESTROY: 
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
            break;
    }

return 0;
}
