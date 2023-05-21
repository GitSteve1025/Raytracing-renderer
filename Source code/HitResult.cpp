#include"HitResult.h"

HitResult::HitResult()
{
	IsHit = false;
	Distance = INF;
}

HitResult::HitResult(bool _IsHit, double _Distance, Vector3D _Normal, Vector3D _HitPoint, Material _material)
{
	IsHit = _IsHit;
	Normal = _Normal;
	material = _material;
	HitPoint = _HitPoint;
	Distance = _Distance;
}

HitResult::~HitResult()
{

}