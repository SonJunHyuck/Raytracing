#pragma once

#include "ray.h"
#include "hitable.h"

class hit_list : public hitable_obj
{
    public :
    hit_list();
    hit_list(hitable_obj** l, int n);

    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;

    hitable_obj** hit_obj_list;
    int list_size;
};