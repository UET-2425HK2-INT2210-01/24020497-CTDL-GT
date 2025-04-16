#include <iostream>
#include <vector>
using namespace std;
int sum = 0;
int recursion(int n) {
    if (n == 0) return sum;
    sum += n;
    n--;
    recursion(n);
}

int main() {
    int n;
    cin >> n;
    cout << recursion(n);
    return 0;
}
