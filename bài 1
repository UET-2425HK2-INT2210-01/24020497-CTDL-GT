#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int tohop(int n) {
    return n * (n - 1) / 2;
}

int main()
{
    int n;
    cin >> n;
    int count = 1;
    int ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            if (count >= 2) {
                ans += tohop(count);
            }
        }
        else {
            if (v[i] == v[i + 1]) {
                ++count;
            }
            else {
                if (count >= 2) {
                    ans += tohop(count);
                }
                count = 1;
            }
        }
    }
    cout << ans;
}
