#pragma once

#include <Arduino.h>
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

    /**
     * returns a copy of point that is rotated around z axis by angle
     * does not modify internal variables
     * @param p_angle_deg angle to rotate in degrees
     * @return copy of rotated point
    */
    Point getRotateZ(const float p_angle_deg) const
    {
        float angle_rad = radians(p_angle_deg);
        Point p = *this;
        p.x = x * cosf(angle_rad) - y * sinf(angle_rad);
        p.y = x * sinf(angle_rad) + y * cosf(angle_rad);
        return p;
    }

    /**
     * rotate point around z axis by angle
     * @param p_angle_deg angle to rotate in degrees
    */
    Point &rotateZ(const float p_angle_deg)
    {
        float angle_rad = radians(p_angle_deg);
        x = x * cosf(angle_rad) - y * sinf(angle_rad);
        y = x * sinf(angle_rad) + y * cosf(angle_rad);
        return *this;
    }

    /**
     * get length of vector in x-y plane
    */
    float getLengthXY()
    {
        return sqrt(sq(x) + sq(y));
    }

    /**
     * get length of vector in x-y-z space
    */
    float getLengthXYZ()
    {
        return sqrt(sq(x) + sq(y) + sq(z));
    }

    /**
     * returns copy of normalized vector
     * this only considers x-y plane
    */
    Point getNormalizedXY() const
    {
        Point p = *this;
        float length = p.getLengthXY();
        p.x /= length;
        p.y /= length;
        return p;
    }

    /**
     * returns copy of normalized vector
     * this considers x-y-z space
    */
    Point getNormalizedXYZ() const
    {
        Point p = *this;
        float length = p.getLengthXY();
        p.x /= length;
        p.y /= length;
        p.z /= length;
        return p;
    }

    /**
     * normalize vector in x-y plane
    */
    Point &normalizeXY()
    {
        float length = this->getLengthXY();
        x /= length;
        y /= length;
        return *this;
    }

    /**
     * normalize vector in x-y-z space
    */
    Point &normalizeXYZ()
    {
        float length = this->getLengthXYZ();
        x /= length;
        y /= length;
        z /= length;
        return *this;
    }

    /**
     * returns copy of vector limited to maximum length in x-y plane
    */
    Point getLimitLengthXY(float max_length) const
    {
        Point p = *this;
        if (p.getLengthXY() > max_length)
        {
            p.normalizeXY();
            p.x *= max_length;
            p.y *= max_length;
        }
        return p;
    }

    /**
     * returns copy of vector limited to maximum length in x-y-z space
    */
    Point getLimitLengthXYZ(float max_length) const
    {
        Point p = *this;
        if (p.getLengthXYZ() > max_length)
        {
            p.normalizeXYZ();
            p *= max_length;
        }
        return p;
    }

    /**
     * limits length of vector to max length in x-y plane
    */
    Point &limitLengthXY(float max_length)
    {
        if (this->getLengthXY() > max_length)
        {
            this->normalizeXY();
            x *= max_length;
            y *= max_length;
        }
        return *this;
    }

    /**
     * limits length of vector to max length in x-y-z space
    */
    Point &limitLengthXYZ(float max_length)
    {
        if (this->getLengthXYZ() > max_length)
        {
            this->normalizeXYZ();
            x *= max_length;
            y *= max_length;
            z *= max_length;
        }
        return *this;
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