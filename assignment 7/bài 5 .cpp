#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), c(n, 0); // mảng c là bộ đếm (control array)
    for (int i = 0; i < n; ++i) {//Gán phần tử của hoán vị đầu tiên
        a[i] = i + 1;
    }

    // In hoán vị đầu tiên
    for (int x : a) cout << x << " ";
    cout << endl;

    int i = 0;//gán i=0
    while (i < n) {
        if (c[i] < i) {//Trường hợp c[i]<i
            if (i % 2 == 0) {//Nếu số chẵn 
                swap(a[0], a[i]);//Đổi chỗ
            } else {//Nếu số lẻ
                swap(a[c[i]], a[i]);//Đổi chỗ
            }

            // In hoán vị tiếp theo
            for (int x : a) cout << x << " ";
            cout << endl;

            c[i]++;
            i = 0;
        } else {//Trường hợp c[i]>1
            c[i] = 0;
            i++;
        }
    }

    return 0;
}
/*
n=3
hoán vị đầu  a =1 2 3
             c= 0 0 0
    Bước 1:i=0,c[i]=0
    ->i++   ->i=1;
Bước 2 i=1,c[i]=0;
->c[i]<i   ->đổi chỗ 2 1 3
    c[1]++;*/
    
