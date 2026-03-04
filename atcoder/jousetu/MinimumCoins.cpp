#include <bits/stdc++.h>
using namespace std;

#define MAX 9999

void val_sort(int &a, int &b, int &c)
{
    if (a < b)
        swap(a, b);
    if (a < c)
        swap(a, c);
    if (b < c)
        swap(b, c);
}

int main()
{
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    val_sort(A, B, C);
    int min_coins = 10000;
    for (int i = 0; A * i <= N && i <= MAX; i++)
    {
        for (int j = 0; B * j <= N - A * i && i + j <= MAX; j++)
        {
            if ((N - A * i - B * j) % C == 0)
            {
                min_coins = min(i + j + (N - A * i - B * j) / C, min_coins);
            }
        }
    }
    cout << min_coins << endl;
    return 0;
}