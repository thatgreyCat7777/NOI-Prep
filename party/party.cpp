#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long total = 0;
    long friends;
    cin >> friends;
    long places = ceil((float) friends / 2);
    //cout << places << '\n';
    vector<long> topscores(places);
    for (long i = 0; i < friends; i++)
    {
        long score;
        cin >> score;
        for (long j = places - 1; j >= 0; j--)
        {
            if (topscores[j] < score)
            {
                for (long k = 0; k < j; k++)
                {
                    topscores[k] = topscores[k+1];
                }

                topscores[j] = score;
                break;
            }
        }
    }
    for (long i = 0; i < places; i++)
    {
        //cout << topscores[i] << '\n';
        total += topscores[i];
    }
    cout << total << '\n';
    return 0;
}
