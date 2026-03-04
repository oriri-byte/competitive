#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MAX_V 100001

struct edge
{
    int to;
    int cost;
};

vector<edge> G[MAX_V];

typedef pair<int, int> P;

vector<int> dijkstra(int s)
{
    vector<int> d(MAX_V, INF);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first)
        {
            continue;
        }
        for (auto e : G[v])
        {
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d;
}

int main()
{
    int N, M;
    cin >> N >> M;
    int A, B, C;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        G[A].push_back({B, C});
        G[B].push_back({A, C});
    }
    vector<int> fromStart(MAX_V, INF);
    vector<int> fromGoal(MAX_V, INF);
    fromStart = dijkstra(1);
    fromGoal = dijkstra(N);

    for (int i = 1; i <= N; i++)
    {
        // printf("%d + %d = ", fromStart[i], fromGoal[i]);
        cout << (fromStart[i] + fromGoal[i]) << endl;
    }

    return 0;
}