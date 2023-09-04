#pragma once

#include <iostream>
#include <limits>
#include <random>
#include <time.h>
#include "vec3.h"
#include "ray.h"
#include "hitable.h"

static float random_real();
static vec3 random_in_unit_sphere();
static vec3 color(const ray& r, hitable_obj* world);

static float random_real()
{
    return (float)rand() / RAND_MAX;
}

// 1크기의 sphere 안에서 무작위 지점을 반환
static vec3 random_in_unit_sphere()
{
    vec3 p;

    // 1보다 작은 크기의 유닛 벡터 반납
    do
    {
        float x = random_real();
        float y = random_real();
        float z = random_real();

        p = vec3(x, y, z);
        p = (2.0f * p) - vec3(1, 1, 1);  // [-1, 1]

    }while(p.length() >= 1);

    return p;
}

static vec3 color(const ray& r, hitable_obj* world)
{
    vec3 col = vec3(0, 0, 0);
    hit_record rec;
    float t = 0;

    // world is hit_list
    if(world->hit(r, 0.0f, std::numeric_limits<float>::max(), rec))
    {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        ray new_ray = ray(rec.p, target - rec.p);

        // reculsive problem
        col = 0.5f * color(new_ray, world);
    }
    else {
        t = r.dir_unit.y();
        t = (t + 1) * 0.5f;  // [-1, 1] -> [0, 1]
        col = (1.0f - t) * vec3(1, 1, 1) + t * vec3(0.5f, 0.7f, 1.0f);
    }

    return col;
}