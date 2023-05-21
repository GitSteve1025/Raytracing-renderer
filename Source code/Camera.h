#ifndef CAMERA_H
#define CAMERA_H
#include"Object.h"
#include"Sphere.h"
#include"Light.h"
#include<vector>
using std::vector;

class Camera
{
public:
	Vector3D Viewport;//视口
	Vector3D forward;//视口指向画布的法向量
	Vector3D right;//向左的单位向量
	Vector3D up;//向上的单位向量
	int Height, Width;//画布的长 宽
	double Distance;//视口到画布的距离

	Camera();

	Ray GetRay(double X, double Y);//画布上的X Y

	Color RayTracing(vector<Object*> Objects, vector<Light*> light, Ray ray, int Recursion = 5);

	Camera(Vector3D _Viewport, int _Width, int _Height, double _Distance, Vector3D _right = {1, 0, 0}, Vector3D _up = {0, 1, 0},  Vector3D _forward = {0, 0, 1});

	~Camera();
};
#endif