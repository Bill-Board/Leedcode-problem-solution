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
void ppp(map<char, int> m){
    cout << "start \n";
    for(auto i: m)
        cout << i.first << ' ' << i.second << '\n';
    cout << '\n';
}


map<char, int> mpp;
int alabu(int len, string &s){
    map<char, int> p = mpp, baki;
    for(int i = 0; i<len; i++){
        if(mpp.count(s[i])){
            if(p.count(s[i])){
                p[s[i]] --;
                if(p[s[i]] == 0)
                    p.erase(s[i]);
            }
            else
                baki[s[i]]++;
        }
        //ppp(p);
    }
    if(p.empty()) return 0;
    int n = s.size();
    for(int i = 0, j = len; j<n; j++, i++){
        if(mpp.count(s[i])){
            if(0 < baki[s[i]]) baki[s[i]] --;
            else p[s[i]]++;
        }
        if(mpp.count(s[j])){
            if(p.count(s[j])){
                p[s[j]] --;
                if(p[s[j]] == 0)
                    p.erase(s[j]);
            }
            else
                baki[s[j]]++;
        }
        if(p.empty()) return i+1;
    }
    return -1;
}
string minWindow(string s, string t) {
    if(s.size() < t.size()) return "";
    for(auto i: t)
        mpp[i]++;
    int l = t.size(), r = s.size(), start = 0, len = 0;
    while(l <= r){
        int m = l + (r - l)/2;
        int ok = alabu(m, s);
        if(ok == -1)
            l = m + 1;
        else{
            r = m - 1;
            len = m;
            start = ok;
        }
    }
    return s.substr(start, len);
}
void solve(int tc)
{
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << '\n';

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
