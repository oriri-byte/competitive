#include <bits/stdc++.h>
using namespace std;

bool checkDiv(long expected_score, long K, vector<long> &lenOfPeaces)
{
  long cur_peaces = 0;
  long div_point = 0;
  for (int i = 0; i < lenOfPeaces.size(); i++)
  {
    div_point += lenOfPeaces[i];
    if (div_point > expected_score)
    {
      div_point = 0;
      cur_peaces++;
    }
  }
  return cur_peaces >= K + 1;
}

void update_score(pair<long, long> &LH, bool larger)
{
  long center = (LH.second + LH.first) / 2;
  long dist = (LH.second - LH.first) / 2;
  if (larger)
  {
    LH.first = center;
    // return center - dist;
  }
  else
  {
    LH.second = center;
    // return center + dist;
  }
}

int main()
{
  long N, L, K;
  cin >> N >> L >> K;
  vector<long> A;

  for (int i = 0; i < N; i++)
  {
    long a;
    cin >> a;
    A.push_back(a);
  }
  A.push_back(L);

  vector<long> lenOfPeaces;
  long prev = 0;
  for (int i = 0; i < A.size(); i++)
  {
    lenOfPeaces.push_back(A[i] - prev);
    prev = A[i];
    // cout << lenOfPeaces[i] << endl;
  }

  pair<long, long> LH = make_pair(0, L);
  while (LH.second - LH.first > 1)
  {
    long cur_score = (LH.second + LH.first) / 2;
    // printf("L:%ld, R:%ld, center:%ld\n", LH.first, LH.second, cur_score);
    bool canDivide = checkDiv(cur_score, K, lenOfPeaces);
    update_score(LH, canDivide);
  }
  cout << LH.second << endl;
  return 0;
}