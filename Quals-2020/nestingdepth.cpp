#include <iostream>
#include <string>

using namespace std;

void solve() {
    int cases;
    cin >> cases;
    for (int cs = 1; cs <= cases; cs++) {
        int curr_depth = 0;
        string s;
        cin >> s;
        cout << "Case #" << cs << ": ";        
        for (char c : s) {
            while (c - 0 > curr_depth) {
                cout << ")";
                curr_depth--;
            }
            while (c - 0 < curr_depth) {
                cout << "(";
                curr_depth++;
            }
            cout << s;
        }
        for (int i = 0; i < curr_depth; i++) {
            cout << ")";
        }
        cout << endl;

    }
}

int main() {
    solve();
    return 0;
}