#include <bits/stdc++.h>
using namespace std;

map<char, int> letter = {
    {'a', 0},
    {'t', 1},
    {'c', 2},
    {'o', 3},
    {'d', 4},
    {'e', 5},
    {'r', 6},
};

const long long M = 1000000000 + 7;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    S = "." + S;
    vector<vector<long long>> cases(N + 1, vector<long long>(7, 0));
    // cout<<S<<endl;
    for (int i = 1; i < N + 1; i++)
    {
        char l = S[i];

        for (int j = 0; j < 7; j++)
        {
            cases[i][j] += cases[i - 1][j];
        }
        if (!letter.count(l))
        {
            continue;
        }
        if (l == 'a')
        {
            cases[i][letter[l]]++;
            continue;
        }
        cases[i][letter[l]] = (cases[i][letter[l]] + cases[i - 1][letter[l] - 1]) % M;
    }
    cout << cases[N][6];

    return 0;
}