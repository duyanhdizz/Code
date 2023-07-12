#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 1 + 1e2;
const int INF = 1e9;

int n;

int32_t main() {
#define TASKNAME "fct031_posiprod"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n;
    int am = 0, dg = 0, k = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x > 0) dg++;
        else if(x == 0) k++;
        else am++;
    }
    if(k > 0) return cout << -1, 0;
    cout << min(am, dg);
    return 0;
}
