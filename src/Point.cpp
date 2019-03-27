#include "Point.h"

// overloaded operators
void Point::operator=(const Point &p)
{
    x = p.x;
    y = p.y;
    z = p.z;
}

Point Point::operator+(const Point &p)
{
    Point ret;
    ret.x = x + p.x;
    ret.y = y + p.y;
    ret.z = z + p.z;
    return ret;
}

Point Point::operator+(float fac)
{
    Point ret;
    ret.x = x + fac;
    ret.y = y + fac;
    ret.z = z + fac;
    return ret;
}

Point &Point::operator+=(const Point &p)
{
    x += p.x;
    y += p.y;
    z += p.z;
    return *this;
}

Point &Point::operator+=(float fac)
{
    x += fac;
    y += fac;
    z += fac;
    return *this;
}

Point Point::operator-(const Point &p)
{
    Point ret;
    ret.x = x - p.x;
    ret.y = y - p.y;
    ret.z = z - p.z;
    return ret;
}

Point Point::operator-(float fac)
{
    Point ret;
    ret.x = x - fac;
    ret.y = y - fac;
    ret.z = z - fac;
    return ret;
}

Point &Point::operator-=(const Point &p)
{
    x -= p.x;
    y -= p.y;
    z -= p.z;
    return *this;
}

Point &Point::operator-=(float fac)
{
    x -= fac;
    y -= fac;
    z -= fac;
    return *this;
}

Point Point::operator*(const Point &p)
{
    Point ret;
    ret.x = x * p.x;
    ret.y = y * p.y;
    ret.z = z * p.z;
    return ret;
}

Point Point::operator*(float fac)
{
    Point ret;
    ret.x = x * fac;
    ret.y = y * fac;
    ret.z = z * fac;
    return ret;
}

Point &Point::operator*=(const Point &p)
{
    x *= p.x;
    y *= p.y;
    z *= p.z;
    return *this;
}

Point &Point::operator*=(float fac)
{
    x *= fac;
    y *= fac;
    z *= fac;
    return *this;
}

Point Point::operator/(const Point &p)
{
    Point ret;
    ret.x = x / p.x;
    ret.y = y / p.y;
    ret.z = z / p.z;
    return ret;
}

Point Point::operator/(float fac)
{
    Point ret;
    ret.x = x / fac;
    ret.y = y / fac;
    ret.z = z / fac;
    return ret;
}

Point &Point::operator/=(const Point &p)
{
    x /= p.x;
    y /= p.y;
    z /= p.z;
    return *this;
}

Point &Point::operator/=(float fac)
{
    x /= fac;
    y /= fac;
    z /= fac;
    return *this;
}

Point Point::operator-()
{
    return Point(-x, -y, -z);
}