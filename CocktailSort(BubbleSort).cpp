#include <iostream>

using namespace std;


void initialize(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % n + 1;
	}
}

void print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void cocktailSort(int* arr, int n) {
	bool flag1 = false;
	bool flag2 = false;
	int start = 0; 
	int end = n - 1;
	while (start < end) {
		flag1 = false;
		flag2 = false;

		for (int j = start; j < end; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				flag1 = true;
			}
		}
		if (!flag1)
			break;
		
		end--;
		for (int j = end; j > start; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				flag2 = true;
			}
		}
		if (!flag2)
			break;
		
		start++;
	}
}


int main() 
{
	int n;
	cin >> n;

	int* array = new int[n];
	initialize(array, n);

	print(array, n);
	cocktailSort(array, n);
	print(array, n);

	return 0;
}
