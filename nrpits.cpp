#include <fstream>
#include <stack>

using namespace std;

ifstream fin("nrpits.in");
ofstream fout("nrpits.out");

int main() {
    // Stack folosit pentru memorarea sirului de numere si colapsarea facila a pit-urilor
    stack<int> s;
    int n, x, sol = 0;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> x;
        // Detectia de pit-uri
        // a1 a2 a3, a1 > a2 && a2 < a3 => stack.pop(a2)
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
