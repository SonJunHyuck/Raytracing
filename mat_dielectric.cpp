#include "mat_dielectric.h"

dielectric::dielectric(float ri) : refraction_index(ri) { }

bool dielectric::scatter(const ray& in_r, const hit_record& rec, vec3& attenuation, ray& out_r) const
{
    attenuation = VEC_ONE;

    vec3 reflected = reflect(in_r, rec);
    vec3 refracted;
    float reflect_prob;

    float cosine = dot(in_r.dir_unit, rec.normal);
    vec3 outward_normal;
    float n1_over_n2;
    
    if(cosine > 0)
    {
        outward_normal = -rec.normal;
        n1_over_n2 = refraction_index;
    }
    else
    {
        outward_normal = rec.normal;
        n1_over_n2 = 1.0f / refraction_index;
        cosine = -cosine;
    }

    if(refract(in_r.dir_unit, outward_normal, n1_over_n2, refracted))
        reflect_prob = schlick(cosine, refraction_index);
    else
        reflect_prob = 1.0f;

    if(random_real() < reflect_prob)
    {
        out_r = ray(rec.p, reflected);
    }
    else
    {
        out_r = ray(rec.p, refracted);
    }

    return true;
}