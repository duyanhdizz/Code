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

ll a, b;
vector<pair<int, ll>> v;

void tim() {
    bool r = false;
    if(abs(a) < abs(b)) swap(a, b), r = true;
    ll res = -(a / b);
    a = a + res * b;
    if(r == true) swap(a, b), v.pb({2, res});
    else v.pb({1, res});
}

int32_t main() {
#define TASKNAME "numbcard"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> a >> b;
    while(a != 0 && b != 0) tim();
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++) cout << v[i].fi << ' ' << v[i].se << '\n';
    return 0;
}

/*
-3 9
-27 57
56 15
*/
