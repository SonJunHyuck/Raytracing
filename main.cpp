#include <iostream>

#include "vec3.h"
#include "easyppm.h"

#include "utility.h"
#include "ray.h"

using namespace std;

int canvas_x;
int canvas_y;

vec3 left_bottom (-2, -2, -1);
vec3 horizontal (4, 0, 0);
vec3 vertical(0, 4, 0);
vec3 origin (0, 0, 0);

int main () {
    canvas_x = 300;  // set canvas
    canvas_y = 300;

    PPM ppm = easyppm_create(canvas_x, canvas_y, IMAGETYPE_PPM);

    for(int y = canvas_y - 1; y >= 0; --y) {  // from bottom
        for(int x = 0; x < canvas_x; ++x) {  // from left

            float u = static_cast<float>(x) / static_cast<float>(canvas_x);  // [0, 4]
            float v = static_cast<float>(y) / static_cast<float>(canvas_y);  // [0, 4]
            vec3 p = vec3(left_bottom + u * horizontal + v * vertical);  // [-2, 2]

            ray r( origin, (p - origin) );

            vec3 col = color(r);

            ppmcolor c;
            c.r = static_cast<int>(255.0f * col.x());  // float -> int (in compile phase)
            c.g = static_cast<int>(255.0f * col.y());
            c.b = static_cast<int>(255.0f * col.z());

            easyppm_set(&ppm, x, y, c);
        }
    }

    easyppm_invert_y (&ppm);  // delete flip problem
    easyppm_write (&ppm, "result.ppm");

    return 0;
}