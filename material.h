#pragma once

#include "vec3.h"
#include "ray.h"

struct hit_record;  // 상호 참조를 피하기 위해, include 하지 않고, only 선언

class material
{
    public :
    virtual bool scatter(const ray& in_r, const hit_record& rec, vec3& attenuation, ray& out_r) const = 0;
};