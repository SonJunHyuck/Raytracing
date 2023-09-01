#pragma once

#include "vec3.h"
#include "ray.h"

struct hit_record 
{
    float t;        // to select closest hit point
    vec3 p;         // hit point
    vec3 normal;    // normal on hit point
};

// abstract class
class hitable_obj
{
    public :
    virtual bool hit (const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};