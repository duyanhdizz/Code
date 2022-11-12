#include<bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

vector<int> pr;
void Sieve(long long lim = 1e7) {
    #define foru(i, a, b, k) for(ll i = a; i <= b; i+=k)
    #define byte unsigned char
    #define ll long long
    #define all(a) (a).begin(), (a).end()
    #define pb push_back
    
    if (lim < 2) return;
    ll sqrn = sqrt(lim);
    ll sieve_size = max(sqrn, (ll)1 << 15);
    ll segment_size = sieve_size << 4;
    vector<byte> mark(sieve_size);
    vector<bool> isPrime(sqrn + 20, true);
    vector<ll> seg_prime;
    vector<ll> seg_multi;
    ll reset[16];
    ll popcnt[256];
    foru(i, 2, 3, 1) {
        if(isPrime[i]) {
            foru(j, i * i, sqrn, i)isPrime[j] = false;
        }
    }
    foru(i, 5, sqrn, 6) {
        if(isPrime[i]) {
            foru(j, i * i, sqrn, i)isPrime[j] = false;
        }
        int k = i + 2;
        if(isPrime[k]) {
            foru(j, k * k, sqrn, k)isPrime[j] = false;
        }
    }
    foru(i, 0, 7, 1) {
        reset[2 * i] = reset[2 * i | 1] = ~(1 << i);
    }
    foru(i, 0, 256, 1) {
        popcnt[i] = __builtin_popcountll(i);
    }
    ll s = 3, high;
    foru(low, 0, lim, segment_size) {
        fill(all(mark), 0xff);
        high = min(low + segment_size - 1, lim);
        sieve_size = ((high - low) >> 4) + 1;
        for( ; s * s <= high; s += 2) {
            if(isPrime[s]) {
                seg_prime.pb(s);
                seg_multi.pb(s * s - low);
            }
        }

        foru(i, 0, seg_prime.size() - 1, 1) {
            int j = seg_multi[i];
            for(int k = seg_prime[i] * 2; j < segment_size; j += k) {
                mark[j >> 4] &= reset[j & 15];
            }
            seg_multi[i] = j - segment_size;
        }
        if (high == lim) {
            int bits = 0xff << ((lim & 15) + 1) / 2;
            mark[sieve_size - 1] &= ~bits;
        }
        foru(n, 0, sieve_size - 1, 1) {
            foru(i, 0, 7, 1) {
                if(mark[n] & (1 << i)) pr.pb(low + (n << 4) + (i << 1) + 1);
            }
        }
    }
    pr.front() = 2;
}

int32_t main() {
#define TASKNAME "Sieve"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    Sieve(1e7);
    cout << pr[1];
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
