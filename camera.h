#pragma once
#include "vec3.h"
#include "ray.h"

class camera 
{
    public:
    vec3 origin;            // camera pos
    vec3 left_bottom;       // left bottom of image plane
    vec3 horizontal;        // width of image plane
    vec3 vertical;          // height of image plane

    camera();
    ray get_ray(float u, float v);
};