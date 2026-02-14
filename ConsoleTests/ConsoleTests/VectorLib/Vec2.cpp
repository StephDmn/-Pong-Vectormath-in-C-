#include "Vec2.h"
#include <cmath>

// NOTE: Keeping these as simple functions first. We'll add edge-case tweaks after tests if needed.

Vec2::Vec2()
    : x(0.0f), y(0.0f)
{
}

Vec2::Vec2(float x, float y)
    : x(x), y(y)
{
}

Vec2 Vec2::Zero()
{
    return Vec2(0.0f, 0.0f);
}

Vec2 Vec2::Add(const Vec2& a, const Vec2& b)
{
    return Vec2(a.x + b.x, a.y + b.y);
}

Vec2 Vec2::Subtract(const Vec2& a, const Vec2& b)
{
    return Vec2(a.x - b.x, a.y - b.y);
}

Vec2 Vec2::Scale(const Vec2& v, float s)
{
    return Vec2(v.x * s, v.y * s);
}

float Vec2::Dot(const Vec2& a, const Vec2& b)
{
    return a.x * b.x + a.y * b.y;
}

float Vec2::Magnitude() const
{
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::Normalize() const
{
    float mag = Magnitude();

    if (mag == 0.0f)
        return Vec2(0.0f, 0.0f);

    return Vec2(x / mag, y / mag);
}

Vec2 Vec2::VectorReflect(const Vec2& v, const Vec2& n)
{
    float d = Dot(v, n);
    return Subtract(v, Scale(n, 2.0f * d));
} // ADDED: VectorReflect (Pong requirement)

Vec2 Vec2::VectorLerp(const Vec2& a, const Vec2& b, float t)
{
    if (t <= 0.0f) return a;
    if (t >= 1.0f) return b;

    return Add(a, Scale(Subtract(b, a), t));
} // ADDED: VectorLerp (Pong requirement)


