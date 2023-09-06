#pragma once

#include "vec3.h"
#include "ray.h"
#include "hitable.h"
#include "material.h"

#include "utility.h"

class dielectric : public material
{
    public:
    float refraction_index;

    dielectric(float ri);

    virtual bool scatter(const ray& in_r, const hit_record& rec, vec3& attenuation, ray& out_r) const;
};