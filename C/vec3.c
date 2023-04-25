#include "vec3.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

Vec3 vec_3(float a, float b, float c)
{
    Vec3 new_vec = {a, b, c};
    return new_vec;
}

float vec_3_x(Vec3 vec)
{

    return vec.vec[0];
}
float vec_3_y(Vec3 vec)
{
    return vec.vec[1];
}

float vec_3_z(Vec3 vec)
{
    return vec.vec[2];
}

float vec_3_r(Vec3 vec)
{
    return vec.vec[0];
}
float vec_3_g(Vec3 vec)
{
    return vec.vec[1];
}

float vec_3_b(Vec3 vec)
{
    return vec.vec[2];
}
Vec3 vec_3_abs(Vec3 vec)
{
    return vec_3(fabsf(vec.vec[0]), fabsf(vec.vec[1]), fabsf(vec.vec[2]));
}

Vec3 vec_3_neg(Vec3 vec)
{
    return vec_3(-vec.vec[0], -vec.vec[1], -vec.vec[2]);
}

float vec_3_length_squared(Vec3 vec)
{
    return (vec.vec[0] * vec.vec[0]) + (vec.vec[1] * vec.vec[1]) + (vec.vec[2] * vec.vec[2]);
}
void vec_3_disp(Vec3 vec)
{
    printf("%f  %f  %f\n", vec.vec[0], vec.vec[1], vec.vec[2]);
}

float vec_3_length(Vec3 vec)
{
    return sqrt(vec_3_length_squared(vec));
}

Vec3 vec_3_unit(Vec3 vec)
{
    float k = 1.0 / vec_3_length(vec);
    vec.vec[0] *= k;
    vec.vec[1] *= k;
    vec.vec[2] *= k;
    return vec;
}

float vec_3_dot(Vec3 vec, Vec3 vec2)
{
    return (vec.vec[0] * vec2.vec[0]) + (vec.vec[1] * vec2.vec[1]) + (vec.vec[2] * vec.vec[2]);
}

Vec3 vec_3_add(Vec3 vec, Vec3 vec2)
{
    return vec_3(vec.vec[0] + vec2.vec[0],
                 vec.vec[1] + vec2.vec[1],
                 vec.vec[2] + vec2.vec[2]);
}

Vec3 vec_3_add_s(Vec3 vec, float f)
{
    return vec_3(vec.vec[0] + f,
                 vec.vec[1] + f,
                 vec.vec[2] + f);
}
Vec3 vec_3_mult(Vec3 vec, Vec3 vec2)
{
    return vec_3(vec.vec[0] * vec2.vec[0],
                 vec.vec[1] * vec2.vec[1],
                 vec.vec[2] * vec2.vec[2]);
}

Vec3 vec_3_div_s(Vec3 vec, float f)
{
    return vec_3(vec.vec[0] / f,
                 vec.vec[1] / f,
                 vec.vec[2] / f);
}

Vec3 vec_3_mult_s(Vec3 vec, float f)
{
    return vec_3(vec.vec[0] * f,
                 vec.vec[1] * f,
                 vec.vec[2] * f);
}

Vec3 vec_3_cross(Vec3 vec, Vec3 vec2)
{
    return vec_3(((vec.vec[1] * vec2.vec[2]) - (vec.vec[2] * vec2.vec[1])),
                 -((vec.vec[0] * vec2.vec[2]) - (vec.vec[2] * vec2.vec[0])),
                 ((vec.vec[0] * vec2.vec[1]) - (vec.vec[1] * vec2.vec[0])));
}