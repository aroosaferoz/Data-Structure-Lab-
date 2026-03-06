#include <iostream>
using namespace std;

struct Node {
    int rain;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->rain = val;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void rainfallStats() {

    Node* temp = head;
    int total = 0;
    int highest = -1;
    int lowest = 9999;
    int day = 1, highDay, lowDay;

    while(temp != NULL) {

        total += temp->rain;

        if(temp->rain > highest) {
            highest = temp->rain;
            highDay = day;
        }

        if(temp->rain < lowest) {
            lowest = temp->rain;
            lowDay = day;
        }

        temp = temp->next;
        day++;
    }

    cout<<"Total rainfall = "<<total<<endl;
    cout<<"Average rainfall = "<<total/7.0<<endl;
    cout<<"Highest rainfall on day "<<highDay<<endl;
    cout<<"Lowest rainfall on day "<<lowDay<<endl;
}

void rainfallAfter5() {

    Node* temp = head;

    for(int i=1;i<6;i++) {
        if(temp != NULL)
            temp = temp->next;
    }

    if(temp != NULL)
        cout<<"Rainfall after 5th node: "<<temp->rain<<endl;
}

int main() {

    int val;

    for(int i=1;i<=7;i++) {

        cout<<"Enter rainfall for day "<<i<<": ";
        cin>>val;

        if(val < 0) {
            cout<<"Negative values not allowed\n";
            i--;
            continue;
        }

        insert(val);
    }

    rainfallStats();
    rainfallAfter5();
}