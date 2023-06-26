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
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    if(!k) return;
    for(int i = 0; i<__gcd(n, k); i++){
        int val = nums[i];
        for(int j = (i + k)%n; i!=j; j=(j+k)%n)
            swap(val, nums[j]);
        nums[i] = val;
    }
}

void solve(int tc)
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &i: a)
        cin >> i;
    rotate(a, k);
    for(auto i: a)
        cout << i << ' '; cout << '\n';
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
