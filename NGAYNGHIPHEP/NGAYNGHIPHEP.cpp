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

int m[N];

void Huong() {
//    Tom tat de : N ngay, t du an
//    du an i a[i] -> b[i]
//    moi du an duoc nghi 1 ngay
//    k co du an nao cx dc nghi
//    ??? wtf sao ra 2 dc
//    6 3
//    1 4
//    3 5
//    2 4
//    Nghi ngay 2 ... a roi
//    Danh dau :
//    1 1
//    2 2
//    3 3
//    4 3
//    5 1
    int n, t;
    cin >> n >> t;
    vector<pii> v(t);
    each(x, v) cin >> x.fi >> x.se, m[x.fi]++, m[x.se + 1]--;
    FOR(i, 1, 1e6) m[i] += m[i - 1];
}

int32_t main() {
#define TASKNAME "NGAYNGHIPHEP"
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    int tbegin = clock();
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    Huong(); // hehe
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
