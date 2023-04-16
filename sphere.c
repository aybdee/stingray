#include "sphere.h"
#include "ray.h"
#include "hittable.h"
#include "vec3.h"
#include "stdbool.h"
Sphere sphere(Vec3 cen, float r)
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
        float temp = (-b - sqrt(discriminant)) / (a);
        // check if object is in range
        if (temp < t_max && temp > t_min)
        {
            rec->t = temp;
            rec->p = ray_point_at_parameter(r, rec->t);
            rec->normal = vec_3_div_s(vec_3_add(rec->p, vec_3_neg(sphere.center)), sphere.radius);
            return true;
        };
        temp = (-b + sqrt(discriminant)) / (a);
        if (temp < t_max && temp > t_min)
        {
            rec->t = temp;
            rec->p = ray_point_at_parameter(r, rec->t);
            rec->normal = vec_3_div_s(vec_3_add(rec->p, vec_3_neg(sphere.center)), sphere.radius);
            return true;
        }
    }
    return false;
}