#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 1 + 1e3;
const int INF = 1e9;

int n, a[N], lo[N], ri[N];

int32_t main() {
#define TASKNAME "fcb044_voice"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] >= a[i - 1]) res++;
        else res = 0;
        lo[i] = res;
    }
    res = 0;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] >= a[i + 1]) res++;
        else res = 0;
        ri[i] = res;
    }
    res = 0;
    for(int i = 0; i < n; i++) res = max(res, 1 + lo[i] + ri[i]);
    cout << res;
    return 0;
}
