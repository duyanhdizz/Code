#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,02,no-stack-protector")
#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("O1")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,mmx,abm")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int NM = 9 + 5e6;
const int INF = 1e9;
static struct FastOutput
{
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t buf_pos = 0;
    static constexpr int TMP_SIZE = 1 << 20;
    char tmp[TMP_SIZE];
    FILE *out = stdout;

    inline void put_char(char c)
    {
        buf[buf_pos++] = c;
        if (buf_pos == BUF_SIZE)
        {
            fwrite(buf, 1, buf_pos, out);
            buf_pos = 0;
        }
    }

    ~FastOutput()
    {
        fwrite(buf, 1, buf_pos, out);
    }

    inline FastOutput &operator<<(char c)
    {
        put_char(c);
        return *this;
    }

    inline FastOutput &operator<<(const char *s)
    {
        while (*s)
        {
            put_char(*s++);
        }
        return *this;
    }

    inline FastOutput &operator<<(const string &s)
    {
        for (int i = 0; i < (int)s.size(); i++)
        {
            put_char(s[i]);
        }
        return *this;
    }

    template <typename T>
    inline char *integer_to_string(T n)
    {
        // beware of TMP_SIZE
        char *p = tmp + TMP_SIZE - 1;
        if (n == 0)
        {
            *--p = '0';
        }
        else
        {
            bool is_negative = false;
            if (n < 0)
            {
                is_negative = true;
                n = -n;
            }
            while (n > 0)
            {
                *--p = (char)('0' + n % 10);
                n /= 10;
            }
            if (is_negative)
            {
                *--p = '-';
            }
        }
        return p;
    }

    template <typename T>
    inline typename enable_if<is_integral<T>::value, char *>::type stringify(T n)
    {
        return integer_to_string(n);
    }

#if !defined(_WIN32) || defined(_WIN64)
    inline char *stringify(__int128 n)
    {
        return integer_to_string(n);
    }
#endif

    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, char *>::type stringify(T n)
    {
        sprintf(tmp, "%.17f", n);
        return tmp;
    }

    template <typename T>
    inline FastOutput &operator<<(const T &n)
    {
        auto p = stringify(n);
        for (; *p != 0; p++)
        {
            put_char(*p);
        }
        return *this;
    }
} fast_output;
#define cout fast_output

int n, a[N], d[NM];
bool dd[NM];

int32_t main() {
#define TASKNAME "fcb034_gcd"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	fill(dd, dd + NM, false);
	for(int i = 0; i < n; i++) cin >> a[i];
	int res = a[0];
	for(int i = 1; i < n; i++) res = __gcd(res,a[i]);
	for(int i = 0; i < n; i++) {
		a[i] /= res;
		d[a[i]]++;
	}
	int res3 = n;
	for(int i = 2; i < NM; i++) {
		if(dd[i] == false) {
			int res2 = d[i];
			for(int j = 2 * i; j < NM; j += i) dd[j] = true, res2 += d[j];
			res3 = min(res3, n - res2);
		}
	}
	if(res3 == n) cout << -1;
	else cout << res3;
	return 0;
}