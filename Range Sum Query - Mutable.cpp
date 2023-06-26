//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii= pair<ll,ll>;

const int N=900005;
ll mod= 1e9+7;

ll a[N];
template <typename T>
struct st{
    #define lc (n<<1)
    #define rc ((n<<1)+1)

    vector<T> t, lazy;

    st(T n){
        t.resize(4*n, 0);
        lazy.resize(4*n, -1);
    }
    inline void push(int n, int b, int e){
        if (lazy[n] == -1)
            return;
        t[n] = lazy[n];
        if (b != e) {
            lazy[lc] += lazy[n];
            lazy[rc] += lazy[n];
        }
        lazy[n] = -1;
    }

    inline T combine(T a, T b){ // change here
        return a+b;
    }
    inline void pull(int n){ // change here
        t[n]=t[lc]+t[rc];
    }
    void update (int n, int b, int e, int i, int j, T v){
        push(n, b, e);
        if(j<b || i>e) return;
        if(i<=b and j>=e){
            lazy[n]=v; // set lazy
            push(n, b, e);
            return ;
        }
        int mid=(b+e)>>1;
        update(lc, b, mid, i, j, v);
        update(rc, mid+1, e, i, j, v);
        pull(n);
    }

    T query(int n, int b, int e, int i, int j){
        push(n, b, e);
        if(i>e || j<b) return 0; // change gere
        if(i<=b and e<=j) return t[n];
        int mid=(b+e)>>1;
        return combine(query(lc, b,mid, i,j), query(rc, mid+1, e, i, j));
    }
};

void solve(int tc)
{
    int n, m; cin >> n >> m;
    st<ll> s(n);
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        s.update(1, 0, n-1, i, i, x);
    }
    while(m--){
        int t, l , r; cin >> t >> l >> r;
        if( t == 1)
            s.update(1, 0, n-1, l , l, r);
        else
            cout << s.query(1, 0, n-1, l, r-1) << '\n';
    }
}



signed main()
{
    int test_case=1;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}
