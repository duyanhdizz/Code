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

int a[N];

void YeuHuong() {
    int n, k, m;
    cin >> n >> k >> m;
    int solan = m / k;
    int p = m % k;
    // 1 2 3 2 1 2 3
    int n_n = 2 * n - 2;
    int vong = solan / n_n;
    int du = solan % n_n;
    // 1 2 3 4 3 2 1
    // 4 5 6
    // 6 / 5 = 1
    a[1] += vong * k;
    a[n] += vong * k;
    FOR(i, 2, n - 1) a[i] += (vong + 1) * k;
    FOR(i, 1, du) a[i] += k;
    a[du + 1] += p;

    FOR(i, 1, n) cout << a[i] << ' ';
}

int32_t main() {
#define TASKNAME ""
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    int tbegin = clock();
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    YeuHuong();
    cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
2 1 3
---
3 2 7
---
4 5 6
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2 1
---
2 3 2
------------------------------    |
==================================+
*/
