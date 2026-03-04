#include <bits/stdc++.h>
using namespace std;

pair<int, int> directions[] = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1}
};

int dfs(vector<vector<int>>& field, int h, int w, int K, vector<vector<bool>>&visited){
  if (K < 0)return 0;
  visited[h][w] = true;
  int maxScore = 0;
  for (auto dir : directions){
    int nextH = h + dir.first;
    int nextW = w + dir.second;
    if (!visited[nextH][nextW]) {
      int score = dfs(field, nextH, nextW, K-1, visited);
      maxScore = max(maxScore, score);
    }
  }
  visited[h][w] = false;
  return field[h][w] + maxScore;
}

int main(){
  int H, W, K;
  cin>>H>>W>>K;
  vector<vector<int>>field(H + 2, vector<int>(W + 2, -1));
  for (int i=1; i<=H; i++){
    for (int j=1; j<=W; j++){
      cin >> field[i][j];
    }
  }

  // 枠を壁で囲む
  vector<vector<bool>>base_visited(H + 2, vector<bool>(W + 2, false));
  for (int j=0; j<W+2; j++) {
    base_visited[0][j] = true;           
    base_visited[H + 1][j] = true;    
  }
  for (int i=0; i<H+2; i++){
    base_visited[i][0] = true;
    base_visited[i][W+1] = true;
  }

  //vector<vector<vector<int>>> currentScore(H + 2, vector<vector<int>>(W + 2, vector<int>(K + 1, -1)));
  int answer = 0;
  vector<vector<int>>coins(H + 2, vector<int>(W + 2, 0));
  for (int i=1; i<=H; i++){
    for (int j=1; j<=W; j++){
      
      vector<vector<bool>> visited = base_visited;
      // coins[i][j] = dfs(field, i, j, K, 0, visited);
      // printf("[%d, %d]\n", i, j);
      int score = dfs(field, i, j, K, visited);
      // printf(" score: %d\n", score);
      answer = max(answer, score);
    }
  }

  cout<< answer <<endl;

  return 0;
}