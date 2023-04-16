#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#include "hittable.h"

struct hittable_list
{
    int *hittable[];
};
