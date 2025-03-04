#include <iostream>

using namespace std;

int main(void)
{
    int total = 0;
    int n,x,y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
    {
        int trips;
        cin >> trips;
        if (x * trips >= y)
        {
            total += y;
        }
        else
        {
            total += x * trips;
        }
    }
    cout << total;
}
