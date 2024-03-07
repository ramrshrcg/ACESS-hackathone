#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> div(n);
    for (int i = 0; i < n; ++i) {
        cin >> div[i];
    }

    sort(div.begin(), div.end());

    int x, y;

    for (int i = 0; i < n; ++i) {
        if (div[i] != div[n - 1 - i]) {
            x = div[i];
            y = div[n - 1 - i];
            break;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}
