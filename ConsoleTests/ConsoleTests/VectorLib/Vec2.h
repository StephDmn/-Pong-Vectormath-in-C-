#pragma once
struct Vec2
{
    float x;
    float y;

    Vec2();
    Vec2(float x, float y);

    static Vec2 Zero();

    // G requirements
    static Vec2 Add(const Vec2& a, const Vec2& b);
    static Vec2 Subtract(const Vec2& a, const Vec2& b);
    static Vec2 Scale(const Vec2& v, float s);

    float Magnitude() const;
    Vec2 Normalize() const;

    static float Dot(const Vec2& a, const Vec2& b);

    // Pong-specific (G)
    static Vec2 VectorReflect(const Vec2& v, const Vec2& n);
    static Vec2 VectorLerp(const Vec2& a, const Vec2& b, float t);
};