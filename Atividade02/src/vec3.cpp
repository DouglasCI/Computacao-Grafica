#include "../include/vec3.hpp"

vec3::vec3() {
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
}

vec3::vec3(double e0, double e1, double e2) {
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

double vec3::x() const { return e[0]; }
double vec3::y() const { return e[1]; }
double vec3::z() const { return e[2]; }

double vec3::operator[](int i) const { return e[i]; }
double& vec3::operator[](int i) { return e[i]; }

vec3 vec3::operator-() const { return vec3(-e[0], -e[1], -e[2]); }

vec3& vec3::operator+=(const vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vec3& vec3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vec3& vec3::operator/=(double t) { return *this *= 1 / t; }

bool vec3::operator==(const vec3 &v) const {
    double abs_error = 1e-2;
    double diff0 = abs(e[0] - v.e[0]);
    double diff1 = abs(e[1] - v.e[1]);
    double diff2 = abs(e[2] - v.e[2]);

    if(diff0 > abs_error || diff1 > abs_error || diff2 > abs_error)
        return false;

    return true;
}

double vec3::length() const { return sqrt(length_squared()); }

double vec3::length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}