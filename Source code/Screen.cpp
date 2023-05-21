#include"Screen.h"

void FixScreen()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLongPtr(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
}

void InitScreenSize(const SHORT& Width, const SHORT& Height)
{
	char Setting[40];
	sprintf_s(Setting, "mode con:cols=%d lines=%d", Width, Height);
	system(Setting);
}

void SetTextSize(const SHORT& ScreenTextSize)
{
	HANDLE Hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX Cfi = { sizeof(CONSOLE_FONT_INFOEX) };
	GetCurrentConsoleFontEx(Hout, FALSE, &Cfi);
	Cfi.dwFontSize.X = 0, Cfi.dwFontSize.Y = ScreenTextSize; 		//ด๓ะก
	SetCurrentConsoleFontEx(Hout, FALSE, &Cfi);
}

void Gotoxy(const SHORT& X, const SHORT& Y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { X, Y });
}

DWORD PutColor(const SHORT& X, const SHORT& Y, const Color& color)
{
    HANDLE Hout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (Hout == INVALID_HANDLE_VALUE)return GetLastError();
    DWORD dwMode = 0;
    if (!GetConsoleMode(Hout, &dwMode))return GetLastError();
    dwMode |= 0x0004;
    if (!SetConsoleMode(Hout, dwMode))return GetLastError();
	Gotoxy(X, Y);
    wprintf(L"\x1b[38;2;%d;%d;%dmM", color.R, color.G, color.B);
}

void InitScreen(const SHORT& Width, const SHORT& Height, const SHORT& ScreenTextSize)
{
	SetTextSize(ScreenTextSize);
	InitScreenSize(Width, Height);
	FixScreen();
}