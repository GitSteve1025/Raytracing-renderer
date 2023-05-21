#ifndef OBJECT_H
#define OBJECT_H
#define eps 1e-6
#include"HitResult.h"
#include"Ray.h"
#include<vector>
#include<windows.h>
#include<fstream>
using std::fstream;
using std::vector;
using std::endl;
using std::ios;



class Object
{
public:

	Object();

	virtual void SaveData() = 0;

	virtual HitResult Intersect(Ray ray) = 0;

	friend HitResult Shoot(vector<Object*> Objects, Ray ray);

	~Object();
};
#endif
