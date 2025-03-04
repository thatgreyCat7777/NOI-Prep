#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long cells, ducks;
    cin >> cells >> ducks;
    vector<long> ducksCell(cells);

    for (long i = 0; i < cells; i++)
    {
        cin >> ducksCell[i];
    }
    long totalSteps = 0;
    for (long i = 1, largestCell = 0, cellLocation; i < cells; i = cellLocation + 1, largestCell = 0)
    {
        //cout << i << '\n';
        for (long j = i; j < cells; j++)
        {
            if (largestCell <= ducksCell[j])
            {
                largestCell = ducksCell[j];
                cellLocation = j;
            }
        }
        // Debug message
        //cout << largestCell << ' ' << cellLocation << ' ' << totalSteps << '\n';
        totalSteps += largestCell * (cellLocation + 1 - i);
    }
    cout << totalSteps << '\n';
}
