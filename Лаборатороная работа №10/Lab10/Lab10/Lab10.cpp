#include <windows.h>

HINSTANCE hInst;
HWND hWnd; 
POINT ptStart, ptEnd; 
bool isDrawing = false; 
bool isRightClick = false;
HPEN hPenRed;
HBRUSH hBrushGreen;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow) {
    hInst = hInstance;

    WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0, hInstance,
                        LoadIcon(NULL, IDI_APPLICATION), LoadCursor(NULL, IDC_ARROW),
                        (HBRUSH)(COLOR_WINDOW + 1), NULL, L"DrawingApp" };

    RegisterClassEx(&wcex);

    hWnd = CreateWindow(L"DrawingApp", L"Простой графический редактор", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_RBUTTONDOWN: { 
        ptStart.x = LOWORD(lParam);
        ptStart.y = HIWORD(lParam);
        isRightClick = true;
        break;
    }
    case WM_RBUTTONUP: { 
        if (isRightClick) {
            ptEnd.x = LOWORD(lParam);
            ptEnd.y = HIWORD(lParam);

            int width = abs(ptEnd.x - ptStart.x);
            int height = abs(ptEnd.y - ptStart.y);

            if (width < 50) width = 50;
            if (height < 50) height = 50;

            HDC hdc = GetDC(hwnd);

            hPenRed = CreatePen(PS_DASH, 1, RGB(255, 0, 0));
            SelectObject(hdc, hPenRed);

            hBrushGreen = CreateSolidBrush(RGB(0, 255, 0));
            SelectObject(hdc, hBrushGreen);

            Ellipse(hdc, ptStart.x, ptStart.y, ptStart.x + width, ptStart.y + height);

            DeleteObject(hPenRed);
            DeleteObject(hBrushGreen);
            ReleaseDC(hwnd, hdc);
            isRightClick = false;
        }
        break;
    }
    case WM_MOUSEMOVE: { 
        if (isDrawing) {
            HDC hdc = GetDC(hwnd);
            ptEnd.x = LOWORD(lParam);
            ptEnd.y = HIWORD(lParam);

            InvalidateRect(hwnd, NULL, TRUE);

                MoveToEx(hdc, ptStart.x, ptStart.y, NULL);
            LineTo(hdc, ptEnd.x, ptEnd.y);
            ReleaseDC(hwnd, hdc);
        }
        break;
    }
    case WM_PAINT: { 
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        EndPaint(hwnd, &ps);
        break;
    }
    case WM_DESTROY: { 
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}