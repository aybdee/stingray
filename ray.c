#include "ray.h"
#include "vec3.h"

Ray ray(Vec3 origin, Vec3 direction)
{
    Ray new_ray = {
        .origin = origin,
        .direction = direction};
    return new_ray;
}

Vec3 ray_point_at_parameter(Ray ray, float t)
{
    return vec_3_add(ray.origin, vec_3_mult_s(ray.direction, t));
}