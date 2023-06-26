//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii= pair<ll,ll>;

const int N=200005;

ll dp[10002], po[10002], mod = 1e9+7;
ll dp[10002], po[10002], mod = 1e9+7;
ll hashh(string s){
    ll power = 37, n = s.size();
    po[0]=1;
    for(int i = 1; i<=n; i++){
        int val = s[i-1] - 'a' +1;
        dp[i] = (val +  (dp[i-1]*power)%mod) % mod;
        po[i] = (po[i-1] * power)%mod;
    }
    return dp[n];
}
ll get_hash(int l , int r){
    ll ans = (dp[r] - (dp[l-1] * po[r-l+1]) % mod) % mod;
    return (ans + mod) % mod;
}
int strStr(string haystack, string needle) {
    ll kot = hashh(needle);
    hashh(haystack);
    int n = haystack.size(), k = needle.size();
    for(int i = 1; i<=n-k+1; i++){
        if(kot == get_hash(i, i + k - 1))
            return i-1;
    }
    return -1;
}

void solve(int tc)
{
    string s, t; cin >> s >> t;
    cout << strStr(s, t) << '\n';
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
