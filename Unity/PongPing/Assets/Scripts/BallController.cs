using System.Runtime.InteropServices;
using UnityEngine;
using static VectorMathDLLTest;
using TMPro;

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

    public Transform PaddleLeft;
    public Transform PaddleRight;

    public float PaddleWidth = 0.5f;
    public float PaddleHeight = 2.5f;
    public float BallSize = 0.25f;

    public TextMeshProUGUI ScoreText;
    private int leftScore = 0;
    private int rightScore = 0;

    void Start()
    {
        // Start centered
        position = new Vec2_I(0f, 0f);

        float randomY = Random.Range(-0.5f, 0.5f);
        velocity = Vec2_Normalize(new Vec2_I(1f, randomY));
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
        // paddle collision (super simple AABB check)
        if (PaddleLeft != null && CheckPaddleHit(PaddleLeft))
        {
            velocity = Vec2_Reflect(velocity, new Vec2_I(1f, 0f)); // normal points right
        }

        if (PaddleRight != null && CheckPaddleHit(PaddleRight))
        {
            velocity = Vec2_Reflect(velocity, new Vec2_I(-1f, 0f)); // normal points left
        }
        // score + reset when off-screen (left/right)
        if (position.x > MaxX)
        {
            leftScore++;
            if (ScoreText != null) ScoreText.text = leftScore + " : " + rightScore;

            position = new Vec2_I(0f, 0f);
            velocity = Vec2_Normalize(new Vec2_I(1f, Random.Range(-0.5f, 0.5f)));
        }
        else if (position.x < MinX)
        {
            rightScore++;
            if (ScoreText != null) ScoreText.text = leftScore + " : " + rightScore;

            position = new Vec2_I(0f, 0f);
            velocity = Vec2_Normalize(new Vec2_I(-1f, Random.Range(-0.5f, 0.5f)));
        }

        // Apply to Unity ONLY for rendering (no UnityEngine.Vector2 used)
        transform.position = new Vector3(position.x, position.y, 0f);
    }
    // simple AABB check against a paddle
    bool CheckPaddleHit(Transform paddle)
    {
        float dx = Mathf.Abs(position.x - paddle.position.x);
        float dy = Mathf.Abs(position.y - paddle.position.y);

        return dx < (BallSize + PaddleWidth * 0.5f) &&
               dy < (BallSize + PaddleHeight * 0.5f);
    }
}