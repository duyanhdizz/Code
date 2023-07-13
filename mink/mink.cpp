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

void YeuHuong() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    deque<int> dq;
    each(x, a) cin >> x;
    REP(i, 0, k) {
        while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.pb(i);
    }
    cout << a[dq.front()] << ' ';
    REP(i, k, n) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.pb(i);
        cout << a[dq.front()] << ' ';
    }
    cout << '\n';
}

int32_t main() {
#define TASKNAME "mink"
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