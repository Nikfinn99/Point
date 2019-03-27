#pragma once

#include <Arduino.h>
#include <math.h>
#include <Printable.h>

struct Point : public Printable
{
    // variables
    union {
        struct
        {
            union {
                float x;
                float a1;
            };
            union {
                float y;
                float a2;
            };
            union {
                float z;
                float a3;
            };
        };
        float raw[3];
    };

    // constructors
    Point() : x(0), y(0), z(0){};
    Point(float x, float y, float z) : x(x), y(y), z(z) {}
    Point(const Point &p) : x(p.x), y(p.y), z(p.z) {}

    // implement pritable function
    size_t printTo(Print &p) const
    {
        size_t c = 0;
        c += p.print(x);
        c += p.print(" ");
        c += p.print(y);
        c += p.print(" ");
        c += p.print(z);
        return c;
    }

    // overloaded operators
    void operator=(const Point &p);
    Point operator+(const Point &p);
    Point operator+(float fac);
    Point &operator+=(const Point &p);
    Point &operator+=(float fac);
    Point operator-(const Point &p);
    Point operator-(float fac);
    Point &operator-=(const Point &p);
    Point &operator-=(float fac);
    Point operator*(const Point &p);
    Point operator*(float fac);
    Point &operator*=(const Point &p);
    Point &operator*=(float fac);
    Point operator/(const Point &p);
    Point operator/(float fac);
    Point &operator/=(const Point &p);
    Point &operator/=(float fac);
    Point operator-();
};