using System.Runtime.InteropServices;
using UnityEngine;

public class VectorMathDLLTest : MonoBehaviour
{
    [StructLayout(LayoutKind.Sequential)]
    public struct Vec2_I
    {
        public float x;
        public float y;

        public Vec2_I(float x, float y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString() => $"({x}, {y})";
    }

    private const string DLL_NAME = "InteropDLL";

    [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl)]
    private static extern Vec2_I Vec2_Add(Vec2_I a, Vec2_I b);

    private void Start()
    {
        Debug.Log("STARTING");

        var a = new Vec2_I(1f, 2f);
        var b = new Vec2_I(3f, 4f);

        var result = Vec2_Add(a, b);
        Debug.Log($"DLL Vec2_Add {a} + {b} = {result}");
    }
}
