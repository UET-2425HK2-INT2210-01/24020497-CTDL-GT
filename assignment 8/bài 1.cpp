#include <iostream>
using namespace std;

int partition(int a[], int high, int low) {
	int pivot = a[high];
	int index = low - 1;
	for (int i = low; i < high; i++) {
		if (a[i] < pivot) {
			index++;
			swap(a[index], a[i]);
		}
	}
	swap(a[index + 1], a[high]);
	return index + 1;
}
void quicksort(int a[], int high, int low) {
	if (high <= low) return;
	int temp = partition( a, high, low);
	quicksort(a, high, temp+1);
	quicksort(a, temp-1,low);
}
int main() {
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quicksort(a, n-1, 0);
	for (int i = 0; i < n; i++) {
		cout<< a[i]<<" ";
	}
}
