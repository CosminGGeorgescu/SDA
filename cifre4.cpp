#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("cifre4.in");
ofstream fout("cifre4.out");

void solve(int& n, int& p) {
    queue<long long> q;
    vector<bool> vis(p, false);

    q.push(0);
    while (!q.empty()) {
        long long curr = q.front();
        q.pop();

        if (curr % p == n) {
            fout << curr << '\n';
            return;
        }

        for (int digit : {2, 3, 5, 7}) {
            long long next = curr * 10 + digit;
            int r = next % p;

            if (!vis[r]) {
                vis[r] = true;
                q.push(next);
            }
        }
    }

    fout << "-1\n";
    return;
}

int main() {
    int t, n, p;

    fin >> t;
    for (int i = 0; i < t; i++) {
        fin >> n >> p;
        solve(n, p);
    }

    return 0;
}
