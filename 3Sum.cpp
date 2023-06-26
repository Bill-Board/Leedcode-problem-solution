//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii= pair<ll,ll>;

const int N=200005;
ll mod= 1e9+7;
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int> > s;
    int n = nums.size();
    for(int i = 0; i<n-2; i++){
        int j = i + 1, k = n - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                vector<int> p({nums[i], nums[j++], nums[k--]});
                sort(p.begin(), p.end());
                s.insert(p);
            }
            else if(sum < 0) j++;
            else k--;
        }
    }
    vector<vector<int>> ans;
    for(auto i: s)
        ans.push_back(i);
    return ans;
}

void solve(int tc)
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    vector<vector<int> > ans = threeSum(a);
    for(auto i: ans){
        for(auto j: i) cout << j << ' ';
        cout << '\n';
    }
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
