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
    string expression; cin >> expression;
    string s= expression;
    int n = expression.size(), r1 , r2 = n-1;
    vector < int > a, b;
    bool ok = false;
    for(int i =0 ; i < n ; i++){
        if (s[i] == '+')
            ok =true, r1 = i;

        if ( ok and s[i] != '+')
            b.push_back(i);
        else if( s[i] != '+')
            a.push_back(i);
    }

    int cr_h  = INT_MAX;
    for( auto l1 :  a){
        for( auto l2 : b){
            string ek, dui, tin , sar;
            for(int i = 0; i < l1; i++)
                ek += s[i];
            for(int i = l1; i <= r1; i++)
                dui += s[i];
            for(int i = r1 + 1; i < l2; i++)
                tin += s[i];
            for(int i = l2; i <= r2; i++)
                sar += s[i];
            int q =stoi(ek);
            int w =stoi(dui);
            int e =stoi(tin);
            int r =stoi(sar);
            if(!q)q=1;
            if(!w)w=1;
            if(!e)e=1;
            if(!r)r=1;
            cout << q << " " << w << " " <<e<< " " <<r<<endl;
            cr_h = min( cr_h, q*w + e*r);
        }
    }
    cout << cr_h << endl;

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
