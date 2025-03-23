#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mintime;
    int cities;
    cin >> cities;
    vector<int> traintimes(cities);
    vector<int> bustimes(cities);
    for (int i = 0; i < cities; i++)
    {
        cin >> traintimes[i];
    }
    for (int i = 0; i < cities; i++)
    {
        cin >> bustimes[i];
    }
    int totalTime = 0;
    for (int i = 0; i < cities; i++)
    {
        totalTime += min(traintimes[i], bustimes[i]);
    }
    cout << totalTime << '\n';
}
