using System.Runtime.InteropServices;
using UnityEngine;
using static VectorMathDLLTest;

// TYPE: MonoBehaviour
public class BallController : MonoBehaviour
{
    // DLL Imports (InteropDLL)
    [DllImport("InteropDLL")]
    private static extern Vec2_I Vec2_Add(Vec2_I a, Vec2_I b);

    [DllImport("InteropDLL")]
    private static extern Vec2_I Vec2_Scale(Vec2_I v, float s);

    [DllImport("InteropDLL")]
    private static extern Vec2_I Vec2_Normalize(Vec2_I v);

    [DllImport("InteropDLL")]
    private static extern Vec2_I Vec2_Reflect(Vec2_I v, Vec2_I n);

    // Ball state (YOUR custom vector)
    private Vec2_I position;
    private Vec2_I velocity;

    [Header("Movement")]
    public float Speed = 5f;
    public float MinX = -9f;
    public float MaxX = 9f;
    public float MinY = -4.5f;
    public float MaxY = 4.5f;

    void Start()
    {
        // Start centered
        position = new Vec2_I(0f, 0f);

        // Initial direction (normalized)
        velocity = Vec2_Normalize(new Vec2_I(1f, 1f));
    }

    void Update()
    {
        // movement = velocity * speed * deltaTime
        Vec2_I movement = Vec2_Scale(velocity, Speed * Time.deltaTime);

        // position += movement
        position = Vec2_Add(position, movement);

        // Bounce top/bottom (stable: clamp + invert)
        if (position.y > MaxY)
        {
            position.y = MaxY;
            velocity.y = -velocity.y;
        }
        else if (position.y < MinY)
        {
            position.y = MinY;
            velocity.y = -velocity.y;
        }
        // Reset when off-screen (left/right)
        if (position.x > MaxX || position.x < MinX)
        {
            position = new Vec2_I(0f, 0f);
            velocity = Vec2_Normalize(new Vec2_I(1f, 1f));
        }

        // Apply to Unity ONLY for rendering (no UnityEngine.Vector2 used)
        transform.position = new Vector3(position.x, position.y, 0f);
    }
}