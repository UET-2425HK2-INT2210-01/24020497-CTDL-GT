#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), c(n, 0); // mảng c là bộ đếm (control array)
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    // In hoán vị đầu tiên
    for (int x : a) cout << x << " ";
    cout << endl;

    int i = 0;
    while (i < n) {
        if (c[i] < i) {
            if (i % 2 == 0) {
                swap(a[0], a[i]);
            } else {
                swap(a[c[i]], a[i]);
            }

            // In hoán vị tiếp theo
            for (int x : a) cout << x << " ";
            cout << endl;

            c[i]++;
            i = 0;
        } else {
            c[i] = 0;
            i++;
        }
    }

    return 0;
}
