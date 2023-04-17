#ifndef SPHERE_H
#define SPHERE_H
#include "hittable.h"
#include "hittable_list.h"
#include "stdbool.h"
#include "vec3.h"

typedef struct Sphere
{
    Vec3 center;
    float radius;
} Sphere;

Sphere sphere_new(Vec3 cen, float r);

Object sphere_object(Sphere sp);
bool sphere_hit(Sphere sphere, Ray r, float t_min, float t_max, HitRecord *rec);
#endif
