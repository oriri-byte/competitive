#include <bits/stdc++.h>
using namespace std;

pair<int, int> directions[] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
  };

int dfs(int h, int w, vector<vector<bool>>&field, vector<vector<bool>>&visited){
  visited[h][w] = true;
  int count = 1;
  for (auto dir : directions) {
    int nH = h + dir.first;
    int nW = w + dir.second;
    if (!visited[nH][nW] && field[nH][nW]){
      count += dfs(nH, nW, field, visited);
    }
  }

  return count; 
}

int main(){
  int H, W;
  cin>>H>>W;
  vector<vector<bool>>field(H + 2, vector<bool>(W + 2, false));
  char tmp;
  int numberOfLake = 0;
  for (int i=1; i<=H; i++){
    for (int j=1; j<=W; j++){
      cin>>tmp;
      if (tmp == '#'){
        field[i][j] = true;
        numberOfLake++;
      }
    }
  }

  vector<vector<bool>>visited(H + 2, vector<bool>(W + 2, false));
  int answer = 0;
  for (int i=1; i<=H; i++){
    for (int j=1; j<=W; j++){
      if (!field[i][j]){
        answer++;
        continue;
      }

      vector<vector<bool>> currentVisited = visited;
      field[i][j] = false;
      for (auto dir : directions){
        int searchH = i + dir.first;
        int searchW = j + dir.second;
        if (!visited[searchH][searchW] && field[searchH][searchW]){
          int lake = dfs(searchH, searchW, field, currentVisited);
          if (lake == numberOfLake - 1)answer++;
        }
      }
      field[i][j] = true;
      //cout<<(dfs(i, j, field, currentVisited))<<endl;
    }
  }
  cout<<answer<<endl;
  return 0;
}