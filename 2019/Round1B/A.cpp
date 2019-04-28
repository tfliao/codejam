#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
using namespace std;

int T;
int P, Q;

set<int> X, Y;

struct PP
{
    int x, y;
    string d;
};

vector<PP> ps;

void input()
{
    cin >> P >> Q;
    ps.clear();
    X.clear();
    Y.clear();
    X.insert(0);
    Y.insert(0);
    for (int i=0;i<P;++i) {
        ps.push_back(PP());
        PP& p = ps.back();
        cin >> p.x >> p.y >> p.d;
//        X.insert(p.x);
//        Y.insert(p.y);
        if (p.d == "N") Y.insert(p.y + 1);
        else if (p.d == "E") X.insert(p.x+1);
        else if (p.d == "W") X.insert(p.x-1);
        else if (p.d == "S") Y.insert(p.y-1);
    }
}

void solv()
{
    pair<int, int> best;
    int best_cnt = 0;

    for (int x : X) {
        for (int y : Y) {
            int cnt = 0;
            for (PP& p : ps) {
                if (p.d == "N" && p.y < y) ++ cnt;
                else if (p.d == "E" && p.x < x) ++ cnt;
                else if (p.d == "W" && p.x > x) ++ cnt;
                else if (p.d == "S" && p.y > y) ++ cnt;
            }
            if (cnt > best_cnt) {
                best_cnt = cnt;
                best = make_pair(x, y);
            } else if (cnt == best_cnt) {
                if (x < best.first || (x==best.first && y < best.second)) {
                    best = make_pair(x, y);
                }
            }
        }
    }
    cout << best.first << " " << best.second << endl;
}

int main()
{
    cin >> T;
    for (int nCase=1; nCase <= T; ++nCase) {
        input();
        cout << "Case #" << nCase << ": ";
        solv();
    }
    return 0;
}
