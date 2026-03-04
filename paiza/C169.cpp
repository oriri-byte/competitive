#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int X;
    cin >> N >> X;
    int ans = 0;
    for (int i=0; i<7; i++){
        ans+=N;
        N = N * X / 100;
    }
    cout << ans;
    
    return 0;
}