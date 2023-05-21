#ifndef HITRESULT_H
#define HITRESULT_H
#define INF 1e9
#include"Material.h"

class HitResult
{
public:
	bool IsHit;//�Ƿ����
	double Distance;//����
	Vector3D Normal;//������
	Vector3D HitPoint;//���е�
	Material material;//����

	HitResult();

	HitResult(bool _IsHit, double _Distance, Vector3D _Normal, Vector3D _HitPoint, Material _material);

	~HitResult();
};
#endif
