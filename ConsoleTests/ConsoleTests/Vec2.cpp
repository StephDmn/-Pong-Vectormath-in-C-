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
// FIX: completed function signature and body

