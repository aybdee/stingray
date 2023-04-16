#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include <stdbool.h>

typedef struct HittableList
{
    int size;
    Object objects[];
} HittableList;

bool object_hit(Object object, Ray r, float t_min, float t_max, HitRecord *rec);
#endif
