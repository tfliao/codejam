#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define MX (100001)

int T;
int N, K;
int C[MX], D[MX];

void input()
{
    cin >> N >> K;
    for (int i=0;i<N;++i) cin >> C[i];
    for (int i=0;i<N;++i) cin >> D[i];
}

void solv()
{
    int cnt = 0;
    for (int i=0;i<N;++i) {
        for (int j=i;j<N;++j) {
            int cc = 0, dd = 0;
            for (int k=i;k<=j;++k) {
                if (C[k] > cc) cc = C[k];
                if (D[k] > dd) dd = D[k];
            }
            //printf("%d vs %d\n", cc, dd);
            if (abs(cc-dd) <= K) ++cnt;
        }
    }
    cout << cnt << endl;
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
