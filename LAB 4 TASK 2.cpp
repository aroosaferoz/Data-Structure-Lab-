#include <iostream>
using namespace std;

class Profile {
public:
    int id;
    string name;
    string gender;
    int age;
    string email;
    string interest;
    string dob;

    Profile(int i = 0, string n = "", string g = "", int a = 0,
            string e = "", string in = "", string d = "") {
        id = i;
        name = n;
        gender = g;
        age = a;
        email = e;
        interest = in;
        dob = d;
    }
};

struct Node {
    Profile data;
    Node* next;

    Node(Profile p) {
        data = p;
        next = NULL;
    }
};

class Portal {
private:
    Node* head;

public:
    Portal() {
        head = NULL;
    }

    void insertProfile(int id, string name, string gender, int age,
                       string email, string interest, string dob) {

        Profile p(id, name, gender, age, email, interest, dob);
        Node* newNode = new Node(p);

        newNode->next = head;
        head = newNode;
    }

    void updateProfile(int id) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data.id == id) {
                cout << "Enter new email: ";
                cin >> temp->data.email;
                cout << "Enter new interest: ";
                cin >> temp->data.interest;
                cout << "Profile updated\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Profile not found\n";
    }

    void deleteProfile(string name) {
        if (head == NULL) {
            cout << "No profiles\n";
            return;
        }

        if (head->data.name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted successfully\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data.name != name) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Profile not found\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Deleted successfully\n";
    }

    void searchProfile(string name) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data.name == name) {
                cout << "Profile Found\n";
                cout << "ID: " << temp->data.id << endl;
                cout << "Email: " << temp->data.email << endl;
                cout << "Interest: " << temp->data.interest << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Profile not found\n";
    }

    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "No profiles available\n";
            return;
        }

        while (temp != NULL) {
            cout << "ID: " << temp->data.id << endl;
            cout << "Name: " << temp->data.name << endl;
            cout << "Email: " << temp->data.email << endl;
            cout << "Interest: " << temp->data.interest << endl;
            cout << "----------------------\n";
            temp = temp->next;
        }
    }
};

int main() {
    Portal p;
    int choice;

    do {
        cout << "\n1. Add Profile";
        cout << "\n2. Update Profile";
        cout << "\n3. Delete Profile";
        cout << "\n4. Search Profile";
        cout << "\n5. Display All";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, age;
            string name, gender, email, interest, dob;

            cout << "Enter ID: "; 
			cin >> id;
            cout << "Enter Name: "; 
			cin >> name;
            cout << "Enter Gender: "; 
			cin >> gender;
            cout << "Enter Age: "; 
			cin >> age;
            cout << "Enter Email: "; 
			cin >> email;
            cout << "Enter Interest: "; 
			cin >> interest;
            cout << "Enter Date Of Birth: "; 
			cin >> dob;

            p.insertProfile(id, name, gender, age, email, interest, dob);
        }

        else if (choice == 2) {
            int id;
            cout << "Enter ID to update: ";
            cin >> id;
            p.updateProfile(id);
        }

        else if (choice == 3) {
            string name;
            cout << "Enter Name to delete: ";
            cin >> name;
            p.deleteProfile(name);
        }

        else if (choice == 4) {
            string name;
            cout << "Enter Name to search: ";
            cin >> name;
            p.searchProfile(name);
        }

        else if (choice == 5) {
            p.display();
        }

    } while (choice != 6);

    return 0;
}