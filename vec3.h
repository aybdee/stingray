#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdlib.h>

typedef struct vec3
{
    float vec[3];
} Vec3;

Vec3 vec_3(float a, float b, float c);
float vec_3_x(Vec3 vec);
float vec_3_y(Vec3 vec);
float vec_3_z(Vec3 vec);
float vec_3_r(Vec3 vec);
float vec_3_g(Vec3 vec);
float vec_3_b(Vec3 vec);
void vec_3_disp(Vec3 vec);
Vec3 vec_3_neg(Vec3 vec);
float vec_3_length_squared(Vec3 vec);
float vec_3_length(Vec3 vec);
Vec3 vec_3_unit(Vec3 vec);
float vec_3_dot(Vec3 vec, Vec3 vec2);
Vec3 vec_3_cross(Vec3 vec, Vec3 vec2);
Vec3 vec_3_add(Vec3 vec, Vec3 vec2);
Vec3 vec_3_mult(Vec3 vec, Vec3 vec2);
Vec3 vec_3_div_s(Vec3 vec, float f);
Vec3 vec_3_mult_s(Vec3 vec, float f);
Vec3 vec_3_add_s(Vec3 vec, float f);
#endif
