#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(int node, int parent, vector<vector<int>> &roads)
{
    pair<int, int> ret = {0, node};
    for (int &e : roads[node])
    {
        if (e == parent)
            continue;
        pair<int, int> tmp = dfs(e, node, roads);
        tmp.first++;
        ret = max(ret, tmp);
    }
    return move(ret);
}
int main()
{
    int N;
    int A, B;
    cin >> N;
    vector<vector<int>> roads(N + 1);
    vector<int> depth(N + 1, -1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B;
        roads[A].push_back(B);
        roads[B].push_back(A);
    }
    pair<int, int> start = dfs(1, 0, roads);
    pair<int, int> diameter = dfs(start.second, 0, roads);
    cout << diameter.first + 1;

    return 0;
}