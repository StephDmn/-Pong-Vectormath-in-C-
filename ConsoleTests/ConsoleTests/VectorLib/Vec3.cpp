#include "Vec3.h"
#include <cmath>

Vec3::Vec3()
    : x(0.0f), y(0.0f), z(0.0f)
{
}

Vec3::Vec3(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

Vec3 Vec3::Zero()
{
    return Vec3(0.0f, 0.0f, 0.0f);
}

Vec3 Vec3::Add(const Vec3& a, const Vec3& b)
{
    return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vec3 Vec3::Subtract(const Vec3& a, const Vec3& b)
{
    return Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vec3 Vec3::Scale(const Vec3& v, float s)
{
    return Vec3(v.x * s, v.y * s, v.z * s);
}

float Vec3::Magnitude() const
{
    return std::sqrt((x * x) + (y * y) + (z * z));
}

Vec3 Vec3::Normalize() const
{
    float m = Magnitude();
    if (m == 0.0f)
        return Zero();

    return Vec3(x / m, y / m, z / m);
}

float Vec3::Dot(const Vec3& a, const Vec3& b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vec3 Vec3::Cross(const Vec3& a, const Vec3& b)
{
    return Vec3(
        (a.y * b.z) - (a.z * b.y),
        (a.z * b.x) - (a.x * b.z),
        (a.x * b.y) - (a.y * b.x)
    );
}
