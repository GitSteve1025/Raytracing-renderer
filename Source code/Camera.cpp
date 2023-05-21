#include"Camera.h"

Camera::Camera()
{
	Viewport = { 0, 0, 0 };
	Width = 512;
	Height = 512;
	Distance = 64;
	right = { 1, 0, 0 };
	up = { 0, 1, 0 };
	forward = { 0, 0, 1 };
}

Camera::Camera(Vector3D _Viewport, int _Width, int _Height, double _Distance, Vector3D _right, Vector3D _up, Vector3D _forward)
{
	Viewport = _Viewport;
	Width = _Width;
	Height = _Height;
	Distance = _Distance;
	right = _right;
	up = _up;
	forward = _forward;
}

//反射
Vector3D Reflect(Vector3D L, Vector3D N)
{
	return 2 * N * Dot(N, L) - L;
}

Ray Camera::GetRay(double X, double Y)
{
	return Ray(Viewport, X * right + Y * up + Distance * forward);
}

Color Camera::RayTracing(vector<Object*> Objects, vector<Light*> light, Ray ray, int Recursion)
{
	HitResult res = Shoot(Objects, ray);
	if (!res.IsHit)
	{
		return { 255, 255, 255 };
	}

	Color CurColor;
	double intensity = 0.0;
	for (auto& p : light)
	{
		intensity += p->ComputeLighting(Objects, res, ray);
	}
	CurColor =  res.material.color * min(intensity, 1.0);//防止光强过高
	
	if (Recursion <= 0 || res.material.reflective <= 0)
	{
		return CurColor;
	}
	
	Vector3D D = ray.Direction;
	Vector3D N = res.Normal;
	Vector3D L = Reflect(-D, N);

	Color ReflectColor = RayTracing(Objects, light, Ray(res.HitPoint, L), Recursion - 1);

	return CurColor * (1 - res.material.reflective) + ReflectColor * res.material.reflective;
}


Camera::~Camera()
{

}