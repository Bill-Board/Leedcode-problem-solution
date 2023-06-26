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

int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};
int n, m;

int dfs(int indx, int indy,int parx, int pary, vector<vector<int>>& a, vector<vector<int>> &val){
    int &ans = val[indx][indy];
    if(ans!=-1) return ans;
    ans = 0;
    for(int i = 0; i<4; i++){
        int x = indx + fx[i], y = indy + fy[i];
        if(x == parx and y==pary)continue;
        if(0<=x and 0<=y and x<n and y<m and a[indx][indy]>=a[x][y]){
            ans = max(ans, dfs(x, y,indx, indy, a, val));
        }
    }
    return 0;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
    n = heights.size(); m = heights[0].size();
    vector<vector<int>> visi(n, vector<int> (m)), val1(n, vector<int> (m, -1)), val2(n, vector<int> (m, -1));
    for(int i = 0; i<n; i++)
        val1[i][0] = 1;
    for(int i = 0; i<m; i++)
        val1[0][i] = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            dfs(i, j,-1, -1, heights, val1);
        }
    }
    for(int i = 0; i<n; i++)
        val2[i][m-1] = 1;
    for(int i = 0; i<m; i++)
        val2[n-1][i] = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            dfs(i, j,-1,-1, heights, val2);
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << val1[i][j] << " \n"[j==m-1];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << val2[i][j] << " \n"[j==m-1];
        }
    }

    vector<vector<int>> ans;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(val1[i][j] and val2[i][j])
                ans.push_back({i,j});
        }
    }
    for(auto i: ans){
        for(auto j: i)
            cout << j << ' ';
        cout << '\n';
    }
    return ans;
}

void solve(int tc)
{
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(auto &i: a)
        for(auto &j: i)
            cin >> j;
    pacificAtlantic(a);
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
