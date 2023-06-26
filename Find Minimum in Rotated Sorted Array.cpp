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

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while( l < r){
        //int m = l + (r - l)/2;
        int m = (l + r)/2;
        if (nums[m] > nums[r])
            l = m + 1;
        else
            r = m;
        //cout << l << ' ' << r << ' ' << ans << '\n';
    }
    return nums[l];
}
void solve(int tc)
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    cout << findMin(a) << '\n';
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
