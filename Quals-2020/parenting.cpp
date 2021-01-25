#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int cases;
    cin >> cases;
    for (int cs = 1; cs <= cases; cs++) {
        int activities;
        cin >> activities;
        vector<vector<int>> cameron, jamie;
        string out = "Case #" + to_string(cs) + ": ";

        bool cond = true;
        for (int j = 0; j < activities; j++) {

            int a,b;
            cin >> a >> b;
            bool c_ok = true, j_ok = true;
            vector<int> level = {a, b};
            
            // If either number is inbetween the two bounds of one of the timeslots, then it won't work for that person
            for (int i = 0; i < cameron.size(); i++) {
                if ((a < cameron[i][1] && a > cameron[i][0]) || (b < cameron[i][1] && b < cameron[i][0])) {
                    c_ok = false;
                    break;
                }
            }
            if (c_ok) {
                cameron.push_back(level);
                out += "C";
                
            }
            if (!c_ok) {
                for (int i = 0; i < jamie.size(); i++) {
                    if ((a < jamie[i][1] && a > cameron[i][0]) || (b < jamie[i][1] && jamie[i][0])) {
                        j_ok = false;
                        break;
                    }
                }

                if (j_ok) {
                    jamie.push_back(level);
                    out += "J";
                }
            }
            if (!c_ok && !j_ok) {
                cond = false;
                break;
            }
            
        }
        if (!cond) cout << "Case #" << cs << ": IMPOSSIBLE" << endl;
        else cout << out << endl;
        
    }
}

int main() {
    solve();
    return 0;
}