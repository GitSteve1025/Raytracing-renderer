#include"Material.h"

Material::Material(Color _C, double _specular, double _reflective)
{
	color = _C;
	specular = _specular;
	reflective = _reflective;
}

Material::~Material()
{

}