#include <bits/stdc++.h>
using namespace std;

int main()
{

    int T, L, X, Y, Q, E;
    cin >> T >> L >> X >> Y >> Q;
    double bottom, hypotenuse;
    double theta, ferrisWheel_y, ferrisWheel_z;
    for (int i = 0; i < Q; i++)
    {
        cin >> E;
        theta = 2.0 * M_PI * E / T;
        ferrisWheel_y = -L * sin(theta) / 2.0;
        ferrisWheel_z = L / 2.0 - L * cos(theta) / 2.0;
        bottom = pow(pow(X, 2.0) + pow(ferrisWheel_y - Y, 2.0), 0.5);
        hypotenuse = pow(pow(X, 2.0) + pow(ferrisWheel_y - Y, 2.0) + pow(ferrisWheel_z, 2.0), 0.5);
        double ans = acos(bottom / hypotenuse) * 180.0 / M_PI;
        printf("%.12f\n", ans);
    }
    return 0;
}