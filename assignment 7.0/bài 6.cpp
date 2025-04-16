#include <iostream>
using namespace std;
int ans = 0;
int temp = 0;
int recursion(int n) {
    if (n == 0) return ans;
    temp = n % 10;
    n /= 10;
    ans+=temp;
     recursion(n);
}

int main() {
    int n;
    cin>>n;
    cout << recursion(n);
    return 0;
}
