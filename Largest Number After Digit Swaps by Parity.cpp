//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;

void solve()
{
    int num; cin >> num;
    string s = to_string(num);
    string a, b;
    for(int i = 0; i<s.size() ; i++){
        if( (s[i] - '0' ) % 2==0 )
            a+=s[i];
        else
            b+=s[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(auto &i : s){
        if( (i - '0') % 2 ==0)
            i = a.back(), a.pop_back();
        else
            i = b.back(), b.pop_back();
    }
    int ans = stoi(s);
    cout << ans << endl;
}



signed main()
{
    ll test_case=1;
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cin >> test_case;
    while(test_case--)
        solve();
    return 0;
}



///  Alhamdulillah...
