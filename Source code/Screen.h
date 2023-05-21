#ifndef SCREEN_H
#define SCREEN_H
#include"Color.h"
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<cstdio>

void FixScreen();

void SetTextSize(const SHORT& ScreenTextSize);

void InitScreenSize(const SHORT& Width, const SHORT& Height);

void Gotoxy(const SHORT& X, const SHORT& Y);

DWORD PutColor(const SHORT& X, const SHORT& Y, const Color& color);

void InitScreen(const SHORT& Width, const SHORT& Height, const SHORT& ScreenTextSize);
#endif
