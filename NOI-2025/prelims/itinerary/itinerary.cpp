#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef struct city
{
    deque<int> neighbours;
} city;

bool IsItinerary(int startingCityIndex);
void FindPath(int current, int parent);
int cursor;
int cityCount, eventCount;
deque<pair<int,int>> PathIndex;
vector<int> eventIndices;
vector<bool> visitedCities;
vector<city> cities;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> cityCount >> eventCount;
    cities.resize(cityCount);
    visitedCities.resize(cityCount);
    for (int i = 0; i < cityCount - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cities[x].neighbours.push_back(y);
        cities[y].neighbours.push_back(x);
    }
    for (int i = 0; i < eventCount; i++)
    {
        int event;
        cin >> event;
        eventIndices.push_back(event - 1);
    }
    FindPath(4, 4);
    cout << PathIndex.size() << '\n';
    for (int i = 0, len = PathIndex.size(); i < len; i++)
    {
        cout << PathIndex.at(i).first + 1 << ' ' << PathIndex.at(i).second + 1 << '\n';
    }
    for (int i = 0; i < cityCount; i++)
    {
        //cout << "i: " << i << '\n';
        if (IsItinerary(i))
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
    return 0;
}
bool IsItinerary(int startingCityIndex)
{
    cursor = 0;
    PathIndex.clear();
    fill(visitedCities.begin(), visitedCities.end(), false);
    FindPath(startingCityIndex, startingCityIndex);
    /*cout << PathIndex.size() << '\n';
    for (int i = 0, len = PathIndex.size(); i < len; i++)
    {
        cout << PathIndex.at(i).first + 1 << ' ' << PathIndex.at(i).second + 1 << '\n';
    }*/
    for (int i = 0, len = PathIndex.size(); i < len;)
    {
        if (PathIndex[i].second != PathIndex[(i+1)%(eventCount-1)].second)
        {
            for (int j = cursor; j < eventCount; ++j)
            {
                if (PathIndex[i].first == eventIndices[j])
                {
                    ++cursor;
                }
            }
            i++;
        }
        else
        {
            int counter = 0;
            for (int j = cursor; j < eventCount; ++j)
            {
                if (PathIndex[i].first == eventIndices[j])
                {
                    ++counter;
                }
            }
            for (int j = cursor; j < eventCount; ++j)
            {
                if (PathIndex[i+1].first == eventIndices[j])
                {
                    ++counter;
                }
            }
            i += 2;
            cursor += counter;
        }
    }
    return cursor >= (eventCount - 1);
}
void FindPath(int current, int parent)
{
    visitedCities[current] = true;
    for (int neighbour : cities[current].neighbours)
    {
        if (neighbour == parent)
            continue;
        if (!visitedCities[neighbour])
        {
            FindPath(neighbour, current);
        }
    }
    //cout << current + 1 << ' ' << parent + 1 << '\n';
    for (int i : eventIndices)
        if (current == i)
            PathIndex.push_front(pair(current, parent));

}
