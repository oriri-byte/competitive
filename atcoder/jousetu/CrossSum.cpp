#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0));
    vector<int> H_sum(H, 0);
    vector<int> W_sum(W, 0);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
            H_sum[i] += A[i][j];
            W_sum[j] += A[i][j];
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << H_sum[i] + W_sum[j] - A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}