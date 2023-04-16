#ifndef HITABLE_H
#define HITABLE_H

#include "ray.h"
#include "vec3.h"
#include "sphere.h"

typedef struct HitRecord
{
    float t;
    Vec3 p;
    Vec3 normal;
} HitRecord;

typedef enum ObjectType
{
    invalid_object = 0,
    sphere
} ObjectType;

typedef union ObjectData
{
    Sphere s;
} ObjectData;

typedef struct Object
{
    ObjectType type;
    ObjectData data;
} Object;

#endif
