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

map<char, vector<pair<int, int> > >mpp;
map<pair<int, int>, int> visi;
int n , m;
bool ok(pair<int, int> a, pair<int, int> b){
    int x1 = a.first, x2 = b.first;
    int y1 = a.second, y2 = b.second;
    int val = abs(x1 - x2) + abs(y1 - y2);
    return val==1;
}
bool alabu(string &s, int ind, pair<int, int> p){
    int k = s.size();
    if(k <= ind) return true;
    cout << s[ind] << ' ' << ind << '\n';
    bool ans = false;
    for(auto i: mpp[s[ind]]){
        if(visi[i]==1 or !ok(p, i)) continue;
        visi[i] = 1;
        ans |= alabu(s, ind + 1, i);
        visi[i] = 0;
    }
    return ans;
}

bool exist(vector<vector<char>>& board, string word) {
    n = board.size(); m = board[0].size();
    for(int i = 0; i<n; i++)
        for(int j = 0;j<m; j++)
            mpp[board[i][j]].push_back({i,j});
    bool ans = false;
    map<char, int> k;
    for(auto i: word)
        k[i]++;

    for(auto i: k)
        if(mpp[i.first].size() < i.second)
            return ans;

    for(auto i: mpp[word[0]]){
        visi[i] = 1;
        ans |= alabu(word, 1, i);
        visi[i] = 0;
        if(ans) return ans;
    }
    return ans;
}
void solve(int tc)
{
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for(auto &i: a)
        for(auto &j: i)
            cin >> j;
    string s; cin >> s;
    cout << exist(a, s) << '\n';

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
