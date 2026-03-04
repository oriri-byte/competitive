#include <bits/stdc++.h>
using namespace std;

void update_score(int &high, int &low, int &score, bool beAble)
{
    if (beAble)
    {
        low = score + 1;
        score = low + (high - low) / 2;
    }
    else
    {
        high = score - 1;
        score = low + (high - low) / 2;
    }
}

bool divide_Yokan(int &score, vector<int> &A, int &K, int &N, int &L)
{
    int cut_pos = 0;
    int cnt = 0;
    for (int i = 1; i < N + 1; i++)
    {
        // printf("cut = %d >= %d\n", A[i] - A[cut_pos], score);
        if (A[i] - A[cut_pos] >= score && cnt < K)
        {
            // printf("div-point = %d\n", i);
            cut_pos = i;
            cnt++;
        }
    }
    return (cnt == K) && (L - A[cut_pos] >= score);
}

int main()
{
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> A(N + 1);
    for (int i = 0; i < N; i++)
        cin >> A[i + 1];
    int low = 1;
    int high = L;
    int score = L / 2;
    int cut_pos, cnt;
    int ans = 0;
    while (low <= high)
    {
        cut_pos = 0;
        cnt = 0;
        // printf("score = %d\n", score);
        bool beAble = divide_Yokan(score, A, K, N, L);
        // printf("k=%d\n",k);
        // printf("cnt = %d\n",cnt);
        // printf("last = %d\n", A[N] - A[div]);
        if (beAble)
            ans = max(ans, score);
        update_score(high, low, score, beAble);
        // printf("high = %d, low = %d,score = %d\n", high, low, score);
    }
    cout << ans;

    return 0;
}