#include"DirectionalLight.h"

DirectionalLight::DirectionalLight(Vector3D _direction, double _intensity)
{
	type = "Directional";
	direction = _direction;
	intensity = _intensity;
}


void DirectionalLight::SaveData()
{
	fstream dlfs("./Data/DirectionalLight.txt", ios::app);
	if (!dlfs)
	{
		MessageBoxW(NULL, L"数据加载失败", L"Warning", MB_OK);
		system("pause");
		exit(0);
	}
	
	dlfs << direction.X << ' ' << direction.Y << ' ' << direction.Z << ' ' << intensity << endl;
	dlfs.close();
}

double DirectionalLight::ComputeLighting(vector<Object*> Objects, HitResult hit, Ray ray)
{
	double FinalIntensity = 0;
	Vector3D N = hit.Normal;
	Vector3D L = direction;

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

DirectionalLight::~DirectionalLight()
{

}