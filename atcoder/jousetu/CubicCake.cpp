#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x, y, z, div, tmp;
    cin >> x >> y >> z;
    tmp = gcd(x, y);
    div = gcd(tmp, z);
    cout << (x / div + y / div + z / div) - 3 << endl;
    return 0;
}