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
int maxArea(vector<int>& height) {
    int n = height.size();
    map<int, set<int> > mpp;

    for(int i = 0; i < n; i++)
        mpp[height[i]].insert(i);

    vector<int>a, mn, mx;
    for(auto i: mpp){
        a.push_back(i.first);
        mn.push_back(*(i.second).begin());
        mx.push_back(*(i.second).rbegin());
    }
    n = a.size();
    vector<int> valmn = mn, valmx = mx;
    for(int i = n-2; 0<=i ; i--){
        mn[i] = min(mn[i] , mn[i+1]);
        mx[i] = max(mx[i] , mx[i+1]);
    }
//    for(int i =0; i<n; i++)
//        cout << valmn[i] << ' ';
//    cout << '\n';
//
//    for(int i =0; i<n; i++)
//        cout << valmx[i] << ' ';
//    cout << '\n';

    int cr_h = 0;
    for(int i = 0; i<n; i++){
        int ans = abs(valmn[i] - valmx[i]) * a[i];
        ans = max(ans, abs(valmx[i] - mn[i]) * a[i]);
        ans = max(ans, abs(valmn[i] - mx[i]) * a[i]);
        ans = max(ans, abs(valmx[i] - mx[i]) * a[i]);
        ans = max(ans, abs(valmn[i] - mn[i]) * a[i]);
        cr_h = max(cr_h, ans);
    }
    return cr_h;

}

void solve(int tc)
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    cout << maxArea(a) << '\n';
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

