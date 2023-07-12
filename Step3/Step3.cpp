#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 9 + 1e6;
const int INF = 1e9;

int n;
ll a[N];
map<ll, ll> d;

int32_t main() {
#define TASKNAME "Step3"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], d[a[i]]++;
    sort(a, a + n);
    for(int i = 0; i < n - 1; i++) 
       if(d[a[i] * 2] == 0 && d[a[i] * 3] == 0) return cout << "No", 0;
    cout << "Yes";
    return 0;
}
