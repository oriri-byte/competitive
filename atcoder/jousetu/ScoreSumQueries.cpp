#include <bits/stdc++.h>
using namespace std;

#define START 1
#define END -1

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> Students(N);
    for (int i = 0; i < N; i++)
    {
        int C, P;
        cin >> C >> P;
        Students[i] = make_pair(C, P);
    }
    int Q;
    cin >> Q;
    vector<int> St_num(N, 0);
    for (int i = 0; i < N; i++)
    {
        int L, R;
        cin >> L >> R;
    }

    cout << ans.first << " " << ans.second;

    return 0;
}