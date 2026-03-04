#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, H, W;
    cin>>N>>H>>W;
    int sy, sx;
    string s;
    cin>>sy>>sx;
    sy--; sx--;
    cin>>s;
    vector<vector<int>> C(H, vector<int>(W));
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            cin>>C[i][j];
        }
    }

    for (int i=0; i<s.size(); i++){
        if (s[i]=='F'){
            sy--;
            cout<<C[sy][sx]<<endl;
        }else if (s[i] == 'B'){
            sy++;
            cout<<C[sy][sx]<<endl;
        }else if (s[i] == 'R'){
            sx++;
            cout<<C[sy][sx]<<endl;
        }else if (s[i] == 'L'){
            sx--;
            cout<<C[sy][sx]<<endl;
        }
    }

    return 0;
}