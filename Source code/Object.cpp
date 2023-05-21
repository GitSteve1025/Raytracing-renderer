#include"Object.h"

Object::Object()
{

}

HitResult Shoot(vector<Object*> Objects, Ray ray)
{
	HitResult res, tep;
	res.Distance = INF;
	for (auto& p : Objects)
	{
		tep = p->Intersect(ray);
		if (tep.IsHit && tep.Distance < res.Distance)
		{
			res = tep;
		}
	}
	return res;
}

Object::~Object()
{

}
