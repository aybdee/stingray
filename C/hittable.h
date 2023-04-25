#ifndef HITABLE_H
#define HITABLE_H
#include "ray.h"
#include "vec3.h"
#include "sphere.h"
#include "hit_rec.h"

typedef enum ObjectType
{
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

Object sphere_object(Sphere sp);
#endif
