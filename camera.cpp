#include "camera.h"


camera::camera()
{
    origin = vec3(0, 0, 0);
    left_bottom = vec3(-2, -2, -1);
    horizontal = vec3(4, 0, 0);
    vertical = vec3(0, 4, 0);
}

// shoot ray from camera pos to image plane
ray camera::get_ray(float u, float v)
{
    vec3 p = vec3( left_bottom + (u * horizontal) + (v * vertical) );  // [-2, 2]
    ray r( origin, (p - origin) );

    return r;
}
