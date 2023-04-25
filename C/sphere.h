#ifndef SPHERE_H
#define SPHERE_H
#include "stdbool.h"
#include "vec3.h"
#include "ray.h"
#include "hit_rec.h"

typedef struct Sphere
{
    Vec3 center;
    float radius;
} Sphere;

Sphere sphere_new(Vec3 cen, float r);
bool sphere_hit(Sphere sphere, Ray r, float t_min, float t_max, HitRecord *rec);
Vec3 random_in_unit_sphere();
#endif
