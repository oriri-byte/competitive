#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mx = 0;
    int N;
    int ans = 0;
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; i++)
    {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < N; i++)
    {
        if (d[i] > mx)
        {
            ans++;
            mx = d[i];
        }
    }
    cout << ans;
    return 0;
}