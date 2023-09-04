#include "sphere.h"

sphere::sphere() {};

sphere::sphere(float x, float y, float z, float r)
{
    center = vec3(x, y, z);
    radius = r;
}

sphere::sphere(const vec3& pos, float r)
{
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
    float t = 0;

    // 충돌 했는가?
    if(d >= 0) 
    {
        float positive_t = (-b + sqrt(d)) / (2 * a);
        float negative_t = (-b - sqrt(d)) / (2 * a);

        // 둘 중 작은 값 선택
        // negative_t > 0 ? negative_t : positive_t; 했다가, bad access 에러나서 한동한 고생
        // 애초에 성립 안되는 식이긴 함
        // negative_t > 0 이어야 한다는 착각 (t의 양수, 음수 여부는 그저 방향성과 관련돼 있을 뿐이라 제약을 주면 안됨)
        t = negative_t < positive_t ? negative_t : positive_t;

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