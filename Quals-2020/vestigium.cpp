#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int cases;
    cin >> cases;
    for (int c = 1; c <= cases; c++) {
        int sz, n;
        cin >> sz;
        vector<vector<int>> res;
        vector<int> level;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                cin >> n;
                level.push_back(n);
            }
            res.push_back(level);
            level.clear();
        }
        int k = 0, r = 0, cols = 0;
        for (int i = 0; i < sz; i++) {
            k += res[i][i];
        }
        set<int> s;

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (s.find(res[i][j]) == s.end()) s.insert(res[i][j]);
                else {
                    r++;
                    break;
                }
            }
            
            s.clear();
        }
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (s.find(res[j][i]) == s.end()) s.insert(res[j][i]);
                else {
                    cols++;
                    break;
                }
            }
            s.clear();
        }
        cout << "Case #" << c << ": " << k << " " << r << " " << cols << endl;
    }
}

int main() {
    solve();
    return 0;
}

