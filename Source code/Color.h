#ifndef COLOR_H
#define COLOR_H
#include<algorithm>
using std::min;
using std::max;

class Color
{
public:
	int R, G, B;

	Color(int _R = 0, int _G = 0, int _B = 0);

	friend Color operator+(Color CL, Color CR);

	friend Color operator-(Color CL, Color CR);

	friend Color operator*(Color C, double K);

	friend Color operator*(double K, Color C);

	friend Color operator/(Color C, double K);


	~Color();
};
#endif
