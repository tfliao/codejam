#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int T;

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
