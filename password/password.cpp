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

string s;

int32_t main() {
#define TASKNAME ""
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> s;
    if (s.size() < 8) return cout << "NO", 0;
    bool r1 = true, r2 = true, r3 = true, r4 = true;
    string ss = "!@#$%^&*()-+";
    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z') r1 = false;
        if ('A' <= s[i] && s[i] <= 'Z') r2 = false;
        if ('0' <= s[i] && s[i] <= '9') r3 = false;
        if (i > 0 && s[i] == s[i - 1]) {
            cout << "NO";
            return 0;
        }
        for (int j = 0; j <= ss.size(); j ++) {
            if (s[i] == ss[j]) {
                r4 = false;
            }
        }
    }
    if (r1 || r2 || r3 || r4) return cout << "NO", 0;
    cout << "YES";
    return 0;
}
