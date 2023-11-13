#include <fstream>
#include <stack>

using namespace std;

ifstream fin("nrpits.in");
ofstream fout("nrpits.out");

int main() {
    stack<int> s;
    int n, x, sol = 0;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> x;
        while (s.size() > 0 && s.top() < x) {
            if (s.size() > 1)
                sol++;
            s.pop();
        }
        s.push(x);
    }

    fout << sol;

    return 0;
}
