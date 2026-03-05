#include <bits/stdc++.h>
using namespace std;

void dfs(string s, int left, int right, int &N)
{
    if (left + right == N)
    {
        cout << s << endl;
        return;
    }
    if (left >= right && left < N / 2)
        dfs(s + "(", left + 1, right, N);
    if (left > right)
        dfs(s + ")", left, right + 1, N);
}

int main()
{
    int N;
    cin >> N;
    if (N % 2)
        return 0;
    dfs("", 0, 0, N);
    return 0;
}