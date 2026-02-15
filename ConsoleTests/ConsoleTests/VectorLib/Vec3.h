#pragma once

struct Vec3
{
    float x;
    float y;
    float z;

    Vec3();
    Vec3(float x, float y, float z);

    static Vec3 Zero();

    // G requirements
    static Vec3 Add(const Vec3& a, const Vec3& b);
    static Vec3 Subtract(const Vec3& a, const Vec3& b);
    static Vec3 Scale(const Vec3& v, float s);

    float Magnitude() const;
    Vec3 Normalize() const;

    static float Dot(const Vec3& a, const Vec3& b);
    static Vec3 Cross(const Vec3& a, const Vec3& b);
};

