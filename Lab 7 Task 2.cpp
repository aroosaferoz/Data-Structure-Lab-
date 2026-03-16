#include <iostream>
using namespace std;

class Inventory {
public:
    int serialNum;
    int manufactYear;
    int lotNum;

    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    void showData() {
        cout << "Serial Number: " << serialNum << endl;
        cout << "Manufacture Year: " << manufactYear << endl;
        cout << "Lot Number: " << lotNum << endl;
    }
};

class Node {
public:
    Inventory item;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(Inventory obj) {
        Node* newNode = new Node;

        newNode->item = obj;
        newNode->next = top;
        top = newNode;

        cout << "\nPart added successfully!\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Inventory is empty. Nothing to remove.\n";
            return;
        }

        Node* temp = top;

        cout << "\nRemoved Part Details:\n";
        temp->item.showData();

        top = top->next;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nNO DATA TO SHOW AS INVENTORY IS EMPTY\n";
            return;
        }

        Node* temp = top;

        while (temp != NULL) {
            temp->item.showData();
            cout << "-------------------\n";
            temp = temp->next;
        }
    }
};

int main() {

    Stack s;
    int choice;

    do {
        cout << "\n---INVENTORY DETAILS---\n";
        cout << "1. Add Part\n";
        cout << "2. Remove Part\n";
        cout << "3. Show Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {

            Inventory obj;
            int sNum, year, lot;

            cout << "\nEnter Serial Number: ";
            cin >> sNum;

            cout << "Enter Manufacture Year: ";
            cin >> year;

            cout << "Enter Lot Number: ";
            cin >> lot;

            obj.setData(sNum, year, lot);
            s.push(obj);
        }

        else if (choice == 2) {
            s.pop();
        }

        else if (choice == 3) {
            cout << "\n---Inventory Data --\n";
            s.display();
        }

    } while (choice != 4);

    cout << "\n---Remaining Inventory in Stack:\n";
    s.display();

    return 0;
}