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
int ok(vector<int>& a, int t, int l, int r){
    while(l <= r){
        int m = (l + r)/2;
        if(a[m] == t)return m;
        if(a[m] < t)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l < r){
        int m = (l + r)/2;
        if(nums[m] > nums[r])
            l = m + 1;
        else
            r = m;
        cout << l << ' ' << r << '\n';
    }
    cout << l << '\n';
    return max(ok(nums, target, l, nums.size() - 1), ok(nums, target, 0, l - 1));
}

void solve(int tc)
{
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for(auto &i: a)
        cin >> i;
    cout << search(a, t) << '\n';
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
