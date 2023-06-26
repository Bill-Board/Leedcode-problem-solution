//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using pii= pair<int,int>;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

const int N=200005;
class MedianFinder {
    public:
        ordered_multiset s;
        int sz;
        MedianFinder() {
            sz = 0;
        }

        void addNum(int num) {
            s.insert({num, 0});
            sz++;
        }

        double findMedian() {
            int n = sz;
            if(n % 2 == 1){
                n/=2;
                return (*s.find_by_order(n)).first;
            }
            else{
                n/=2;
                double val1 = (*s.find_by_order(n)).first, val2 = (*s.find_by_order(n-1)).first;
                cout << val1 << ' ' << val2 << '\n';
                return (val1+val2)/2.0;
            }
        }
        void prrr(){
            for(auto i: s)
                cout << i.first << ' ' << i.second << '\n';
            cout << "\n\n";
        }
};

void solve(int tc)
{
    MedianFinder* a = new MedianFinder();
    while(1){
        int t; cin >> t;
        if(t == 1){/// add number
            int x; cin >> x;
            a->addNum(x);
        }
        else if(t==2)
            cout << a->findMedian()<< '\n';
        else
            a->prrr();
    }
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
