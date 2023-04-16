#ifndef RAY_H
#define RAY_H
#include "vec3.h"

typedef struct Ray
{
    Vec3 origin;
    Vec3 direction;
} Ray;

Ray ray(Vec3 origin, Vec3 direction);
Vec3 ray_point_at_parameter(Ray ray, float t);
#endif