#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    int queue[size];
    int front = -1, rear = -1;
    int choice, val;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if (rear == size - 1) {
                    cout << "Queue Overflow\n";
                } else {
                    cout << "Enter value: ";
                    cin >> val;
                    if (front == -1) front = 0;
                    queue[++rear] = val;
                    cout << "Inserted Successfully\n";
                }
                break;

            case 2:
                if (front == -1 || front > rear) {
                    cout << "Queue Underflow\n";
                } else {
                    cout << "Deleted: " << queue[front++] << endl;
                }
                break;

            case 3:
                if (front == -1 || front > rear) {
                    cout << "Queue is Empty\n";
                } else {
                    cout << "Queue: ";
                    for (int i = front; i <= rear; i++) {
                        cout << queue[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}