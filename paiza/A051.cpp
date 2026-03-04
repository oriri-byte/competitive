# include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<int>> S(H+1, vector<int>(W+2, 0));
    vector<vector<int>> scores(H+1, vector<int>(W+2, 0));
    for (int i=1; i<=H; i++){
        for (int j=1; j<=W; j++){
            cin>>S[i][j]; 
            int prev_max = max(scores[i-1][j-1], max(scores[i-1][j], scores[i-1][j+1]));
            scores[i][j] = S[i][j] + prev_max;
        }
    }
    int ans = 0;
    for (int i=1; i<=W; i++){
        ans = max(ans, scores[H][i]);
    }
    cout<<ans;
    return 0;
}