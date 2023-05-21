#ifndef VECTOR3D_H
#define VECTOR3D_H
#include<math.h>

class Vector3D
{
public:
	double X, Y, Z;

	Vector3D(double _X = 0, double _Y = 0, double _Z = 0);

	double Length();

	double SquareLength();

	friend Vector3D Unit(Vector3D V);

	friend double GetCos(Vector3D VL, Vector3D VR);

	friend Vector3D GetNormal(Vector3D VL, Vector3D VR);

	friend Vector3D operator-(Vector3D V);

	friend Vector3D operator+(const Vector3D& VL, const Vector3D& VR);

	friend Vector3D operator-(const Vector3D& VL, const Vector3D& VR);

	friend double Dot(const Vector3D& VL, const Vector3D& VR);

	friend Vector3D operator*(const Vector3D& VL, const double& K);

	friend Vector3D operator*(const double& K, const Vector3D& VR);

	friend Vector3D operator/(const Vector3D& VL, const double& K);

	Vector3D operator+=(const Vector3D& V);

	Vector3D operator-=(const Vector3D& V);

	Vector3D operator*=(const double& K);

	Vector3D operator/=(const double& K);

	~Vector3D();
};
#endif
