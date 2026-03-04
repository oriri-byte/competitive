#include <bits/stdc++.h>
using namespace std;
struct Plan
{
    int x;
    int y;
    int t;
};

int main()
{
    int N;
    cin >> N;
    vector<Plan> plans(N + 1);
    plans[0].x = 0;
    plans[0].y = 0;
    plans[0].t = 0;

    for (int i = 1; i < N + 1; i++)
    {
        cin >> plans[i].t >> plans[i].x >> plans[i].y;
    }
    for (int i = 1; i < N + 1; i++)
    {
        int dist = abs(plans[i].x - plans[i - 1].x) + abs(plans[i].y - plans[i - 1].y);
        int time = plans[i].t - plans[i - 1].t;
        // printf("dist: %d, time: %d\n", dist, time);

        if (dist > time || (time - dist) % 2 == 1)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}
