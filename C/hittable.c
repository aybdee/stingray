#include "sphere.h"
#include "hittable.h"

Object sphere_object(Sphere sp)
{
    Object object = {
        .type = sphere,
        .data.s = sp};

    return object;
}