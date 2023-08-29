#pragma once

#include <iostream>
#include "vec3.h"
#include "ray.h"

// test color (depending on y coordinate of ray dir)
static vec3 color(ray r) {
    float t = r.dir_unit.y();
    t = (t + 1) / 2;  // [-1, 1] -> [0, 1]

    // test color
    vec3 c = (1.0f - t) * vec3(1, 1, 1) + t * vec3(0.5f, 0.7f, 1.0f);

    return c;
}