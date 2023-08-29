#pragma once

#include "vec3.h"

class ray {
public :
ray ();
ray (const vec3& a, const vec3& b);

// return start position
vec3 get_origin();

// return direction vector (!!! normalize !!!) 
vec3 get_direction();

// end point of ray
vec3 shoot_ray(float t);

vec3 origin;  // (point)
vec3 dir_unit;  // (vector)
};