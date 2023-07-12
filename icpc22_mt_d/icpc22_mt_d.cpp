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

static struct FastInput
{
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t chars_read = 0;
    size_t buf_pos = 0;
    FILE *in = stdin;
    char cur = 0;

    inline char get_char()
    {
        if (buf_pos >= chars_read)
        {
            chars_read = fread(buf, 1, BUF_SIZE, in);
            buf_pos = 0;
            buf[0] = (chars_read == 0 ? -1 : buf[0]);
        }
        return cur = buf[buf_pos++];
    }

    inline void tie(int) {}

    inline explicit operator bool()
    {
        return cur != -1;
    }

    inline static bool is_blank(char c)
    {
        return c <= ' ';
    }

    inline bool skip_blanks()
    {
        while (is_blank(cur) && cur != -1)
        {
            get_char();
        }
        return cur != -1;
    }

    inline FastInput &operator>>(char &c)
    {
        skip_blanks();
        c = cur;
        return *this;
    }

    inline FastInput &operator>>(string &s)
    {
        if (skip_blanks())
        {
            s.clear();
            do
            {
                s += cur;
            } while (!is_blank(get_char()));
        }
        return *this;
    }

    template <typename T>
    inline FastInput &read_integer(T &n)
    {
        // unsafe, doesn't check that characters are actually digits
        n = 0;
        if (skip_blanks())
        {
            int sign = +1;
            if (cur == '-')
            {
                sign = -1;
                get_char();
            }
            do
            {
                n += n + (n << 3) + cur - '0';
            } while (!is_blank(get_char()));
            n *= sign;
        }
        return *this;
    }

    template <typename T>
    inline typename enable_if<is_integral<T>::value, FastInput &>::type operator>>(T &n)
    {
        return read_integer(n);
    }

#if !defined(_WIN32) | defined(_WIN64)
    inline FastInput &operator>>(__int128 &n)
    {
        return read_integer(n);
    }
#endif

    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, FastInput &>::type operator>>(T &n)
    {
        // not sure if really fast, for compatibility only
        n = 0;
        if (skip_blanks())
        {
            string s;
            (*this) >> s;
            sscanf(s.c_str(), "%lf", &n);
        }
        return *this;
    }
} fast_input;

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

class Bit_Presum {
public:
    static constexpr uint32_t omega = CHAR_BIT * sizeof(uint64_t);
    static constexpr uint32_t lg_omega = __lg(omega);
    static_assert(omega == 64u);

    Bit_Presum(vector<uint64_t> mask_)
            : n(mask_.size()), mask(move(mask_)), presum(n+1) {
        build();
    }
    Bit_Presum(uint32_t bits, bool init_val = 0)
            : n((bits>>lg_omega) + 1),
              mask(n, init_val ? ~uint64_t{0} : uint64_t{0}),
              presum(n+1) {
        if (init_val) mask.back()<<=((n<<lg_omega) - bits);
        build();
    }
    // popcount l <= i < r
    uint32_t query(uint32_t l, uint32_t r) const {
        if (__builtin_expect(r < l, false)) return 0;
        return query(r) - query(l);
    }
    // popcount 0 <= i < x
    uint32_t query(uint32_t x) const {
        uint32_t high = x>>lg_omega, low = x & ((uint64_t{1}<<lg_omega) - 1);
        uint32_t ret = presum_query(high);
        ret += __builtin_popcountll(mask[high]& ((uint64_t{1} << low)-1));
        return ret;
    }

    void update_pre_build(uint32_t x, bool val) {
        uint32_t high = x>>lg_omega, low = x & ((1u<<lg_omega) - 1);
        mask[high] = (mask[high] & ~(uint64_t{1} << low)) | (uint64_t{val}<<low);
    }
    void do_build() {
        build();
    }

