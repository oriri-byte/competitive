#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    cin >> Q;
    long long B;
    for (int i = 0; i < Q; i++)
    {
        cin >> B;
        auto itr = lower_bound(A.begin(), A.end(), B);
        int idx = distance(A.begin(), itr);
        long long ans;
        if (idx == 0)
        {
            ans = abs(*itr - B);
        }
        else
        {
            ans = min(abs(*itr - B), abs(*(itr - 1) - B));
        }

        cout << ans << endl;
    }
    return 0;
}