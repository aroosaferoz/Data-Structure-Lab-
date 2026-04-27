#include <iostream>
using namespace std;

int main() {
    int tickets[10] = {13579, 26791, 26792, 33445, 55555,
                       62483, 77777, 79422, 85647, 93121};
                       
    cout << "Lottery Ticket Program (Linear Search) \n";
    int winningNumber;
    cout << "Enter this week's winning 5-digit number: ";
    cin >> winningNumber;

    bool found = false;

    for (int i = 0; i < 10; i++) {
        if (tickets[i] == winningNumber) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Congratulations! You have a winning ticket";
    } else {
        cout << "Sorry, no match. Better luck next time!";
    }

    return 0;
}