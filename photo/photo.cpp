#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int classes, students;
    cin >> classes >> students;
    int heights[classes][students];
    if (classes == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < classes; i++)
    {
        for (int j = 0; j < students; j++)
        {
            cin >> heights[i][j];
        }
    }
    int minheight = 0;
    for (int i = 1; i < classes; i++)
    {
        for (int j = 0; j < students; j++)
        {
            for (int k = 0; k < students; k++)
            {
                if (abs(heights[0][k] - heights[i][j]))
                {

                }

            }
        }
    }
    return 0;
}
