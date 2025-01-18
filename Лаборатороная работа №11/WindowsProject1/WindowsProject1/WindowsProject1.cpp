#include "Windows.h"
#include <cmath>
#include "Resource.h"

HWND hEditInput, hEditOutput1, hEditOutput2;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE: {
        CreateWindow(L"STATIC", L"Введите вещественное число:",
            WS_VISIBLE | WS_CHILD, 20, 20, 200, 20, hwnd, (HMENU)1, NULL, NULL);

        hEditInput = CreateWindow(L"EDIT", L"",
            WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 50, 200, 20, hwnd, (HMENU)2, NULL, NULL);

        CreateWindow(L"STATIC", L"Целая часть:",
            WS_VISIBLE | WS_CHILD, 20, 80, 200, 20, hwnd, (HMENU)3, NULL, NULL);

        hEditOutput1 = CreateWindow(L"EDIT", L"",
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY, 20, 110, 200, 20, hwnd, (HMENU)4, NULL, NULL);

        CreateWindow(L"STATIC", L"Округленное значение:",
            WS_VISIBLE | WS_CHILD, 20, 140, 200, 20, hwnd, (HMENU)5, NULL, NULL);

        hEditOutput2 = CreateWindow(L"EDIT", L"",
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY, 20, 170, 200, 20, hwnd, (HMENU)6, NULL, NULL);

        CreateWindow(L"BUTTON", L"Вычислить",
            WS_VISIBLE | WS_CHILD, 20, 200, 200, 30, hwnd, (HMENU)7, NULL, NULL);
        break;
    }

    case WM_COMMAND: {
        if (LOWORD(wParam) == 7) {  
            wchar_t inputBuffer[256];
            GetWindowText(hEditInput, inputBuffer, 256);
            double number = _wtof(inputBuffer); 

            if (number == 0.0 && inputBuffer[0] != L'0') {
                MessageBox(hwnd, L"Введите корректное вещественное число", L"Ошибка ввода", MB_OK | MB_ICONERROR);
                break;
            }

            int intPart = (int)number;
            int rounded = (int)round(number);  

            wchar_t outputBuffer[256];
            wsprintf(outputBuffer, L"%d", intPart); 
            SetWindowText(hEditOutput1, outputBuffer);

            wsprintf(outputBuffer, L"%d", rounded); 
            SetWindowText(hEditOutput2, outputBuffer);
        }
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"CalculatorWindow";
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, wc.lpszClassName, L"Калькулятор",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 250, 300, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL)
        return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
