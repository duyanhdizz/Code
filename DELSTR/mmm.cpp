#pragma GCC optimize("Ofast")
#pragma GCC target("sse4")

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define int128 __int128_t
#define double long double
#define gcd __gcd
#define lcm(a, b) ((a)/gcd(a, b)*(b))
#define sqrt sqrtl
#define log2 log2l
#define log10 log10l
#define yes cout << "YES"
#define no cout << "NO"
#define trav(i, a) for (auto &i: (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)a.size()
#define Max(a) *max_element(all(a))
#define Min(a) *min_element(all(a))
#define Find(a, n) (find(all(a), n) - a.begin())
#define Count(a, n) count(all(a), n)
#define Upper(a, n) (upper_bound(all(a), n) - a.begin())
#define Lower(a, n) (lower_bound(all(a), n) - a.begin())
#define next_perm(a) next_permutation(all(a))
#define prev_perm(a) prev_permutation(all(a))
#define sorted(a) is_sorted(all(a))
#define sum(a) accumulate(all(a), 0)
#define sumll(a) accumulate(all(a), 0ll)
#define Sort(a) sort(all(a))
#define Reverse(a) reverse(all(a))
#define Unique(a) Sort(a); (a).resize(unique(all(a)) - a.begin())
#define pb push_back
#define eb emplace_back
#define open(s) freopen(s, "r", stdin)
#define write(s) freopen(s, "w", stdout)
#define fileopen(s) open((string(s) + ".inp").c_str()), write((string(s) + ".out").c_str());
#define For(i, a, b) for (auto i = (a); i < (b); i++)
#define Fore(i, a, b) for (auto i = (a); i >= (b); i--)
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ret(s) return void(cout << s);

const int mod = 1e9 + 7, mod2 = 998244353;
const double PI = acos(-1);
const ull npos = string::npos;
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<double> vdo;
typedef vector<string> vs;
typedef vector<pii> vpair;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef priority_queue<int> pq;
typedef priority_queue<int, vi, greater<int>> pqg;
typedef priority_queue<ll> pqll;
typedef priority_queue<ll, vll, greater<ll>> pqgll;

ll power(ll a, ll b, int m){ll x = 1;a%=m;while (b) {if (b & 1) x = x*a % m;a = a*a % m;b>>=1;}return x;}
ll power(ll a, ll b){ll x = 1;while (b) {if (b & 1) x = x*a;a = a*a;b>>=1;}return x;}
ll ceil(ll a, ll b){return (a + b - 1)/b;}
ll to_int(const string &s){ll x = 0; for (int i = (s[0] == '-'); i < sz(s); i++) x = x*10 + s[i] - '0';return x*(s[0] == '-' ? -1: 1);}
bool is_prime(ll n) {if (n < 2) return 0;if (n < 4) return 1;if (n % 2 == 0 || n % 3 == 0) return 0;for (ll i = 5; i*i <= n; i+=6) {if(n % i == 0 || n % (i + 2) == 0) return 0;}return 1;}
bool is_square(ll n) {ll k = sqrt(n); return k*k == n;}
ll factorial(int n) {ll x = 1;for (int i = 2; i <= n; i++) x*=i;return x;}
ll factorial(int n, int m) {ll x = 1;for (ll i = 2; i <= n; i++) x = x*i % m;return x;}
bool is_power(ll n, ll k) {while (n % k == 0) n/=k;return n == 1ll;}
string str(ll n) {if (n == 0) return "0"; string s = ""; bool c = 0; if (n < 0) c = 1, n = -n; while (n) {s+=n % 10 + '0'; n/=10;} if (c) s+='-'; Reverse(s); return s;}
string repeat(const string &s, int n) {if (n < 0) return ""; string x = ""; while (n--) x+=s; return x;}
string bin(ll n) {string s = ""; while (n) {s+=(n & 1) + '0'; n>>=1;} Reverse(s); return s;}
void sieve(vector<bool> &a) {int n = a.size(); a[0] = a[1] = 0; for (int i = 4; i < n; i+=2) a[i] = 0; for (int i = 3; i*i < n; i+=2) {if (a[i]) {for (int j = i*i; j < n; j+=(i << 1)) a[j] = 0;}}}
vector<pii> factorize(int n) {vector<pii> a; for (int i = 2; i*i <= n; i++) {if (n % i == 0) {int k = 0; while (n % i == 0) k++, n/=i; a.emplace_back(i, k);}} if (n > 1) a.emplace_back(n, 1); return a;}

template<class A, class B> istream& operator>>(istream& in, pair<A, B> &p) {in >> p.first >> p.second; return in;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &p) {out << p.first << ' ' << p.second; return out;}
template<class T> istream& operator>>(istream& in, vector<T> &a) {for (auto &i: a) in >> i; return in;}
template<class T> ostream& operator<<(ostream& out, const vector<T> &a) {for (auto &i: a) out << i << ' '; return out;}
template<class T> istream& operator>>(istream& in, vector<vector<T>> &a) {for (auto &i: a) in >> i; return in;}
template<class T> ostream& operator<<(ostream& out, const vector<vector<T>> &a) {for (auto &i: a) out << i << '\n'; return out;}
template<class T> istream& operator>>(istream& in, deque<T> &a) {for (auto &i: a) in >> i; return in;}
template<class T> ostream& operator<<(ostream& out, const deque<T> &a) {for (auto &i: a) out << i << ' '; return out;}
// istream& operator>>(istream& in, __int128_t &a) {string s; in >> s; a = 0; for (auto &i: s) a = a*10 + (i - '0'); return in;}
// ostream& operator<<(ostream& out, __int128_t a) {string s = ""; while (a > 0) {s+=(int)a % 10 + '0'; a/=10;} Reverse(s); out << s; return out;}

int f[128];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(10);
    int m, k; string s; cin >> m >> k >> s;
    //m = 3;
    int n = sz(s);
    vb c(26);
    trav(i,s) c[i - 'A'] = 1;
    vc ch;
    For(i,0,26){
        if (c[i]) ch.pb(i + 'A');
    }
    assert(sz(ch) == m);
    For(i,0,m) f[ch[i]] = i;
    vi a(m);
    int x = n;
    for (int l = 0, r = 0; l < n; l++) {
        if (l) a[f[s[l - 1]]]--;
        while (r < n && Min(a) < k) a[f[s[r++]]]++;
        if (r == n) break;
        x = min(x, sum(a) - m*k);
    }
    cout << x;
    cerr << "\nProcess returned 0 (0x0)   execution time :  " << 0.001*clock() << " s";
    return 0;
}
