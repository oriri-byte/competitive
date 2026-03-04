#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> targets = {"erase", "eraser", "dream", "dreamer"};
    string s;
    cin >> s;
    bool isDelete = true;
    while (isDelete && !s.empty())
    {
        isDelete = false;
        for (int i = 0; i < 4; i++)
        {
            int targetLen = targets[i].length();
            if (s.length() < targetLen)
                continue;
            if (s.substr(s.length() - targetLen, targetLen) == targets[i])
            {
                isDelete = true;
                s.erase(s.length() - targetLen, targetLen);
                break;
            }
        }
    }
    if (s.empty())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}