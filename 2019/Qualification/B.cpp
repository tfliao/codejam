#include <iostream>
#include <string>
using namespace std;

int T;

int main()
{
    cin >> T;
    for (int nCase=1; nCase <= T; ++nCase) {
        int len;
        string N;
        cin >> len >> N;

        for (char& c : N) {
            c = 'S' + 'E' - c;
        }
        cout << "Case #" << nCase << ": ";
        cout << N << endl;
    }
    return 0;
}
