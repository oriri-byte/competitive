# include <bits/stdc++.h>
using namespace std;

vector<pair<long, long>>AB;

int N;
long long S,T;

template <typename T>
void print_array(const vector<T>& arr) {
    
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout<< endl;
}


void dfs_first(int day, int end,long weight, vector<long> &result) {
    if (weight > T)return;
    if (day > end){
        result.push_back(weight);
        return;
    }
    dfs_first(day+1, end, weight - AB[day].first, result);
    dfs_first(day+1, end, weight + AB[day].second, result);
}

void dfs_second(int day, int end,long delta, long delta_max, vector<long> &result) {
    if (day > end){
        result.push_back(delta_max);
        return;
    }
    dfs_second(day + 1, end, delta - AB[day].first, max(delta_max, delta - AB[day].first), result);
    dfs_second(day + 1, end, delta + AB[day].second, max(delta_max, delta + AB[day].second), result);
}



int main(){
    cin>>N>>S>>T;
    for (int i=0; i<N; i++){
        long long A,B;
        cin>>A>>B;
        AB.push_back(make_pair(A, B));
    }

    vector<long>first_weight;
    vector<long>second_weight;
    dfs_first(0, N/2, S, first_weight);
    dfs_second(N/2+1, N-1, 0, 0, second_weight);

    sort(first_weight.begin(), first_weight.end());

    //print_array(first_weight);
    long long ans = 0;
    for (int i=0; i<second_weight.size(); i++){
        auto itr = upper_bound(first_weight.begin(), first_weight.end(), T-second_weight[i]);
        long long dist = distance(first_weight.begin(), itr);
        ans += dist;
    }
    cout<<ans<<endl;

    return 0;
}