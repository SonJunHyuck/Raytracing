#include "ray.h"

ray::ray () { }
ray::ray (const vec3& a, const vec3& b) {
    origin = a;
    dir_unit = b;
    dir_unit.make_unit_vector();
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
vec3 ray::point_at_parameter(float t) {
    return origin + t * dir_unit;
}