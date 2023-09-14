#include "camera.h"


camera::camera()
{
    origin = VEC_ZERO;
    left_bottom = vec3(-2, -2, -1);
    horizontal = vec3(4, 0, 0);
    vertical = vec3(0, 4, 0);
}

camera::camera(vec3 look_from, vec3 look_at, float fov_y, float aspect, vec3 v_up, float aperture, float focal_dist)
{
    float theta = fov_y * M_PI / 180.0f;
    float half_height = tan(theta * 0.5f);
    float half_width = aspect * half_height;
    
    origin = look_from;
    lens_radius = aperture * 0.5f;

    vec3 w = unit_vector(look_at - look_from);  // from -> at
    vec3 u = unit_vector(cross(w, v_up));  // 순서 중요
    vec3 v = unit_vector(cross(u, w));  // 순서 중요

    // image plane
    left_bottom = (origin + focal_dist * w) - (focal_dist * half_width * u) - (focal_dist * half_height * v);
    horizontal = 2.0f * focal_dist * half_width * u;
    vertical = 2.0f * focal_dist * half_height * v;
}

// shoot ray from camera pos to image plane
ray camera::get_ray(float u, float v)
{
    vec3 random = lens_radius * random_in_unit_disk();
    vec3 offset = vec3(random.x() * u, random.y() * v, 0);
    vec3 p = left_bottom + (u * horizontal) + (v * vertical);  // [-2, 2]
    ray r( origin + offset, ( p - (origin + offset) ) );

    return r;
}
