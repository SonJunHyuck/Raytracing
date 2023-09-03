#pragma once
#include "vec3.h"
#include "ray.h"

class camera 
{
    public:
    vec3 origin;
    vec3 left_bottom;
    vec3 horizontal;
    vec3 vertical;

    camera();
    ray get_ray(float u, float v);
};