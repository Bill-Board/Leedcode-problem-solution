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


void solve(int tc)
{
    string s; cin >> s;
    int n = s.size();
    vector<int> o(n+3), z(n+3);
    for(int i = n; 0<i; i--){
        if(s[i]=='1')
        {
            o[i] ++;
            o[i] += o[i+1];
        }
    }
    int m = 0;
    for(int i = 1; i<=n; i++){
        if(s[i]=='0'){
            z[i]++;
            z[i] += z[i-1];
            m = max(m, min(z[i], o[i+1]));
        }
    }
    cout << 2 *m << '\n';
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
