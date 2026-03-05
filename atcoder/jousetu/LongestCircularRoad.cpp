#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> roads;

vector<int> search_farthest(int node)
{
  vector<int> dist(N, -1);
  queue<int> que;
  dist[node] = 0;
  que.push(node);

  while (!que.empty())
  {
    int v = que.front();
    que.pop();
    // cout << "current_node = " << v << endl;
    for (auto nv : roads[v])
    {
      if (dist[nv] != -1)
        continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }
  return dist;
}

int main()
{
  cin >> N;
  roads.resize(N);

  for (int i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    roads[a].push_back(b);
    roads[b].push_back(a);
  }
  vector<int> dist = search_farthest(0);
  int idx = distance(dist.begin(), max_element(dist.begin(), dist.end()));
  vector<int> fin_dist = search_farthest(idx);
  cout << *max_element(fin_dist.begin(), fin_dist.end()) + 1 << endl;
  return 0;
}