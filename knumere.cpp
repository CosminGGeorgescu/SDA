#include <fstream>
#include <vector>
#include <deque>

using namespace std;

ifstream fin("knumere.in");
ofstream fout("knumere.out");

int main() {
    deque<int> dq;
    vector<int> difs;
    int n, k, difmin = __INT_MAX__, x, y;

    fin >> n >> k >> x;
    k = n - k - 1;
    for (int i = 0; i < n - 1; i++) {
        fin >> y;
        difs.push_back(y - x);
        x = y;
    }

    for (int i = 0; i < n - 1; i++) {
        while (!dq.empty() && difs[i] >= difs[dq.back()])
            dq.pop_back();
    
        dq.push_back(i);

        if (dq.front() == i - k)
            dq.pop_front();
        
        if (i >= k - 1)
            difmin = min(difmin, difs[dq.front()]);
    }

    fout << difmin;

    return 0;
}
