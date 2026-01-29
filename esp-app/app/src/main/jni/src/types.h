#pragma once
#include <cstdint>
#include <cmath>
#include <string>

struct Vec3 {
    float x, y, z;
    
    Vec3() : x(0), y(0), z(0) {}
    Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    
    static Vec3 zero() { return Vec3(0, 0, 0); }
    
    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }
    
    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }
    
    float length() const {
        return std::sqrt(x*x + y*y + z*z);
    }
};

struct Matrix {
    float m[4][4];
    
    Matrix() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                m[i][j] = 0;
    }
};
