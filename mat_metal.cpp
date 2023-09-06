#include "mat_metal.h"

metal::metal(const vec3 &a, float f) : albedo(a)
{
    if(f < 1)   fuzz = f;
    else    fuzz = 1;
}

bool metal::scatter(const ray &in_r, const hit_record &rec, vec3 &attenuation, ray &out_r) const
{
    attenuation = albedo;
    vec3 reflected = reflect(in_r, rec);
    reflected += fuzz * random_in_unit_sphere();

    out_r = ray(rec.p, reflected);

    // 반사각이 90도 이하일 때만 반사
    return dot(out_r.dir_unit, rec.normal) > 0;
}