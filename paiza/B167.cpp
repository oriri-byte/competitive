#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    string S;
    vector<vector<char>>R(N + 2,vector<char>(N + 2, '0'));
    for (int i=1; i<N+1; i++){
        cin>>S;
        for (int j=0; j<N; j++){
            R[i][j+1] = S[j];
        }
    }

    bool left,right,upper,lower;
    for (int i=1; i<N+1; i++){
        for (int j=1; j<N+1; j++){
            if (R[i][j] != '7'){
                cout<<R[i][j];
                continue;
            }
            if (R[i][j-1] == '1' || R[i][j-1] == '3' || R[i][j-1] == '4')left = true;
            else left =false;
            if (R[i][j+1] == '1' || R[i][j+1] == '5' || R[i][j+1] == '6')right = true;
            else right = false;
            if (R[i-1][j] == '2' || R[i-1][j] == '4' || R[i-1][j] == '5')upper = true;
            else upper = false;
            if (R[i+1][j] == '2' || R[i+1][j] == '3' || R[i+1][j] == '6')lower = true;
            else lower = false;

            if (left && right)cout<<'1';
            else if (upper && lower)cout<<'2';
            else if (upper && right)cout<<'3';
            else if (lower && right)cout<<'4';
            else if (left && lower)cout<<'5';
            else if (left && upper)cout<<'6';
        }
        cout<<endl;
    }
    
    return 0;
}