#include <stdlib.h>
#include "sphere.h"
#include "ray.h"
#include "hittable.h"
#include "vec3.h"
#include "stdbool.h"
#include "hit_rec.h"
#include <stdio.h>
Sphere sphere_new(Vec3 cen, float r)
{
    Sphere new_sphere = {
        .center = cen,
        .radius = r};
    return new_sphere;
}

bool sphere_hit(Sphere sphere, Ray r, float t_min, float t_max, HitRecord *rec)
{
    Vec3 oc = vec_3_add(r.origin, vec_3_neg(sphere.center));
    float a = vec_3_dot(r.direction, r.direction);
    float b = vec_3_dot(oc, r.direction);
    float c = vec_3_dot(oc, oc) - (sphere.radius * sphere.radius);
    float discriminant = (b * b) - (a * c);
    if (discriminant > 0)
    {
        float temp = (b - sqrt(discriminant)) / (a);
        printf("%f", temp);
        // check if object is in range
        // if (temp < t_max && temp > t_min)
        // {
        rec->t = temp;
        rec->p = ray_point_at_parameter(r, rec->t);
        rec->normal = vec_3_div_s(vec_3_add(rec->p, vec_3_neg(sphere.center)), sphere.radius);
        // vec_3_disp(rec->normal);
        return true;
        // };
        // temp = (b + sqrt(discriminant)) / (a);
        // if (temp < t_max && temp > t_min)
        // {
        //     rec->t = temp;
        //     rec->p = ray_point_at_parameter(r, rec->t);
        //     rec->normal = vec_3_div_s(vec_3_add(rec->p, vec_3_neg(sphere.center)), sphere.radius);
        //     return true;
        // }
    }
    return false;
}

Vec3 random_in_unit_sphere()
{
    Vec3 p;
    do
    {
        p = vec_3_mult_s(vec_3_add(vec_3(drand48(), drand48(), drand48()), vec_3_neg(vec_3(1.0, 1.0, 1.0))), 2.0);
    } while (vec_3_length_squared(p) >= 1.0);
    return p;
}