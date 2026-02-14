#pragma once
// Interop.h — C ABI exports for Unity (DllImport)
// NOTE (devlog): We export a C ABI to avoid C++ name mangling and ensure predictable layout.

#if defined(_WIN32)
#define VEC_API __declspec(dllexport)
#else
#define VEC_API
#endif

extern "C" {

    // Interop-safe structs (POD). Must match C# layout (Sequential).
    struct Vec2_I
    {
        float x;
        float y;
    };

    struct Vec3_I
    {
        float x;
        float y;
        float z;
    };

    // --- Vec2 ---
    VEC_API Vec2_I Vec2_Add(Vec2_I a, Vec2_I b);
    VEC_API Vec2_I Vec2_Sub(Vec2_I a, Vec2_I b);
    VEC_API Vec2_I Vec2_Scale(Vec2_I v, float s);
    VEC_API float  Vec2_Dot(Vec2_I a, Vec2_I b);
    VEC_API float  Vec2_Magnitude(Vec2_I v);
    VEC_API Vec2_I Vec2_Normalize(Vec2_I v);

    // Pong-specific (Vec2)
    VEC_API Vec2_I Vec2_Reflect(Vec2_I v, Vec2_I n);
    VEC_API Vec2_I Vec2_Lerp(Vec2_I a, Vec2_I b, float t);

    // --- Vec3 ---
    VEC_API Vec3_I Vec3_Add(Vec3_I a, Vec3_I b);
    VEC_API Vec3_I Vec3_Sub(Vec3_I a, Vec3_I b);
    VEC_API Vec3_I Vec3_Scale(Vec3_I v, float s);
    VEC_API float  Vec3_Dot(Vec3_I a, Vec3_I b);
    VEC_API float  Vec3_Magnitude(Vec3_I v);
    VEC_API Vec3_I Vec3_Normalize(Vec3_I v);
    VEC_API Vec3_I Vec3_Cross(Vec3_I a, Vec3_I b);
}