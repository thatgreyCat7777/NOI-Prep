#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

typedef struct
{
    // Quality needed
    int quality;
    // happy gained if accepted
    int happy;
} contest_t;
typedef struct
{
    // Problem quality
    int quality;
    // happy loss if rejected
    int happy;

} problem_t;

int totalHappy = 0;
int contestCount, problemCount;
vector<pair<int,int>> Max_Happy; // {quality, happy}
vector<contest_t> contests;
vector<problem_t> problems;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Allocate space for contests and problems
    cin >> contestCount >> problemCount;
    contests.resize(contestCount);
    problems.resize(problemCount);

    // Get data for contest
    for (int i = 0; i < contestCount; ++i)
    {
        cin >> contests[i].quality >> contests[i].happy;
    }
    sort(contests.begin(), contests.end(), [](const contest_t &a, const contest_t &b)
         {
             return a.quality < b.quality;
         });
    // Precompute best happy for quality value
    int maxHappy = 0;
    for (contest_t &a : contests)
    {
        maxHappy = max(maxHappy, a.happy)
        Max_Happy.emplace_back(pair(a.quality, maxHappy))
    }
    // Get data for problems
    for (int i = 0; i < problemCount; ++i)
    {
        cin >> problems[i].quality >> problems[i].happy;
        int maxHappyGained = 0;
        for (int j = 0; j < contestCount; ++j)
        {
            if (problems[i].quality >= contests[j].quality)
                maxHappyGained = max(maxHappyGained, contests[j].happy);
        }
        maxHappyGained -= problems[i].happy;
        if (maxHappyGained > 0)
            totalHappy += maxHappyGained;
    }
    cout << totalHappy;

}

