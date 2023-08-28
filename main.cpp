#include <iostream>
#include "vec3.h"
#include "easyppm.h"

using namespace std;

int canvas_x;
int canvas_y;
int resolution;

int main () {
    canvas_x = 300;  // set canvas
    canvas_y = 300;
    resolution = 100;

    PPM ppm = easyppm_create(canvas_x, canvas_y, IMAGETYPE_PPM);

    for(int y = canvas_y - 1; y >= 0; --y) {  // from bottom
        for(int x = 0; x < canvas_x; ++x) {  // from left
            float r = static_cast<float>(x) / static_cast<float>(canvas_x);  // left-bottom = black
            float g = static_cast<float>(y) / static_cast<float>(canvas_y);  // right-top = yellow
            float b = 0.2f;

            ppmcolor c;
            c.r = static_cast<int>(255.0f * r);  // float -> int (in compile phase)
            c.g = static_cast<int>(255.0f * g);
            c.b = static_cast<int>(255.0f * b);

            easyppm_set(&ppm, x, y, c);
        }
    }

    int total = 0;
    for(int i = 1; i < 11; ++i) {
        if(i % 2 == 1)
            total += i;
    }

    cout << total << endl;

    easyppm_invert_y (&ppm);  // delete flip problem
    easyppm_write (&ppm, "result.ppm");

    return 0;
}