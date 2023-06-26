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
long long ok(vector<int> &a, int l, int r){
    if(r < l) return -LLONG_MAX;
    if(r == l) return (long long)a[l];
    vector<int> pos, pre(r - l + 4, 1);
    for(int i = l; i<=r; i++){
        pre[i - l + 1] = pre[i -l] * a[i];
        if(a[i] < 0) pos.push_back(i - l + 1);
    }
    int n = r - l + 1;
    int ans= pre[n];
    if(0 < ans) return ans;
    l = pos.front(), r = pos.back();
    ans = max({ans,pre[r-1], pre[n]/pre[l]});
    return (long long)ans;
}
int maxProduct(vector<int>& nums) {
    vector<int> pos({-1});
    int n = nums.size();
    for(int i = 0; i<n; i++)
        if(nums[i] == 0)pos.push_back(i);
    pos.push_back(n);
    long long ans = -LLONG_MAX;
    if(2<pos.size()) ans=  0;
    n = pos.size();
    cout << ans << '\n';
    for(int i = 0; i<n-1; i++){
        ans = max(ans,ok(nums,pos[i]+1, pos[i+1]-1));
    }
    return ans;
}

void solve(int tc)
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    cout << maxProduct(a)<< '\n';
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
