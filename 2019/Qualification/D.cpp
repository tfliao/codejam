#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T;
int N, B, F;

string send_guess(const string& guess)
{
    string ret;
    cout << guess << endl << flush;
    cin >> ret;
    return ret;
}

int send_answer(const vector<int>& answer)
{
    bool first = true;
    string s;
    for (auto a : answer) {
        if (!first) s += " ";
        s += to_string(a);
        first = false;
    }
    cout << s << endl << flush;
    cin >> s;
    return stoi(s);
}

void fill_pattern(string& pattern, int sz)
{
    pattern.resize(N);
    for (int i=0;i<N;++i) {
        pattern[i] = (i / sz) % 2 + '0';
    }
}

void solve()
{
    vector<int> m(N-B);
    string pattern;
    string result;
    int sz = 16;

    while (sz > 0) {
        fill_pattern(pattern, sz);
        result = send_guess(pattern);
        for(int i=0;i<N-B;++i) {
            m[i] = (m[i] << 1) + result[i] - '0';
        }
        sz >>= 1;
    }
    m.push_back(-1);
    vector<int> ans;
    int p = 0;
    for (int i=0;i<N;++i) {
        if ((i & 31) != m[p] || m[p] == -1) {
            ans.push_back(i);
        } else {
            ++p;
        }
    }
    send_answer(ans);
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> N >> B >> F;
        solve();
    }
    return 0;
}
