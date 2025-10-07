#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Generator {
private:
    int type;
    float a = 0, w = 0, t = 0, step;
    float* x;
    int sizeX;

    float func();

public:
    Generator(float p_a, float p_w, int p_type, float p_t);
    void setf(float p_f);
    void setw(float p_w);
    void setA(float p_a);
    float* get();
    float getAt(float p_t);
    float getStep();

    ~Generator();
};