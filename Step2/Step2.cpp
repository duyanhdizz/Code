#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 9 + 1e7;
const int INF = 1e9;

int t;

ll pow(ll a, ll n, ll m) {
    ll result = 1;
    a = a % m;
    while (n > 0) {
        if (n & 1) result = result * a % m;
        n >>= 1;
        a = a * a % m;
    }
    return result;
}

pair<ll, ll> factor(ll n) {
    ll s = 0;
    while ((n & 1) == 0) {
        s++;
        n >>= 1;
    }
    return {s, n};
}

bool witness_test(ll s, ll d, ll n, ll witness) {
    if (n == witness) return true;
    ll p = pow(witness, d, n);
    if (p == 1) return true;
    for (; s > 0; s--) {
        if (p == n-1) return true;
        p = p * p % n;
    }
    return false;
}

bool miller(int n) {
    if (n < 2) return false;
    if ((n & 1) == 0) return n == 2;
    ll s, d;
    tie(s, d) = factor(n-1);
    return witness_test(s, d, n, 2) && witness_test(s, d, n, 3) && witness_test(s, d, n, 5) && witness_test(s, d, n, 7) && witness_test(s, d, n, 11) && witness_test(s, d, n, 13) && witness_test(s, d, n, 17) && witness_test(s, d, n, 19) && witness_test(s, d, n, 23);
}

int32_t main() {
#define TASKNAME "Step2"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> t;
    while(t--) {
       long long n;
       cin >> n;
       long long k = sqrt(n);
       if(k * k == n && miller(k) == true) cout << "YES" << '\n';
       else cout << "NO" << '\n';
	}
    return 0;
}
