#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long plates, queries;
    cin >> plates >> queries;
    long totalDelicious = 0;
    vector<long> deliciousValue(plates);

    for (long i = 0; i < plates; i++)
    {
        cin >> deliciousValue[i];
        totalDelicious += deliciousValue[i];
    }
    cout << totalDelicious << '\n';
    totalDelicious = 0;
    for (long i = 0, minDelicious, maxDelicious, newSnack; i < queries; i++, totalDelicious = 0)
    {
        cin >> minDelicious >> maxDelicious >> newSnack;
        for (long j = 0; j < plates; j++)
        {
            if (deliciousValue[j] >= minDelicious && deliciousValue[j] <= maxDelicious)
            {
                deliciousValue[j] = newSnack;
            }
            totalDelicious += deliciousValue[j];
        }
        cout << totalDelicious << '\n';
    }
    return 0;
}
