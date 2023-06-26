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
int lengthOfLongestSubstring(string s){
    int l = 0, r = 0, ses =  s.size(), ans = 0;
    map<char, int>mpp;
    while(r!=ses)
    {
        mpp[s[r]]++;
        while(1 < mpp[s[r]] && l<r){
            mpp[s[l]]--;
            l++;
        }
        r++;
        ans=max(ans,(r-l));
        //cout << l << " " << r << '\n';
    }
    return ans;
}

void solve(int tc)
{
    string s; cin >> s;
    cout << lengthOfLongestSubstring(s) << '\n';
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
