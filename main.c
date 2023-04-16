#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "vec3.h"
#include "ray.h"

float hit_sphere(Vec3 center, float radius, Ray r)
{
    Vec3 oc = vec_3_add(r.origin, vec_3_neg(center));
    float a = vec_3_dot(r.direction, r.direction);
    float b = 2.0 * vec_3_dot(oc, r.direction);
    float c = vec_3_dot(oc, oc) - (radius * radius);
    float discriminant = (b * b) - 4 * a * c;
    if (discriminant < 0)
    {
        return -1.0;
    }
    else
    {
        return (b - sqrt(discriminant)) / (2.0 * a);
    }
}

// decide the color of a ray
// Vec3 color(Ray r)
// {
//     float t = hit_sphere(vec_3(0, 0, -1), 0.5, r);
//     if (t > 0.0)
//     {
//         Vec3 N = vec_3_unit(vec_3_add(ray_point_at_parameter(r, t), vec_3_neg(vec_3(0.0, 0.0, -1.0))));
//         return vec_3_mult_s(vec_3(vec_3_x(N) + 1.0, vec_3_y(N) + 1.0, vec_3_z(N) + 1.0), 0.5);
//     }
//     Vec3 unit_direction = vec_3_unit(r.direction);
//     t = 0.5 * (vec_3_y(unit_direction) + 2.0);
//     return vec_3_add(vec_3_mult_s(vec_3(1.0, 1.0, 1.0), (1.0 - t)), vec_3_mult_s(vec_3(0.5, 0.7, 1.0), t));
// }

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

    for (int y = cols - 1; y >= 0; y--)
    {
        for (int x = 0; x < rows; x++)
        {
            float u = (float)(x) / (float)(rows);
            float v = (float)(y) / (float)(cols);
            Vec3 direction = vec_3_add(lower_left_corner, vec_3_add(vec_3_mult_s(horizontal, u), vec_3_mult_s(vertical, v)));
            Ray r = ray(origin, direction);
            Vec3 col = color(r);
            // vec_3_disp(col);
            int ir = (int)(255.9 * col.vec[0]);
            int ig = (int)(255.9 * col.vec[1]);
            int ib = (int)(255.9 * col.vec[2]);
            fprintf(ppm, "%d %d %d\n", ir, ig, ib);
        }
    }
}
