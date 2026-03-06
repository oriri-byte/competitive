#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q, B;
    cin >> N;
    vector<int> class_rate(N);
    for (int i = 0; i < N; i++)
        cin >> class_rate[i];
    sort(class_rate.begin(), class_rate.end());
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> B;
        auto itr = lower_bound(class_rate.begin(), class_rate.end(), B);
        int idx = distance(class_rate.begin(), itr);
        int ans;
        if (idx == 0)
            ans = abs(B - class_rate[0]);
        else if (idx == N)
            ans = abs(B - class_rate[N - 1]);
        else
            ans = min(abs(*itr - B), abs(*(itr--) - B));
        cout << ans << endl;
    }
    return 0;
}