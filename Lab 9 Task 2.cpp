#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }

    cout << "Inserted Successfully\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;
    cout << "Deleted: " << temp->data << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void display() {
    if (front == NULL) {
        cout << "Queue is Empty\n";
        return;
    }

    Node* temp = front;
    cout << "\nQueue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
	cout << "---Enqueue 10\n ";
    enqueue(10);
    cout << "---Enqueue 20\n ";
    enqueue(20);
    cout << "---Enqueue 30\n ";
    enqueue(30);

    display();
    cout << "---Queue after dequeue deleted 10\n ";
    dequeue();
    display();

    return 0;
}