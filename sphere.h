#pragma once

#include "vec3.h"
#include "ray.h"
#include "hitable.h"

class sphere : public hitable_obj{
    public :
    vec3 center;
    float radius;

    sphere();
    sphere(float x, float y, float z, float r);
    sphere(const vec3& pos, float r);

    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;
};