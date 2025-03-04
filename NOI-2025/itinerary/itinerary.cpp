#include <iostream>
#include <vector>

using namespace std;

class city
{
public:
    bool hasEvent = false;
    vector<int> paths;
    city(bool hasEvent)
    {
        this->hasEvent = false;
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cityCount, eventCount;
    cin >> cityCount >> eventCount;
    vector<int> eventIndices(eventCount);
    vector<city> cities(cityCount);

    for (int i = 0; i < cityCount - 1; i++)
    {
        int path;
        cin >> cities[i] >> path;
        cities[i].paths.push_back(path);
    }
    for (int i = 0; i < eventCount; i++)
    {
        cin >> eventIndices[i];
    }
    // for each starting city
    int previous;
    for (int i = 0; i < cityCount; i++)
    {
        for (int j = 0; j < cities[i].paths.capacity(); j++)
        {
            for (int k = cities[i].paths[j];; k = cities[k].paths[j])
            {

            }
        }
    }
    return 0;
}
