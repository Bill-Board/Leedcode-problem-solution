//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii= pair<int,int>;

const int N=200005;
ll mod= 1e9+7;
void topKFrequent(vector<int>& nums, int k) {
    int p[10002]={},n[10004]={};
    for(auto i: nums){
        if(i < 0) n[abs(i)]++;
        else p[i]++;
    }
    vector<int> a[100002];
    for(int i = -10000; i<=10000; i++){
        if(i < 0){
            if(n[abs(i)])cout << i << ' ' << n[abs(i)] << '\n';
        }
        else
            if(p[i])cout << i << ' ' << p[i] << '\n';
    }
    for(int i = -10000; i<=10000; i++){
        if(i < 0) a[n[abs(i)]].push_back(i);
        else a[p[i]].push_back(i);
    }
    vector<int> ans;
    for(int i = 100000; 0<i and 0<k; i--){
        for(int j = 0; j<a[i].size() and 0<k; j++, k--){
            ans.push_back(a[i][j]);
        }
    }
    for(auto i: ans) cout << i << ' ';cout << '\n';
}

void solve(int tc)
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    topKFrequent(a, k);
}



signed main()
{
    int test_case=1;
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}



///  Alhamdulillah...
