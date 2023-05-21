#include"PointLight.h"

PointLight::PointLight(Vector3D _position, double _intensity)
{
	type = "Point";
	position = _position;
	intensity = _intensity;
}

void PointLight::SaveData()
{
	fstream plfs("./Data/PointLight.txt", ios::app);
	if (!plfs)
	{
		MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
		system("pause");
		exit(0);
	}

	plfs << position.X << ' ' << position.Y << ' ' << position.Z << ' ' << intensity << endl;
	plfs.close();
}


double PointLight::ComputeLighting(vector<Object*> Objects, HitResult hit, Ray ray)
{
	double FinalIntensity = 0;
	Vector3D N = hit.Normal;
	Vector3D L = position - hit.HitPoint;

	HitResult res = Shoot(Objects, Ray(hit.HitPoint, L));//阴影
	if (res.IsHit)
	{
		return FinalIntensity;
	}

	FinalIntensity += intensity * max(GetCos(N, L), 0.0);//漫反射

	if (hit.material.specular)//镜面反射
	{
		Vector3D V = -ray.Direction;
		Vector3D R = 2 * N * Dot(N, L) - L;
		double CosRV = GetCos(R, V);
		if (CosRV > 0)
		{
			FinalIntensity += intensity * pow(CosRV, hit.material.specular);
		}
	}

	return FinalIntensity;
}

PointLight::~PointLight()
{

}