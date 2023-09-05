#pragma once

#include "vec3.h"
#include "ray.h"
#include "hitable.h"
#include "material.h"

#include "utility.h"

// diffuse
class lambertian : public material
{
    public :
    vec3 albedo;        // attenuation value

    lambertian(const vec3& a);

    virtual bool scatter(const ray &in_r, const hit_record &rec, vec3 &attenuation, ray &out_r) const;
};