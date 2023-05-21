#ifndef MATERIAL_H
#define MATERIAL_H
#include"Vector3D.h"
#include"Color.h"

class Material
{
public:
	Color color;

	double specular;//反射指数

	double reflective;//反射程度 [0, 1]

	Material(Color _C = { 0, 0, 0 }, double _specular = 0, double _reflective = 0);

	~Material();
};
#endif
