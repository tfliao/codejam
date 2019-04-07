#include <iostream>
#include <string>
using namespace std;

int T;

int main()
{
    cin >> T;
    for (int nCase=1; nCase <= T; ++nCase) {
        string N, A, B;
        cin >> N;
        bool zero = false;
        for (char c : N) {
            if (c == '4') {
                A += '2';
                B += '2';
                zero = true;
            } else {
                A += c;
                if (zero) B += '0';
            }
        }
        cout << "Case #" << nCase << ": ";
        cout << A << " " << B << endl;
    }
    return 0;
}
