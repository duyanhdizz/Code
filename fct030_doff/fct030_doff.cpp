#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 1 + 1e6;
const int INF = 1e9;

int n;

int32_t main() {
#define TASKNAME "fct030_doff"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n;
    cout << n / 7 * 2 << ' ' << (n - 2) / 7 * 2 + 2;
    return 0;
}
