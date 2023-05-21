#include"Color.h"

Color::Color(int _R, int _G, int _B)
{
	R = min(_R, 255);
	G = min(_G, 255);
	B = min(_B, 255);
}

Color operator+(Color CL, Color CR)
{
	return Color(min((CL.R + CR.R), 255), min((CL.G + CR.G), 255), min((CL.B + CR.B), 255));
}


Color operator-(Color CL, Color CR)
{
	return Color(max((CL.R - CR.R), 0), max((CL.G - CR.G), 0), max((CL.B - CR.B), 0));
}

Color operator*(Color C, double K)
{
	return Color(K * C.R, K * C.G, K * C.B);
}

Color operator*(double K, Color C)
{
	return Color(K * C.R, K * C.G, K * C.B);
}

Color operator/(Color C, double K)
{
	return Color(C.R / K, C.G / K, C.B / K);
}

Color::~Color()
{

}