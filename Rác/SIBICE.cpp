#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h, w;
    scanf("%d%d%d", &n, &h, &w);
    for(int i = 0; i < n; ++i) {
        int l; 
        scanf("%d", &l);
        puts((h*h + w*w >= l*l) ? "DA" : "NE");
    }

    return 0;
}