#pragma once
#include "vec3.h"
#include "ray.h"
#include "utility.h"

class camera 
{
    public:
    vec3 origin;            // camera pos
    vec3 left_bottom;       // left bottom of image plane
    vec3 horizontal;        // width of image plane
    vec3 vertical;          // height of image plane

    float lens_radius;

    camera();
    camera(vec3 look_from, vec3 look_at, float fov_y, float aspect, vec3 v_up, float aperture, float focal_dist);

    ray get_ray(float u, float v);
};