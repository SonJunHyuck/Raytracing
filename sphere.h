#pragma once

#include "vec3.h"
#include "ray.h"
#include "hitable.h"
#include "material.h"

class sphere : public hitable_obj{
    public :
    vec3 center;
    float radius;
    material *mat_ptr;

    sphere();
    sphere(float x, float y, float z, float r);
    sphere(const vec3& pos, float r);
    sphere(const vec3& pos, float r, material *m);


    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;
};