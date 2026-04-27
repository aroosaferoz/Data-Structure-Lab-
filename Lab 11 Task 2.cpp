#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, left, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, right, key);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    int key;
    cout << "Recursive Binary Search \n";
    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, size - 1, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}