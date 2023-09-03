#include <iostream>

#include "vec3.h"
#include "easyppm.h"

#include "utility.h"
#include "ray.h"
#include "hitable.h"
#include "hit_list.h"
#include "sphere.h"
#include "camera.h"

using namespace std;

int resolution_x;
int resolution_y;
int sampling_size;
camera cam;

int main()
{
    resolution_x = 300; // set canvas
    resolution_y = 300;
    sampling_size = 100;
    cam = camera();

    hitable_obj *list[2];
    list[0] = new sphere(vec3(0, 0, -1), 0.5f);
    list[1] = new sphere(vec3(0, -100.5f, -1), 100);
    hit_list *world = new hit_list(list, 2);

    PPM ppm = easyppm_create(resolution_x, resolution_y, IMAGETYPE_PPM);

    for (int y = resolution_y - 1; y >= 0; --y)
    {
        for (int x = 0; x < resolution_x; ++x)
        {
            vec3 col = vec3(0, 0, 0);
            for (int s = 0; s < sampling_size; ++s)
            {
                float u = static_cast<float>(x + random_real()) / static_cast<float>(resolution_x);
                float v = static_cast<float>(y + random_real()) / static_cast<float>(resolution_y);

                ray r = cam.get_ray(u, v);
                col += color(r, world);
            }

            col /= static_cast<float>(sampling_size);

            ppmcolor c;
            c.r = static_cast<int>(255.0f * col.x()); // float -> int (in compile phase)
            c.g = static_cast<int>(255.0f * col.y());
            c.b = static_cast<int>(255.0f * col.z());

            easyppm_set(&ppm, x, y, c);
        }
    }

    easyppm_invert_y(&ppm); // delete flip problem
    easyppm_write(&ppm, "result.ppm");

    return 0;
}