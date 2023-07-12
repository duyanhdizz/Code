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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int get(int a) {
    return (a & 1);
}

void YeuHuong() {
    int a, b, c;
    cin >> a >> b >> c;
    int lo = 31 - __builtin_clz((max({a, b, c}))) + 1;
    bool work = false;
    while(lo--) { // BE YEU DI NGU ROI A
        if(get(a) == get(b) && get(a) != get(c)) {
            work = !work;
        }
        a /= 2;
        b /= 2;
        c /= 2;
    }
    cout << (work ? "NO\n" : "YES\n");
}

int32_t main() {
#define TASKNAME "fc144_xgift"
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    int tbegin = clock();
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    int testcase;
    cin >> testcase;
    while(testcase--)
        YeuHuong();
    cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
