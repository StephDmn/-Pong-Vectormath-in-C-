using UnityEngine;
using TMPro;

// TYPE: MonoBehaviour
public class ScoreManager : MonoBehaviour
{
    public TextMeshProUGUI ScoreText;

    private int leftScore = 0;
    private int rightScore = 0;

    void Start()
    {
        UpdateUI();
    }

    public void AddLeftScore()
    {
        leftScore++;
        UpdateUI();
    }

    public void AddRightScore()
    {
        rightScore++;
        UpdateUI();
    }

    void UpdateUI()
    {
        ScoreText.text = leftScore + " : " + rightScore;
    }
}