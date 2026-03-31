#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> road;
stack<int> garage;

// Add truck to road
void On_road(int id) {
    road.push(id);
}

// Move truck from road to garage
void Enter_garage(int id) {
    if(road.empty()) {
        cout << "Error: No vehicle on road.\n";
        return;
    }

    if(road.front() == id) {
        garage.push(id);
        road.pop();
    } else {
        cout << "Error: " << id << " No. Vehicle cannot enter into garage.\n";
    }
}

// Exit truck from garage
void Exit_garage(int id) {
    if(garage.empty()) {
        cout << "Garage empty\n";
        return;
    }

    if(garage.top() == id) {
        cout << id << " No. vehicle leaving garage\n";
        garage.pop();
    } else {
        cout << "Error: " << id << " No. Vehicle cannot exit garage.\n";
    }
}

// Show trucks
void Show_trucks(string type) {
    if(type == "road") {
        cout << "Road Vehicle: ";
        queue<int> temp = road;

        if(temp.empty()) {
            cout << "Empty";
        } else {
            while(!temp.empty()) {
                cout << temp.front();
                temp.pop();

                if(!temp.empty()) // print _ only if more elements exist
                    cout << "_";
            }
        }
        cout << endl;
    }

    else if(type == "garage") {
        cout << "Garage Vehicle: ";
        stack<int> temp = garage;

        if(temp.empty()) {
            cout << "Empty";
        } else {
            while(!temp.empty()) {
                cout << temp.top();
                temp.pop();

                if(!temp.empty()) // fix here also
                    cout << "_";
            }
        }
        cout << endl;
    }
}

int main() {

    On_road(2);
    On_road(5);
    On_road(10);
    On_road(9);
    On_road(22);

    Show_trucks("road");
    Show_trucks("garage");

    Enter_garage(2);

    Show_trucks("road");
    Show_trucks("garage");

    Enter_garage(10); // error
    Enter_garage(5);

    Exit_garage(2); // error
    Exit_garage(5); // correct

    Show_trucks("garage");

    return 0;
}