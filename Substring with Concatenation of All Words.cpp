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
bool alabu(map<ll, int> mpp, int l, int r, int k){
    for(int i = l+k-1; i<=r; i+=k){
        ll kot = get_hash(i - k + 1, i);
        mpp[kot]--;
        if(mpp[kot] < 0) return false;
    }
    return true;
}

vector<int> findSubstring(string s, vector<string>& words) {
    map<ll, int> mpp;
    int n = s.size(), m= words.size(),k = words[0].size();
    int len = m*k;
    for(auto i: words)
        mpp[hashh(i)]++;
    hashh(s);
    vector<int> ans;
    for(int i = 1; i<=n - len + 1; i++)
        if(alabu(mpp, i, i + len - 1, k))
            ans.push_back(i-1);
    return ans;
}

void solve(int tc)
{
    int n; cin >> n;
    string s; cin >> s;
    vector<string> t(n);
    for(auto &i: t) cin >> i;
    vector<int> ans = findSubstring(s, t);
    for(auto i: ans)
        cout << i << ' ';
    cout << '\n';
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
