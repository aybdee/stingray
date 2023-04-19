#ifndef HIT_REC
#define HIT_REC
#include "vec3.h"

typedef struct HitRecord
{
    float t;
    Vec3 p;
    Vec3 normal;
} HitRecord;

#endif