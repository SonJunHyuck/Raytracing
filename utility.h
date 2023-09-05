#pragma once

#include <iostream>
#include <limits>
#include <random>
#include <time.h>
#include "vec3.h"
#include "ray.h"
#include "hitable.h"
#include "material.h"

#define VEC_ZERO vec3(0, 0, 0)
#define VEC_ONE vec3(1, 1, 1)
#define MAX_RECURSIVE 50


static float random_real();
static vec3 random_in_unit_sphere();
static vec3 color(const ray& r, hitable_obj* world, int depth);

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
        float x = random_real();  // [0, 1]
        float y = random_real();
        float z = random_real();

        p = vec3(x, y, z);
        p = (2.0f * p) - vec3(1, 1, 1);  // [-1, 1]

    }while(p.length() >= 1);

    return p;
}

static vec3 color(const ray& r, hitable_obj* world, int depth)
{
    vec3 col;
    hit_record rec;

    // world is hit_list
    if(world->hit(r, 0.01f, std::numeric_limits<float>::max(), rec))
    {
        ray scattered;
        vec3 attenuation;
        
        if(depth < MAX_RECURSIVE && rec.mat_ptr->scatter(r, rec, attenuation, scattered))
        {
            col = attenuation * color(scattered, world, depth + 1);
        }
        else
        {
            col = VEC_ZERO;
        }
    }
    else {
        float t = 0;
        t = r.dir_unit.y();
        t = (t + 1) * 0.5f;  // [-1, 1] -> [0, 1]
        col = (1.0f - t) * VEC_ONE + t * vec3(0.5f, 0.7f, 1.0f);
    }

    return col;
}