#include <utility>
#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<long,long> lower_b(long pos);
bool isVisited(long x);
typedef struct
{
	long position, health;
} monster;

long totalSteps;
deque<long> visited;
vector<monster> monsters;
vector<long> mines;
long monsterCount, mineCount;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	cin >> monsterCount >> mineCount;
	
	monsters.resize(monsterCount);
	mines.resize(mineCount);


	for (long i = 0; i < monsterCount; ++i)
	{
		cin >> monsters[i].position >> monsters[i].health;
	}

// 	sort(monsters.begin(), monsters.end(), [](const monster &a, const monster &b)
// {
// 	return a.position < b.position;
// });

	// Debug message
	// for (monster i : monsters)
	// {
	// 	cout << i.position << '\n';
	// }

	for (long i = 0; i < mineCount; ++i)
	{
		cin >> mines[i];
	}
	sort(mines.begin(), mines.end());
	// for (long i : mines)
	// {
	// 	cout << "mine: " << i << '\n';
	// }
	long monAtMine = 0;
	for (long i = 0; i < monsterCount; ++i)
	{
		// cout << "monster #" << i << " position: " << monsters[i].position << '\n';
		pair<long,long> bounds = lower_b(monsters[i].position);
		
		

		// cout << "iter #" << i << '\n';
		// cout << "a: " << bounds.first << ' ' << "b: " << bounds.second << '\n';
		if (bounds.first == 0)
		{
			bounds.first = bounds.second;
		}
		else if (bounds.second == 0)
		{
			bounds.second = bounds.first;
		}
		long minMineStep = min(abs(bounds.first - monsters[i].position), abs(bounds.second - monsters[i].position));
		
		// cout << "minMineStep: " << minMineStep << '\n';

		if (minMineStep <= 0)
		{
			if (!isVisited(bounds.first))
			{
				visited.push_front(bounds.first);
				++monAtMine;
			}
			else if(!isVisited(bounds.second))
			{
				visited.push_front(bounds.second);
				++monAtMine;
			}
			continue;
		}

		if (minMineStep < monsters[i].health)
		{
			if (abs(bounds.first - monsters[i].position) < abs(bounds.second - monsters[i].position))
			{
				if (!isVisited(bounds.first))
				{
					visited.push_front(bounds.first);
					++monAtMine;
				}
			}
			else
			{
				if (!isVisited(bounds.second))
				{
					visited.push_front(bounds.second);
					++monAtMine;
				}
			}
			totalSteps += minMineStep;
		}
		else
		{
			totalSteps += monsters[i].health;
		}
	}
	// cout << "monAtMine: " << monAtMine << '\n';
	cout << totalSteps+monAtMine << '\n';
	return 0;
}
pair<long,long> lower_b(long pos)
{
	if (pos <= mines[0])
	{
		return pair<long,long>(0, mines[0]);
	}
	for (long i = 1; i < mineCount; ++i)
	{
		if (pos <= mines[i] && pos >= mines[i-1])
		{
			return pair<long,long>(mines[i-1], mines[i]);
		}
	}
	return pair<long,long>(mines[mineCount - 1], 0);
}
bool isVisited(long x)
{
	for (long i : visited)
	{
		if (i == x)
		{
			return true;
		}
	}
	return false;
}