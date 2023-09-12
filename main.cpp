#include <iostream>

#include "vec3.h"
#include "easyppm.h"

#include "utility.h"
#include "ray.h"
#include "hitable.h"
#include "hit_list.h"
#include "sphere.h"
#include "mat_lambertian.h"
#include "mat_metal.h"
#include "mat_dielectric.h"

#include "camera.h"

using namespace std;

int resolution_x;
int resolution_y;
int sampling_size;
camera cam;

int main()
{
    srand(time(NULL));

    resolution_x = 300; // set canvas
    resolution_y = 300;
    sampling_size = 100;
    camera cam(vec3(-2, 2, 1), vec3(0, 0, -1), 90.0f,
            static_cast<float>(resolution_x) / static_cast<float>(resolution_y), vec3(0, 1, 0));

    int obj_size = 4;
    hitable_obj *list[obj_size];
    list[0] = new sphere(vec3(0, 0, -1), 0.5f, new lambertian(vec3(0.8f, 0.3f, 0.3f)));
    list[1] = new sphere(vec3(0, -100.5f, -1), 100, new lambertian(vec3(0.8f, 0.8f, 0)));
    list[2] = new sphere(vec3(1, 0, -1), 0.5f, new metal(vec3(0.8f, 0.6f, 0.2f), 0.3f));
    list[3] = new sphere(vec3(-1, 0, -1), 0.5f, new dielectric(2.5f));
    hit_list *world = new hit_list(list, obj_size);

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
                col += color(r, world, 0);
            }

            col /= static_cast<float>(sampling_size);
            col = vec3(sqrt(col.x()), sqrt(col.y()), sqrt(col.z()));  // gamma correction

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