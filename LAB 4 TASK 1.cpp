#include <iostream>
using namespace std;

class Mobile {
public:
    string brand;
    int unitsOnHand;
    double price;

    Mobile(string b = "", int u = 0, double p = 0.0) {
        brand = b;
        unitsOnHand = u;
        price = p;
    }
};

struct Node {
    Mobile data;
    Node* next;

    Node(Mobile m) {
        data = m;
        next = NULL;
    }
};

class Store {
private:
    Node* head;

public:
    Store() {
        head = NULL;
    }

    // Insert at Start
    void insertAtStart(string b, int u, double p) {
        Mobile m(b, u, p);
        Node* newNode = new Node(m);

        newNode->next = head;
        head = newNode;
    }

    // Insert at End
    void insertAtEnd(string b, int u, double p) {
        Mobile m(b, u, p);
        Node* newNode = new Node(m);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Delete by Brand
    void deleteMobile(string brandName) {
        if (head == NULL) {
            cout << "Store is empty\n";
            return;
        }

        if (head->data.brand == brandName) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted successfully\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data.brand != brandName) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Mobile not found\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Deleted successfully\n";
    }

    // Display
    void display() {
        if (head == NULL) {
            cout << "Store is empty\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << "Brand: " << temp->data.brand << endl;
            cout << "Units: " << temp->data.unitsOnHand << endl;
            cout << "Price: " << temp->data.price << endl;
            cout << "------------------------\n";
            temp = temp->next;
        }
    }
};

int main() {
    Store s;
    int choice;
    string brand;
    int units;
    double price;

    do {
        cout << "\n1. Insert at Start";
        cout << "\n2. Insert at End";
        cout << "\n3. Delete Mobile";
        cout << "\n4. Display All";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Brand: ";
            cin >> brand;
            cout << "Enter Units: ";
            cin >> units;
            cout << "Enter Price: ";
            cin >> price;
            s.insertAtStart(brand, units, price);
            break;

        case 2:
            cout << "Enter Brand: ";
            cin >> brand;
            cout << "Enter Units: ";
            cin >> units;
            cout << "Enter Price: ";
            cin >> price;
            s.insertAtEnd(brand, units, price);
            break;

        case 3:
            cout << "Enter Brand to delete: ";
            cin >> brand;
            s.deleteMobile(brand);
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}