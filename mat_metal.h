#pragma once

#include "vec3.h"
#include "ray.h"
#include "hitable.h"
#include "material.h"

#include "utility.h"

class metal : public material
{
    public :
    vec3 albedo;        // attenuation value
    float fuzz;

    metal(const vec3& a, float f);

    virtual bool scatter(const ray &in_r, const hit_record &rec, vec3 &attenuation, ray &out_r) const;
};