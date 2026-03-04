#include <bits/stdc++.h>
using namespace std;

void dfs(string s, int &N, int left, int right)
{
    if (left + right == N)
    {
        cout << s << endl;
    }
    if (left < N / 2)
    {
        dfs(s + "(", N, left + 1, right);
    }
    if (right < left)
    {
        dfs(s + ")", N, left, right + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    if (N % 2 == 1)
    {
        return 0;
    }
    dfs("", N, 0, 0);
    return 0;
}