#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Y;
    cin >> N >> Y;
    for (int i = 0; i <= N && 10000 * i <= Y; i++)
    {
        for (int j = 0; i + j <= N && 5000 * j <= Y - 10000 * i; j++)
        {
            if (10000 * i + 5000 * j + 1000 * (N - i - j) == Y)
            {
                printf("%d %d %d", i, j, N - i - j);
                return 0;
            }
        }
    }
    printf("%d %d %d", -1, -1, -1);
    return 0;
}