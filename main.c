#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include "vec3.h"
#include "ray.h"
#include "hittable.h"
#include "sphere.h"

float hit_sphere(Sphere sph, Ray r)
{
    Vec3 oc = vec_3_add(r.origin, vec_3_neg(sph.center));
    float a = vec_3_dot(r.direction, r.direction);
    float b = vec_3_dot(oc, r.direction);
    float c = vec_3_dot(oc, oc) - (sph.radius * sph.radius);
    float discriminant = (b * b) - (a * c);
    if (discriminant < 0)
    {
        return -11.0;
    }
    else
    {
        return (b - sqrt(discriminant)) / (a);
    }
}

Vec3 color(Ray r, Object objects[], int num_objects)
{
    for (int i = 0; i < num_objects; i++)
    {
        switch (objects[i].type)
        {
        case (sphere):
        {
            Sphere sph = objects[i].data.s;
            Vec3 oc = vec_3_add(r.origin, vec_3_neg(sph.center));
            float a = vec_3_dot(r.direction, r.direction);
            float b = vec_3_dot(oc, r.direction);
            float c = vec_3_dot(oc, oc) - (sph.radius * sph.radius);
            float discriminant = (b * b) - (a * c);
            if (discriminant > 0.0 && discriminant < FLT_MAX)
            {
                float t = (b - sqrt(discriminant)) / (a);
                if (t > 0.0)
                {
                    Vec3 N = vec_3_unit(vec_3_add(ray_point_at_parameter(r, t), vec_3_neg(objects[i].data.s.center)));
                    // vec_3_disp(N);
                    return vec_3_mult_s(vec_3_add_s(N, 1.0), 0.5);
                }
                else
                {

                    float t = (b + sqrt(discriminant)) / (a);
                    if (t > 0.0 && discriminant < FLT_MAX)
                    {
                        Vec3 N = vec_3_unit((vec_3_add(ray_point_at_parameter(r, t), vec_3_neg(objects[i].data.s.center))));
                        // vec_3_disp(N);
                        return vec_3_mult_s(vec_3_add_s(N, 1.0), 0.5);
                    }
                }
            }
        }
        }
    }
    Vec3 unit_direction = vec_3_unit(r.direction);
    float t = 0.5 * (vec_3_y(unit_direction) + 1.0);
    return vec_3_add(vec_3_mult_s(vec_3(1.0, 1.0, 1.0), (1.0 - t)), vec_3_mult_s(vec_3(0.5, 0.7, 1.0), t));
}

// decide the color of a ray

int main()
{
    // Vec3 new_vec = vec_3(1.0, 1.0, 1.0);
    // vec_3_disp(vec_3_unit(new_vec));
    int rows = 200;
    int cols = 100;
    FILE *ppm;

    ppm = fopen("canvas.ppm", "w");
    fprintf(ppm, "P3\n");
    fprintf(ppm, "%d %d\n", rows, cols);
    fprintf(ppm, "225\n");
    Vec3 lower_left_corner = vec_3(-2.0, -1.0, -1.0);
    Vec3 horizontal = vec_3(4.0, 0.0, 0.0);
    Vec3 vertical = vec_3(0.0, 2.0, 0.0);
    Vec3 origin = vec_3(0.0, 0.0, 0.0);
    Object objects[2] = {

        sphere_object(sphere_new(vec_3(0.0, 0.0, -1.0), 0.5)),
        sphere_object(sphere_new(vec_3(0.0, -100.5, -1.0), 100.0))

    };

    for (int y = cols - 1; y >= 0; y--)
    {
        for (int x = 0; x < rows; x++)
        {
            float u = (float)(x) / (float)(rows);
            float v = (float)(y) / (float)(cols);
            Vec3 direction = vec_3_add(lower_left_corner, vec_3_add(vec_3_mult_s(horizontal, u), vec_3_mult_s(vertical, v)));
            Ray r = ray(origin, direction);
            Vec3 p = ray_point_at_parameter(r, 2.0);
            // Vec3 col = color(r, world);
            Vec3 col = color(r, objects, 2);
            int ir = (int)(255.9 * col.vec[0]);
            int ig = (int)(255.9 * col.vec[1]);
            int ib = (int)(255.9 * col.vec[2]);
            fprintf(ppm, "%d %d %d\n", ir, ig, ib);
        }
    }
}
