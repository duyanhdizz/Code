#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int STR = 18;
const int INF = 1e9;

string s, t;
int cnt_s[STR], cnt_t[STR];
bool check[STR], notok[STR][STR];

int32_t main() {
#define TASKNAME "EQUSTRQ"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> s >> t;
    // dem so lan xuat hien ki tu tren s, t
    for(int i = 0; i < (int) s.size(); i++) {
        cnt_s[s[i] - 'a']++;
    }
    for(int i = 0; i < (int) t.size(); i++) {
        cnt_t[t[i] - 'a']++;
    }
    //danh dau
    for(int i = 0; i < STR; i++) {
        if(cnt_s[i] != cnt_t[i]) {
            check[i] = true;
        }
    }
    // thu moi TH
    for(int i = 0; i < STR; i++) {
        for(int j = i + 1; j < STR; j++) {
            string p1 = "", p2 = "";
            for(int c = 0; c < (int) s.size(); c++) {
                if(s[c] - 'a' == i || s[c] - 'a' == j) {
                    p1 += s[c];
                }
            }
            for(int c = 0; c < (int) t.size(); c++) {
                if(t[c] - 'a' == i || t[c] - 'a' == j) {
                    p2 += t[c];
                }
            }
            notok[i][j] = !(p1 == p2);
        }
    }
    // q truy van
    int q;
    cin >> q;
    while(q--) {
        string Q;
        cin >> Q;
        bool works = true;
        for(int i = 0; i < (int) Q.size(); i++) {
            if(check[Q[i] - 'a']) {
                works = false;
                break;
            }
        }
        if(works) {
            for(int i = 0; i < (int) Q.size(); i++) {
                for(int j = i + 1; j < (int) Q.size(); j++) {
                    if(notok[Q[i] - 'a'][Q[j] - 'a']) {
                        works = false;
                        break;
                    }
                }
            }
        }
        if(works) cout << 'Y';
        else cout << 'N';
    }
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
aabcd
caabd
4
a
ac
abd
abcd
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
YNYN
------------------------------    |
==================================+
*/
