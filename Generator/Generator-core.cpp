#include "Generator.h"

float Generator::func() {
    float res = 0;
    switch (type)
    {
        case 1:
            res = a * sin(w * t);
            break;
        case 2:
            for (int i = 1; i < 1001; i++) {
                res += (sin((2 * i - 1) * w * t)) / (2 * i - 1);
            }
            res *= 4 * a / M_PI;
            break;
        case 3:
            for (int i = 1; i < 1001; i++) {
                res += pow(-1, i) * sin(i * w * t) / i;
            }
            res *= a / M_PI;
            break;
        default:
            break;
    }
    return res;
}

void Generator::setf(float p_f) {
    w = 2 * M_PI * p_f;
}
void Generator::setw(float p_w) {
    w = p_w;
}
void Generator::setA(float p_a) {
    a = p_a;
}
void Generator::setType(int p_type) {
    type = p_type;
}
float* Generator::get() {
    return x;
}
float Generator::getAt(float p_t) {
    t = p_t;
    return func();
}