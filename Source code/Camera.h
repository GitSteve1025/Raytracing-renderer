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
	Vector3D Viewport;//�ӿ�
	Vector3D forward;//�ӿ�ָ�򻭲��ķ�����
	Vector3D right;//����ĵ�λ����
	Vector3D up;//���ϵĵ�λ����
	int Height, Width;//�����ĳ� ��
	double Distance;//�ӿڵ������ľ���

	Camera();

	Ray GetRay(double X, double Y);//�����ϵ�X Y

	Color RayTracing(vector<Object*> Objects, vector<Light*> light, Ray ray, int Recursion = 5);

	Camera(Vector3D _Viewport, int _Width, int _Height, double _Distance, Vector3D _right = {1, 0, 0}, Vector3D _up = {0, 1, 0},  Vector3D _forward = {0, 0, 1});

	~Camera();
};
#endif