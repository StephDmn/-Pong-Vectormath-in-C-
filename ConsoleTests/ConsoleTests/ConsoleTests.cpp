#include <iostream>
#include <cmath>

#include "Vec2.h"
#include "Vec3.h"

bool FloatEquals(float a, float b, float epsilon = 0.0001f)
{
    return std::fabs(a - b) < epsilon;
}

void PrintResult(const std::string& testName, bool result, int& passed, int& failed)
{
    if (result)
    {
        ++passed;
        std::cout << "[PASS] " << testName << "\n";
    }
    else
    {
        ++failed;
        std::cout << "[FAIL] " << testName << "\n";
    }
}

int passed = 0;
int failed = 0;

int main()
{
    std::cout << "=== Vec2 Tests ===\n\n";

    // Vec2 Add
    {
        Vec2 a(1.0f, 2.0f);
        Vec2 b(3.0f, 4.0f);
        Vec2 result = Vec2::Add(a, b);

        bool pass = FloatEquals(result.x, 4.0f) &&
            FloatEquals(result.y, 6.0f);

        PrintResult("Vec2 Add", pass, passed, failed);
    }

    // Vec2 Subtract
    {
        Vec2 a(5.0f, 4.0f);
        Vec2 b(2.0f, 1.0f);
        Vec2 result = Vec2::Subtract(a, b);

        bool pass = FloatEquals(result.x, 3.0f) &&
            FloatEquals(result.y, 3.0f);

        PrintResult("Vec2 Subtract", pass, passed, failed);
    }

    // Vec2 Dot
    {
        Vec2 a(1.0f, 2.0f);
        Vec2 b(3.0f, 4.0f);
        float result = Vec2::Dot(a, b);

        bool pass = FloatEquals(result, 11.0f);
        PrintResult("Vec2 Dot", pass, passed, failed);
    }

    // Vec2 Magnitude
    {
        Vec2 v(3.0f, 4.0f);
        float result = v.Magnitude();

        bool pass = FloatEquals(result, 5.0f);
        PrintResult("Vec2 Magnitude", pass, passed, failed);
    }
    
    // Vec2 Magnitude (Edge Case: Zero Vector)
    {
        Vec2 v(0.0f, 0.0f);
        float result = v.Magnitude();

        bool pass = FloatEquals(result, 0.0f);
        PrintResult("Vec2 Edge: Magnitude Zero Vector", pass, passed, failed);
    }

    // Vec2 Normalize
    {
        Vec2 v(3.0f, 4.0f);
        Vec2 n = v.Normalize();

        bool pass = FloatEquals(n.x, 0.6f) && FloatEquals(n.y, 0.8f);
        PrintResult("Vec2 Normalize", pass, passed, failed);
    }

    // Vec2 Normalize (Edge Case: Zero Vector)
    {
        Vec2 v(0.0f, 0.0f);
        Vec2 n = v.Normalize();

        bool notNaN = (n.x == n.x) && (n.y == n.y);
        bool isZero = FloatEquals(n.x, 0.0f) && FloatEquals(n.y, 0.0f);

        PrintResult("Vec2 Edge: Normalize Zero Vector", notNaN && isZero, passed, failed);
    }


    std::cout << "\n=== Vec3 Tests ===\n\n";

    // Vec2 VectorReflect
    {
        Vec2 v(0.0f, -1.0f);  // moving down
        Vec2 n(0.0f, 1.0f);  // upward normal

        Vec2 result = Vec2::VectorReflect(v, n);

        bool pass = FloatEquals(result.x, 0.0f) &&
            FloatEquals(result.y, 1.0f);

        PrintResult("Vec2 VectorReflect", pass, passed, failed);
    }

    // Vec2 VectorLerp
    {
        Vec2 a(0.0f, 0.0f);
        Vec2 b(10.0f, 20.0f);

        Vec2 r0 = Vec2::VectorLerp(a, b, 0.0f);
        Vec2 rHalf = Vec2::VectorLerp(a, b, 0.5f);
        Vec2 r1 = Vec2::VectorLerp(a, b, 1.0f);

        bool pass = FloatEquals(r0.x, 0.0f) && FloatEquals(r0.y, 0.0f) &&
            FloatEquals(rHalf.x, 5.0f) && FloatEquals(rHalf.y, 10.0f) &&
            FloatEquals(r1.x, 10.0f) && FloatEquals(r1.y, 20.0f);

        PrintResult("Vec2 VectorLerp", pass, passed, failed);
    }


    // Vec3 Add
    {
        Vec3 a(1.0f, 2.0f, 3.0f);
        Vec3 b(4.0f, 5.0f, 6.0f);
        Vec3 result = Vec3::Add(a, b);

        bool pass = FloatEquals(result.x, 5.0f) &&
            FloatEquals(result.y, 7.0f) &&
            FloatEquals(result.z, 9.0f);

        PrintResult("Vec3 Add", pass, passed, failed);
    }

    // Vec3 Subtract
    {
        Vec3 a(5.0f, 4.0f, 3.0f);
        Vec3 b(2.0f, 1.0f, 1.0f);
        Vec3 result = Vec3::Subtract(a, b);

        bool pass = FloatEquals(result.x, 3.0f) &&
            FloatEquals(result.y, 3.0f) &&
            FloatEquals(result.z, 2.0f);

        PrintResult("Vec3 Subtract", pass, passed, failed);
    }

    // Vec3 Scale
    {
        Vec3 v(1.0f, 2.0f, 3.0f);
        Vec3 result = Vec3::Scale(v, 2.0f);

        bool pass = FloatEquals(result.x, 2.0f) &&
            FloatEquals(result.y, 4.0f) &&
            FloatEquals(result.z, 6.0f);

        PrintResult("Vec3 Scale", pass, passed, failed);
    }

    // Vec3 Dot
    {
        Vec3 a(1.0f, 2.0f, 3.0f);
        Vec3 b(4.0f, 5.0f, 6.0f);
        float result = Vec3::Dot(a, b);

        bool pass = FloatEquals(result, 32.0f);
        PrintResult("Vec3 Dot", pass, passed, failed);
    }

    // Vec3 Magnitude
    {
        Vec3 v(2.0f, 3.0f, 6.0f);
        float result = v.Magnitude();

        bool pass = FloatEquals(result, 7.0f);
        PrintResult("Vec3 Magnitude", pass, passed, failed);
    }

    // Vec3 Normalize
    {
        Vec3 v(0.0f, 3.0f, 4.0f);
        Vec3 n = v.Normalize();

        bool pass = FloatEquals(n.x, 0.0f) &&
            FloatEquals(n.y, 0.6f) &&
            FloatEquals(n.z, 0.8f);

        PrintResult("Vec3 Normalize", pass, passed, failed);
    }

    // Vec3 Normalize (Edge Case: Zero Vector)
    {
        Vec3 v(0.0f, 0.0f, 0.0f);
        Vec3 n = v.Normalize();

        bool notNaN = (n.x == n.x) && (n.y == n.y) && (n.z == n.z);
        bool isZero = FloatEquals(n.x, 0.0f) &&
            FloatEquals(n.y, 0.0f) &&
            FloatEquals(n.z, 0.0f);

        PrintResult("Vec3 Edge: Normalize Zero Vector", notNaN && isZero, passed, failed);
    }

    // Vec3 Cross
    {
        Vec3 a(1.0f, 0.0f, 0.0f);
        Vec3 b(0.0f, 1.0f, 0.0f);
        Vec3 result = Vec3::Cross(a, b);

        bool pass = FloatEquals(result.x, 0.0f) &&
            FloatEquals(result.y, 0.0f) &&
            FloatEquals(result.z, 1.0f);

        PrintResult("Vec3 Cross", pass, passed, failed);
    }

    // Vec3 Cross (Edge Case: Parallel Vectors -> Zero Vector)
    {
        Vec3 a(2.0f, 0.0f, 0.0f);
        Vec3 b(5.0f, 0.0f, 0.0f);

        Vec3 result = Vec3::Cross(a, b);

        bool pass = FloatEquals(result.x, 0.0f) &&
            FloatEquals(result.y, 0.0f) &&
            FloatEquals(result.z, 0.0f);

        PrintResult("Vec3 Edge: Cross Parallel Vectors", pass, passed, failed);
    }

    std::cout << "\n=== Summary ===\n";
    std::cout << "Passed: " << passed << "\n";
    std::cout << "Failed: " << failed << "\n";
    std::cout << "Total : " << (passed + failed) << "\n";

    return 0;
}
