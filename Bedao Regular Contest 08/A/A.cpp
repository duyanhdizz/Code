#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

int N, K, a[MAX];
long long bit[MAX], f[MAX];

long long getBit(int i) {
    long long ans = 0;
    while (i > 0) {
        ans += bit[i];
        i -= (i & (-i));
    }
    return ans;
}

void UpDate(int i, long long j) {
    while (i <= N) {
        bit[i] += j;
        i += (i & (-i));
    }
}

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) scanf("%d", a + i);

    for(int i = 0; i < N; i++) f[i] = 1;

    for(int j = 0; j < K; j++) {
        memset(bit, 0, sizeof bit);
        for(int i = 0; i < N; i++) {
            long long x = getBit(a[i] - 1);
            UpDate(a[i], f[i]);
            f[i] = x;           
        }
    }
    long long ans = 0;
    for(int i = 0; i < N; i++) ans += f[i];
    cout << ans;
    return 0;
}