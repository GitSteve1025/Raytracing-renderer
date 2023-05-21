#include"AmbientLight.h"

AmbientLight::AmbientLight(double _intensity)
{
	type = "Ambient";
	intensity = _intensity;
}

void AmbientLight::SaveData()
{
    fstream alfs("./Data/AmbientLight.txt", ios::app);
    if (!alfs)
    {
        MessageBoxW(NULL, L" ˝æ›º”‘ÿ ß∞‹", L"Warning", MB_OK);
        system("pause");
        exit(0);
    }

    alfs << intensity << endl;
    alfs.close();
}

double AmbientLight::ComputeLighting(vector<Object*> Objects, HitResult hit, Ray ray)
{
	return intensity;
}

AmbientLight::~AmbientLight()
{

}