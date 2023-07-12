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

ll m, k, a, b;

int32_t main() {
#define TASKNAME "fcb044_coins"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> m >> k >> a >> b;
    while(m > 0) {
        if(a > b) b += k;
        else a += k;
        m--;
    }
    cout << abs(a - b);
    return 0;
}
