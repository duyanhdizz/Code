#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> values;
vector<int> count;

void dfs(int node) {
    count[node] = 0;

    for (int child : tree[node]) {
        dfs(child);
        if (values[child] > values[node]) {
            count[node] += count[child] + 1;
        }
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);
    values.resize(n + 1);
    count.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << count[i] << endl;
    }

    return 0;
}
