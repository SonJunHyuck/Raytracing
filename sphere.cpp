#include "sphere.h"

sphere::sphere() {};

sphere::sphere(float x, float y, float z, float r){
    center = vec3(x, y, z);
    radius = r;
}

sphere::sphere(const vec3& pos, float r) {
    center = pos;
    radius = r;
}


bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
{
    float a = dot(r.dir_unit, r.dir_unit);
    float b = 2.0f * dot(r.dir_unit, r.origin - center);
    float c = dot(r.origin - center, r.origin - center) - pow(radius, 2);

    // root-finder 판별식
    float d = pow(b, 2) - 4 * a * c;

    float positive_t = (-b + sqrt(d)) / (2 * a);
    float negative_t = (-b - sqrt(d)) / (2 * a);

    float t;

    // 충돌 했는가?
    if(d >= 0) 
    {
        // 둘 중 작은 값 선택
        t = negative_t > 0 ? negative_t : positive_t;

        // ray의 범위 내에 있는 오브젝트만 선택
        if(t >= t_min && t <= t_max)
        {
            rec.t = t;
            rec.p = r.shoot_ray(t);
            rec.normal = unit_vector(r.shoot_ray(t) - center);
            return true;
        }
    }
    
    return false;
}