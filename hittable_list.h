#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#include <stdbool.h>
#include "hittable.h"
#include "hit_rec.h"

typedef struct HittableList
{
    int size;
    Object objects[100];
} HittableList;

bool object_hit(Object object, Ray r, float t_min, float t_max, HitRecord *rec);
bool pool_hits(HittableList list, Ray r, float t_min, float t_max, HitRecord *rec);
#endif
