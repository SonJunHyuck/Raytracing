#pragma once

#include <iostream>
#include <limits>
#include "vec3.h"
#include "ray.h"
#include "hitable.h"
#include "sphere.h"

static vec3 color(const ray& r, hitable_obj* world);

static vec3 color(const ray& r, hitable_obj* world)
{
    vec3 col;
    hit_record rec;
    float t;

    // world is hit_list
    if(world->hit(r, 0.0f, std::numeric_limits<float>::max(), rec))
    {
        vec3 N = rec.normal;
        col = 0.5f * vec3(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    else {
        t = r.dir_unit.y();
        t = (t + 1) * 0.5f;  // [-1, 1] -> [0, 1]
        col = (1.0f - t) * vec3(1, 1, 1) + t * vec3(0.5f, 0.7f, 1.0f);
    }

    return col;
}