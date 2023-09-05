#include "mat_lambertian.h"

lambertian::lambertian(const vec3& a) : albedo(a) { }

bool lambertian::scatter(const ray &in_r, const hit_record &rec, vec3 &attenuation, ray &out_r) const
{
    attenuation = albedo;
    vec3 target = rec.p + rec.normal + random_in_unit_sphere();
    out_r = ray(rec.p, target - rec.p);

    return true;  // diffuse -> 무조건 true
}