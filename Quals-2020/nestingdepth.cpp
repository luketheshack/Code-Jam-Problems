#include <iostream>
#include <string>

using namespace std;

void solve() {
    int cases;
    cin >> cases;
    cout << endl;
    for (int cs = 1; cs <= cases; cs++) {
        int curr_depth = 0;
        string in;
        string out = "Case #";
        cin >> in;
        out += (to_string(cs) + ": ");
        for (char c : in) {
            while (c - '0' > curr_depth) {
                out += '(';
                curr_depth++;
            }
            while (c - '0' < curr_depth) {
                out += ')';
                curr_depth--;
            }
            out += c;
        }
        for (int i = 0; i < curr_depth; i++) {
            out += ')';
        }
        cout << out << endl;

    }
}

int main() {
    solve();
    return 0;
}