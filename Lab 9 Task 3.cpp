#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    int queue[size];
    int front = -1, rear = -1;
    int n, val;

    cout << "How many elements to insert? ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        if (rear == size - 1) {
            cout << "Queue Overflow\n";
            break;
        }
        cout << "Enter value: ";
        cin >> val;
        if (front == -1) front = 0;
        queue[++rear] = val;
    }

    // Display
    if (front == -1 || front > rear) {
        cout << "Queue is Empty\n";
    } else {
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
    }

    // Count
    int count = rear - front + 1;
	cout << "\nTotal Elements: " << count;
    
    return 0;
}