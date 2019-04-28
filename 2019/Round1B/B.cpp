#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int T;
int W;

ofstream fout("debug");
typedef unsigned long long ULL;

ULL send_query(int query)
{
    ULL ret;
    cout << query << endl << flush;
    cin >> ret;
    return ret;
}

int send_answer(const vector<int>& answer)
{
    int ret;
    bool first = true;
    stringstream ss;
    for (auto a : answer) {
        if (!first) ss << " ";
        ss << a;
        first = false;
    }
    cout << ss.str() << endl << flush;
    cin >> ret;
    return ret;
}

void solve()
{
    ULL r1 = send_query(219);
    ULL r2 = send_query(48);
    for (int i=2;i<W;++i) {
        send_query(1);
    }
    vector<int> ans(6);

    ans[3] = (r1 >> 54) & 127;
    ans[4] = (r1 >> 43) & 127;
    ans[5] = (r1 >> 36) & 127;

    r2 -= (ans[3] << 12) + (ans[4] << 9) + (ans[5] << 8);
    ans[0] = (r2 >> 48) & 127;
    ans[1] = (r2 >> 24) & 127;
    ans[2] = (r2 >> 16) & 127;

   int ret = send_answer(ans);
   if (ret < 0) exit(1);
}

int main()
{
    cin >> T >> W;
    while (T--) {
        solve();
    }
    return 0;
}
