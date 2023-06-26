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
    string s; int k;cin >> s >> k;
    while(s.size() > k){
        string ans ;
        int sum = 0;
        for(int i =0; i<s.size() ; i++){
            sum += s[i]-'0';
            if((i+1)%k ==0){
                ans += to_string(sum);
                sum = 0;
            }
        }
        if(s.size() % k)
            ans += to_string(sum);
        s = ans;
        //cout << s << endl;
    }
    return s;
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
