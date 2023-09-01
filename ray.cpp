#include "ray.h"

ray::ray () { }
ray::ray (const vec3& a, const vec3& b) {
    origin = a;
    dir_unit = unit_vector(b);
}

// return origin position
vec3 ray::get_origin() {
    return origin;
}

// return direction vector (!!! normalize !!!) 
vec3 ray::get_direction() {
    return dir_unit;
}


// end point of ray
vec3 ray::shoot_ray(float t) const
{
    return origin + t * dir_unit;
}