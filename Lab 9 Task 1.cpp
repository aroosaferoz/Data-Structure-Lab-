#include <iostream>
using namespace std;

// Applicant Node
struct Applicant {
    int id, height, weight;
    float vision;
    string status;
    Applicant* next;
    Applicant* prev;
};

class Queue {
private:
    Applicant *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Enqueue (insert at rear)
    void enqueue(int id, int h, int w, float v, string s) {
        Applicant* temp = new Applicant();
        temp->id = id;
        temp->height = h;
        temp->weight = w;
        temp->vision = v;
        temp->status = s;
        temp->next = NULL;
        temp->prev = NULL;

        if(front == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }

    // Dequeue (remove from front)
    void dequeue() {
        if(front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Applicant* temp = front;
        cout << "\n---Applicant " << temp->id << " completed test---\n";

        front = front->next;

        if(front != NULL)
            front->prev = NULL;
        else
            rear = NULL;

        delete temp;
    }

    // Remove 2nd applicant (urgency case)
    void removeSecond() {
        if(front == NULL || front->next == NULL) {
            cout << "Less than 2 applicants\n";
            return;
        }

        Applicant* temp = front->next;

        cout << "\n---Applicant " << temp->id << " left due to urgency---\n";

        front->next = temp->next;

        if(temp->next != NULL)
            temp->next->prev = front;
        else
            rear = front;

        delete temp;
    }

    // Display Queue
    void display() {
        if(front == NULL) {
            cout << "Queue empty\n";
            return;
        }

        Applicant* temp = front;
        cout << "\nQueue:";

        while(temp != NULL) {
            cout << "ID: " << temp->id
                 << " Height: " << temp->height
                 << " Weight: " << temp->weight
                 << " Vision: " << temp->vision
                 << " Status: " << temp->status << endl;

            temp = temp->next;
        }
    }
};

// Main Function
int main() {
    Queue q;

    // 7 applicants
    cout << "---Queue Initially---\n";
    q.enqueue(1, 170, 65, 1.0, "Waiting");
    q.enqueue(2, 168, 60, 1.2, "Waiting");
    q.enqueue(3, 175, 70, 1.0, "Waiting");
    q.enqueue(4, 180, 75, 0.9, "Waiting");
    q.enqueue(5, 165, 55, 1.1, "Waiting");
    q.enqueue(6, 172, 68, 1.0, "Waiting");
    q.enqueue(7, 169, 62, 1.3, "Waiting");

    q.display();

    // Urgency case
    q.removeSecond();

    q.display();

    // First applicant gives test
    q.dequeue();

    q.display();

    return 0;
}