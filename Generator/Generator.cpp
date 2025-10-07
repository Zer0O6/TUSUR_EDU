#include "Generator.h"

Generator::Generator(float p_a, float p_w, int p_type, float p_t) {
    a = p_a;
    w = p_w;
    type = p_type;
    t = p_t;
    step = 12.5 / w;
    sizeX = (int)(t / step);
    t = 0;
    x = new float[sizeX];
    for (int i = 0; i < sizeX; i++) {
        x[i] = func();
        t += step;
    }
}
Generator::~Generator() {
    delete[] x;
    x = nullptr;
}