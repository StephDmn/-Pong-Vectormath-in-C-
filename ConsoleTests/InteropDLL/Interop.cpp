#include "Interop.h"

// Include your real library headers (from VectorLib)
#include "..\\ConsoleTests\\VectorLib\\Vec2.h"
#include "..\\ConsoleTests\\VectorLib\\Vec3.h"

// --- Helpers: convert between interop POD and your C++ structs ---
static Vec2 ToVec2(const Vec2_I& v) { return Vec2(v.x, v.y); }
static Vec2_I ToVec2I(const Vec2& v) { return Vec2_I{ v.x, v.y }; }

static Vec3 ToVec3(const Vec3_I& v) { return Vec3(v.x, v.y, v.z); }
static Vec3_I ToVec3I(const Vec3& v) { return Vec3_I{ v.x, v.y, v.z }; }

extern "C"
{
    // --- Vec2 ---
    Vec2_I Vec2_Add(Vec2_I a, Vec2_I b) { return ToVec2I(Vec2::Add(ToVec2(a), ToVec2(b))); }
    Vec2_I Vec2_Sub(Vec2_I a, Vec2_I b) { return ToVec2I(Vec2::Subtract(ToVec2(a), ToVec2(b))); }
    Vec2_I Vec2_Scale(Vec2_I v, float s) { return ToVec2I(Vec2::Scale(ToVec2(v), s)); }

    float Vec2_Dot(Vec2_I a, Vec2_I b) { return Vec2::Dot(ToVec2(a), ToVec2(b)); }
    float Vec2_Magnitude(Vec2_I v) { return ToVec2(v).Magnitude(); }      // if yours is static, change it
    Vec2_I Vec2_Normalize(Vec2_I v) { return ToVec2I(ToVec2(v).Normalize()); } // if yours is static, change it

    Vec2_I Vec2_Reflect(Vec2_I v, Vec2_I n) { return ToVec2I(Vec2::VectorReflect(ToVec2(v), ToVec2(n))); }
    Vec2_I Vec2_Lerp(Vec2_I a, Vec2_I b, float t) { return ToVec2I(Vec2::VectorLerp(ToVec2(a), ToVec2(b), t)); }

    // --- Vec3 ---
    Vec3_I Vec3_Add(Vec3_I a, Vec3_I b) { return ToVec3I(Vec3::Add(ToVec3(a), ToVec3(b))); }
    Vec3_I Vec3_Sub(Vec3_I a, Vec3_I b) { return ToVec3I(Vec3::Subtract(ToVec3(a), ToVec3(b))); }
    Vec3_I Vec3_Scale(Vec3_I v, float s) { return ToVec3I(Vec3::Scale(ToVec3(v), s)); }

    float Vec3_Dot(Vec3_I a, Vec3_I b) { return Vec3::Dot(ToVec3(a), ToVec3(b)); }
    float Vec3_Magnitude(Vec3_I v) { return ToVec3(v).Magnitude(); }          // if yours is static, change it
    Vec3_I Vec3_Normalize(Vec3_I v) { return ToVec3I(ToVec3(v).Normalize()); } // if yours is static, change it
    Vec3_I Vec3_Cross(Vec3_I a, Vec3_I b) { return ToVec3I(Vec3::Cross(ToVec3(a), ToVec3(b))); }
}
