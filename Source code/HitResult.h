#ifndef HITRESULT_H
#define HITRESULT_H
#define INF 1e9
#include"Material.h"

class HitResult
{
public:
	bool IsHit;//是否击中
	double Distance;//距离
	Vector3D Normal;//法向量
	Vector3D HitPoint;//击中点
	Material material;//材质

	HitResult();

	HitResult(bool _IsHit, double _Distance, Vector3D _Normal, Vector3D _HitPoint, Material _material);

	~HitResult();
};
#endif
