#pragma once

#include <iostream>
#include "vec3.h"
#include "ray.h"
#include "sphere.h"

static vec3 color(ray r);
static float hit_sphere(const sphere& s, const ray& r);

// test color (depending on y coordinate of ray dir)
static vec3 color(ray r) {
    vec3 col;
    sphere s = sphere(vec3(0, 0, -1), 0.5f);
    float t = hit_sphere(s, r);

    // ray와 충돌했는가?
    if (t >= 0)
    {
        vec3 N = unit_vector(r.shoot_ray(t) - s.center);
        col = 0.5f * vec3(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    else {
        t = r.dir_unit.y();
        t = (t + 1) * 0.5f;  // [-1, 1] -> [0, 1]
        col = (1.0f - t) * vec3(1, 1, 1) + t * vec3(0.5f, 0.7f, 1.0f);
    }

    return col;
}

static float hit_sphere(const sphere& s, const ray& r) {
    float a = dot(r.dir_unit, r.dir_unit);
    float b = 2.0f * dot(r.dir_unit, r.origin - s.center);
    float c = dot(r.origin - s.center, r.origin - s.center) - pow(s.radius, 2);

    // root-finder 판별식
    float d = pow(b, 2) - 4 * a * c;

    float positive_t = (-b + sqrt(d)) / (2 * a);
    float negative_t = (-b - sqrt(d)) / (2 * a);

    float t;

    // 충돌 했는가?
    if(d >= 0) {
        // 둘 중 작은 값 선택
        t = negative_t > 0 ? negative_t : positive_t;
    }
    else {
        t = -1.0f;
    }
    
    return t;
}