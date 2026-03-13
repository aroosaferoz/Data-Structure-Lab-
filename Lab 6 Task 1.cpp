#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* last = NULL;

void insertBefore(int value){
    Node* newNode = new Node();
    newNode->data = value;

    if(last == NULL){
        last = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertAfter(int value){
    Node* newNode = new Node();
    newNode->data = value;

    if(last == NULL){
        last = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void deleteNode(int key){

    if(last == NULL){
        cout<<"List empty\n";
        return;
    }

    Node *curr = last->next, *prev = last;

    do{
        if(curr->data == key){

            if(curr == last && curr->next == last){
                last = NULL;
            }
            else{
                prev->next = curr->next;

                if(curr == last)
                    last = prev;
            }

            delete curr;
            cout<<"Deleted successfully\n";
            return;
        }

        prev = curr;
        curr = curr->next;

    }while(curr != last->next);

    cout<<"Value not found\n";
}

void display(){

    if(last == NULL){
        cout<<"List empty\n";
        return;
    }

    Node* temp = last->next;

    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != last->next);

    cout<<endl;
}

int main(){

    cout<<"---Before adding nodes in linked list:\n";
    display();
    cout<<"\n";
       
    insertBefore(10);
    insertBefore(5);
    insertAfter(20);
    insertAfter(30);
 
    cout<<"---After adding nodes in linked list (before and after):\n";
    display();
    cout<<"\n";

    cout<<"---Delete node 3 having value 20 in linked list: ";
    deleteNode(20);
    display();
    cout<<"\n";

    return 0;
}