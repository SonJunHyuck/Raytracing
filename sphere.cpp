#include "sphere.h"

sphere::sphere() {};

sphere::sphere(float x, float y, float z, float r){
    center = vec3(x, y, z);
    radius = r;
}

sphere::sphere(const vec3& pos, float r) {
    center = pos;
    radius = r;
}