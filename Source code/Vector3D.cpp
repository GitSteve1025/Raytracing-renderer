#include"Vector3D.h"

//初始化
Vector3D::Vector3D(double _X, double _Y, double _Z)
{
	X = _X;
	Y = _Y;
	Z = _Z;
}
//单位化
Vector3D Unit(Vector3D V)
{
	double L = V.Length();
	return Vector3D(V.X / L, V.Y / L, V.Z / L);
}
//获取Cos
double GetCos(Vector3D VL, Vector3D VR)
{
	return Dot(VL, VR) / (VL.Length() * VR.Length());
}
//模长
double Vector3D::Length()
{
	return sqrt(X * X + Y * Y + Z * Z);
}
//模长平方
double Vector3D::SquareLength()
{
	return X * X + Y * Y + Z * Z;
}
//求法向量
Vector3D GetNormal(Vector3D VL, Vector3D VR)
{
	double X = VL.Y * VR.Z - VL.Z * VR.Y;
	double Y = VL.Z * VR.X - VL.X * VR.Z;
	double Z = VL.X * VR.Y - VL.Y * VR.X;
	return Vector3D(X, Y, Z);
}
//向量加
Vector3D operator+(const Vector3D& VL, const Vector3D& VR)
{
	return Vector3D(VL.X + VR.X, VL.Y + VR.Y, VL.Z + VR.Z);
}
//向量减
Vector3D operator-(Vector3D V)
{
	return Vector3D(-V.X, -V.Y, -V.Z);
}

Vector3D operator-(const Vector3D& VL, const Vector3D& VR)
{
	return Vector3D(VL.X - VR.X, VL.Y - VR.Y, VL.Z - VR.Z);
}
//向量乘
double Dot(const Vector3D& VL, const Vector3D& VR)
{
	return VL.X * VR.X + VL.Y * VR.Y + VL.Z * VR.Z;
}

Vector3D operator*(const Vector3D& VL, const double& K)
{
	return Vector3D(VL.X * K, VL.Y * K, VL.Z * K);
}

Vector3D operator*(const double& K, const Vector3D& VR)
{
	return Vector3D(VR.X * K, VR.Y * K, VR.Z * K);
}
//向量除
Vector3D operator/(const Vector3D& VL, const double& K)
{
	return Vector3D(VL.X / K, VL.Y / K, VL.Z / K);
}


//其他
Vector3D Vector3D::operator+=(const Vector3D& V)
{
	this->X += V.X;
	this->Y += V.Y;
	this->Z += V.Z;
	return *this;
}

Vector3D Vector3D::operator-=(const Vector3D& V)
{
	this->X -= V.X;
	this->Y -= V.Y;
	this->Z -= V.Z;
	return *this;
}

Vector3D Vector3D::operator*=(const double& K)
{
	this->X *= K;
	this->Y *= K;
	this->Z *= K;
	return *this;
}

Vector3D Vector3D::operator/=(const double& K)
{
	this->X /= K;
	this->Y /= K;
	this->Z /= K;
	return *this;
}

Vector3D::~Vector3D()
{

}