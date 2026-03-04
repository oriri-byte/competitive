#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long tmp = 1;
    for (int i = 0; i < b; i++)
    {
        // cout<<tmp<<endl;
        tmp *= c;
        if (a < tmp)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}