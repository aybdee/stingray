#ifndef SPHERE_H
#define SPHERE_H
#include "hittable.h"
#include "stdbool.h"
#include "vec3.h"

typedef struct Sphere
{
    Vec3 center;
    float radius;
} Sphere;

bool sphere_hit(Sphere sphere, Ray r, float t_min, float t_max, HitRecord *rec);
#endif
