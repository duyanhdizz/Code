#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

vector<pii> v;
map<int, int> m;

int32_t main() {
#define TASKNAME "THUVIEN"
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    int tbegin = clock();
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        m[x]++;
    }
    each(x, m) v.pb({x.fi, x.se});
    sort(all(v));
    each(x, v) cout << "Dau sach " << x.fi << ": " << x.se << " luot" << '\n';
    cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
5
2 6 2 1 4
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
Dau sach 1: 1 luot
Dau sach 2: 2 luot
Dau sach 4: 1 luot
Dau sach 6: 1 luot
------------------------------    |
==================================+
*/
