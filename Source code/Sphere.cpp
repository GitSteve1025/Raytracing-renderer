#include"Sphere.h"

Sphere::Sphere(double _R, Vector3D _O, Material _material)
{
	R = _R;
	O = _O;
	material = _material;
}

void Sphere::SaveData()
{
	fstream sfs("./Data/Sphere.txt", ios::app);
	if (!sfs)
	{
		MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
		system("pause");
		exit(0);
	}

	sfs << R << ' ' << O.X << ' ' << O.Y << ' ' << O.Z << ' ' << material.color.R << ' ' << material.color.G << ' ' << material.color.B << ' ' << material.specular << ' ' << material.reflective << endl;
	sfs.close();
}


//射线求交
HitResult Sphere::Intersect(Ray ray)
{
	HitResult Res;
	Vector3D S = ray.Start;
	Vector3D D = ray.Direction;

	Vector3D SO = S - O;
	double A = Dot(D, D);
	double B = 2.0 * Dot(SO, D);
	double C = Dot(SO, SO) - R * R;
	double Discriminant = B * B - 4.0 * A * C;
	double D1 = (-B - sqrt(Discriminant)) / (2 * A);
	double D2 = (-B + sqrt(Discriminant)) / (2 * A);
	if (Discriminant < 0 || D1 < eps)//eps 防止交自己
	{
		Res.IsHit = false;
		return Res;
	}
	Res.IsHit = true;
	double T = D1 > 0 ? D1 : D2;
	Res.Distance = T;
	Res.HitPoint = S + T * D;
	Res.Normal = Unit(Res.HitPoint - O);
	Res.material = material;
	return Res;
}

Sphere::~Sphere()
{

}