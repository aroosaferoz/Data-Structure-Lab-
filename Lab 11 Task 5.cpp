#include <iostream>
using namespace std;

int arraySum(int arr[], int size) {
    if (size == 0)
        return 0;

    return arr[size - 1] + arraySum(arr, size - 1);
}

int main() {
    int size;
    cout << "Recursive Sum of Array \n";
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];

    cout << "Enter elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Sum of all elements in array = " << arraySum(arr, size);

    return 0;
}