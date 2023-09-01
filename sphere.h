#pragma once

#include "vec3.h"

class sphere {
    public :
    vec3 center;
    float radius;

    sphere();
    sphere(float x, float y, float z, float r);
    sphere(const vec3& pos, float r);

};