    friend ostream& operator<<(ostream&o, Bit_Presum const&b) {
        for (auto const& e : b.mask) {
            stringstream ss;
            ss << bitset<omega>(e);
            auto s = ss.str();
            reverse(s.begin(), s.end());
            o << s << "|";
        }
        o << " : ";
        for (auto const&e:b.presum) o << e << " ";
        o << "\n";
        return o;
    }

private:
    void presum_build() {
        for (uint32_t x = 1; x <= n; ++x) {
            presum[x] += presum[x-1];
        }
    }
    // sum 0 <= i < x
    uint32_t presum_query(uint32_t x) const {
        return presum[x];
    }
    void build() {
        for (uint32_t x = 0; x < n; ++x) {
            presum[x+1] = __builtin_popcountll(mask[x]);
        }
        presum_build();
    }

    const uint32_t n;
    vector<uint64_t> mask;
    vector<uint32_t> presum;
};


template<typename T, typename Bit_Ds = Bit_Presum>
class WaveletMatrix {
public:
    static_assert(is_integral<T>::value);
    static constexpr uint32_t height = CHAR_BIT * sizeof(T);

    WaveletMatrix(vector<T> v): n(v.size()), data(height, n) {
        build(move(v));
    }

    uint32_t range_count(int l, int r, T A, T B) const {
        assert(0 <= l && r <= n);
        return count_lower(l, r, B) - count_lower(l, r, A);
    }

    uint32_t range_count_up(int l, int r, T A) const {
        assert(0 <= l && r <= n);
        if (__builtin_expect(l>r, false)) return uint32_t{0};
        return (r-l) - count_lower(l, r, A);
    }

    T k_th(int l, int r, int k) const {
        assert(0 <= k && k < n);
        return get_kth(l, r, k);
    }

private:
    void build(vector<T> v) {
        m_index.resize(height);
        T const a = numeric_limits<T>::min();
        for (int h = height-1; h>=0;--h) {
            T const b = a + (T{1}<<(max(0, h-1))) - !h + (T{1}<<(max(0, h-1)));
            for (int i=0;i<n;++i) {
                data[h].update_pre_build(i, v[i]<b);
            }
            data[h].do_build();
            const int m = stable_partition(v.begin(), v.end(), [&b](T const&x) {return x < b;}) - v.begin();
            for (int i=m;i<n;++i) {
                v[i] = v[i] - (T{1}<<(max(0, h-1))) + !h - (T{1}<<(max(0, h-1)));
            }
            m_index[h] = m;
        }
    }
    uint32_t count_lower(int l, int r, T const&B) const {
        assert(0 <= l && r <= n);
        if (__builtin_expect(r<l, false)) return 0;
        uint32_t ret = 0;
        int h = height;
        T a = numeric_limits<T>::min();
        while(h > 0) {
            --h;
			bool go_left = B < a + (T{1}<<(max(0, h-1))) - !h + (T{1}<<(max(0, h-1)));
            const int low_l = data[h].query(l), low_r = data[h].query(r);
            if (go_left) {
                l = low_l;
                r = low_r;
            } else {
                a = a + (T{1}<<(max(0, h-1))) - !h + (T{1}<<(max(0, h-1)));
                ret+= low_r-low_l;
                l = m_index[h] + l-low_l;
                r = m_index[h] + r-low_r;
            }
        }
        return ret;
    }
    T get_kth(int l, int r, int k) const {
        assert(0 <= l && r <= n);
        assert(0 <= k && k < r-l);
        int h = height;
        T a = numeric_limits<T>::min();
        while (h > 0) {
            --h;
            const int low_l = data[h].query(l), low_r = data[h].query(r), low_lr = low_r-low_l;
            bool go_left = k < low_lr;
            if (go_left) {
                l = low_l;
                r = low_r;
            } else {
                a+= T{1}<<h;
                k-= low_lr;
                l = m_index[h] + l-low_l;
                r = m_index[h] + r-low_r;
            }
        }
        return a;
    }

    const int n;
    vector<int> m_index;
    vector<Bit_Ds> data;
};

#define cin fast_input
#define cout fast_output
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, t;

int32_t main() {
#define TASKNAME "icpc22_mt_d"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n >> t;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    WaveletMatrix mat(a);
    while(t--) {
    	int l, r;
    	cin >> l >> r;
    	int res = (r - l) / 2;
    	cout << mat.k_th(l - 1, r, res) << '\n';
	}
}
