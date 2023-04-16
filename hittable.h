#ifndef HITABLE_H
#define HITABLE_H

#include "ray.h"
#include "vec3.h"

typedef struct HitRecord
{
    float t;
    Vec3 p;
    Vec3 normal;
} HitRecord;

#endif
