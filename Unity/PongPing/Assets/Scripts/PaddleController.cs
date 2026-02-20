using UnityEngine;

public class PaddleController : MonoBehaviour
{
    // Public so you can set in Inspector (simple & clear for the assignment)
    public KeyCode UpKey = KeyCode.W;
    public KeyCode DownKey = KeyCode.S;

    public float Speed = 8f;

    // Arena limits (simple: no Unity Vector2 used)
    public float MinY = -4.5f;
    public float MaxY = 4.5f;

    void Update()
    {
        float input = 0f;

        if (Input.GetKey(UpKey)) input += 1f;
        if (Input.GetKey(DownKey)) input -= 1f;

        float dy = input * Speed * Time.deltaTime;

        Vector3 pos = transform.position;
        pos.y = Mathf.Clamp(pos.y + dy, MinY, MaxY);
        transform.position = pos;
    }
}
