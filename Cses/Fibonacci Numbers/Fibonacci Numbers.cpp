#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define F first
#define S second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
#define pii pair<int, int>
const int N = 9 + 1e6;
const int md = 1e9 + 7;

pii fib(int n, int md){
    if (n == 0){
        return {0,1};
    }
    auto p = fib(n>>1, md);
    int c = p.F * (2 * p.S - p.F + md) % md;
    int d = (p.F * p.F % md + p.S * p.S % md) % md;
    if (n & 1) return {d,(c + d) % md};
    else return {c,d};
}

void solve(){
    int n; 
    cin >> n;
    cout << fib(n, md).F << '\n';
}    

int32_t main() {
#define TASKNAME ""
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    solve();
    return 0;
}
