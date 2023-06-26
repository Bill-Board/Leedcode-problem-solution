//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii= pair<int,int>;

const int N=1005;

ll dp[2][1003],pow_[1003], MOD = 1e9+7;

ll gethas_sub(int l, int r, int k){
    ll ans = ((dp[k][r] - dp[k][l-1] * pow_[r-l+1])%MOD + MOD ) %MOD;
    return ans;
}
string longestPalindrome(string s) {
    ll power = 157, n = s.size();
    pow_[0]=1;
    for(int j = 0; j<2; j++){
        for(int i = 1; i<=n; i++){
            ll val = s[i-1] - 'a' + 1;
            dp[j][i] = (val +  dp[j][i-1] * power) % MOD;
            if(j == 0)pow_[i] = (power * pow_[i-1]) % MOD;
        }
        reverse(s.begin(), s.end());
    }
    int l = 0, x, y;
    for(int i = 1; i<=n ; i++){
        for(int j = i; j<=n; j++){
            if(gethas_sub(i, j, 0) == gethas_sub(n - j + 1, n - i + 1, 1) and l < j - i + 1){
                l = j - i + 1;
                x = i, y = j;
            }
        }
    }
    return s.substr(x-1, l);
}

void solve(int tc)
{
    string s; cin >> s;
    cout << longestPalindrome(s) << '\n';
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

