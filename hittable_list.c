#include <stdbool.h>
#include "hittable_list.h"
#include "sphere.h"
#include "hittable.h"

bool pool_hits(HittableList list, Ray r, float t_min, float t_max, HitRecord *rec)
{
    HitRecord temp_rec;
    HitRecord *temp_rec_p = &temp_rec;

    bool hit_anything = false;
    double closest_so_far = t_max;
    for (int i = 0; i < list.size; i++)
    {
        if (hit(list.objects[i], r, t_min, t_max, temp_rec_p))
        {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            *rec = temp_rec;
        };
    }
    return hit_anything;
};

bool object_hit(Object object, Ray r, float t_min, float t_max, HitRecord *rec)
{
    switch (object.type)
    {
    case sphere:
        Sphere sph = object.data.s;
        return sphere_hit(sph, r, t_min, t_max, *rec);
    }
}

// HittableList hittable_list_append(HittableList list, Object *object)
// {
//     list.size += 1;
//     Object object_list[list.size];
//     for (int i = 0; i < list.size - 1; i++)
//     {
//         object_list[i] = list.objects[i];
//     }
//     object_list[list.size - 1] = object;

//     HittableList new_list = {
//         .size = list.size,
//         .objects = object_list};
// }