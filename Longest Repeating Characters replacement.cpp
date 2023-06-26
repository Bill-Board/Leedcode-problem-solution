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

int alabu(char c, string &s, int k){
    int l = 0, r = 0, n = s.size(), cnt  = 0, ans = 0;
    while(r < n){
        cnt += (s[r++] != c);
        while(k < cnt){
            cnt -= (s[l++] != c);
        }
        ans = max(ans, r - l);
    }
    return ans;
}

int characterReplacement(string s, int k) {
    int n = s.size();
    int ans = 0;
    for(char i = 'A'; i<='Z'; i++)
        ans = max(ans, alabu(i, s, k));
    return ans;
}
void solve(int tc)
{
    string s; int k;
    cin >> s >> k;
    cout << characterReplacement(s, k) << '\n';

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
