#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    long dist = 0;
    for (int i = 0; i < N; i++)
    {
        dist += abs(A[i] - B[i]);
    }
    if (dist <= K && (K - dist) % 2 == 0)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
    return 0;
}