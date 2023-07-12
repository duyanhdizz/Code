#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
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

string subtract(string s , string t) {
    int u = s.size();
    string res = "";
    res.resize(u);

    int h = u - (int)t.size();
    string tem = "";
    FOR(i, 1, h) tem += '0';
    t = tem + t;
    int mem = 0;
    for (int i = u - 1; i >= 0 ; i--) {
        int val = s[i] - t[i] - mem;
        mem = 0;
        while (val < 0) {
            mem++;
            val += 10;

        }

        res[i] = val + 48;

    }
    while (1) {
        int l = res.size();
        if (l == 1 || res[0] > '0') break;
        res.erase(0,1);
    }
    return res;

}

int32_t main() {
#define TASKNAME ""
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    string s, t;
    cin >> s >> t;
    cout << subtract(s, t);
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
