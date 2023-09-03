#include "camera.h"


camera::camera()
{
    left_bottom = vec3(-2, -2, -1);
    origin = vec3(0, 0, 0);
    horizontal = vec3(4, 0, 0);
    vertical = vec3(0, 4, 0);
}

ray camera::get_ray(float u, float v)
{
    vec3 p = vec3( left_bottom + (u * horizontal) + (v * vertical) );  // [-2, 2]
    ray r( origin, (p - origin) );

    return r;
}
