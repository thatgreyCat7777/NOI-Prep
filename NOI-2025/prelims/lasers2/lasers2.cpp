#include <iostream>

using namespace std;

typedef struct wall
{
    int a;
    int b;
    int cost;
    int length;
} wall;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int rows, columns, budget;
    cin >> rows >> columns >> budget;
    int highestCost = 0, highestLength = 0;
    vector<wall> walls(rows);
    for (int i = 0; i < rows; i++)
    {
        cin >> walls[i].a >> walls[i].b >> walls[i].cost;
        walls[i].length = walls[i].b - walls[i].a + 1;
        if (highestCost < walls[i].cost)
        {
            highestCost = walls[i].cost;
        }
        if (highestLength > walls[i].length)
        {
            highestLength = walls[i].length;
        }
    }
    for (int i = 0; i < rows; i++)
    {

    }
    // Max lasers that can go through
    // when unlocking one wall, figure out how many lasers will be able to go through
    return 0;
}
