#include <iostream>
using namespace std;

struct Product{
	string name;
	int code;
	float price;
};

int main(){
	int n;
	cout << "Please enter number of products: \n";
	cin >> n;
	
	Product* products = new Product[n];
	
	for (int i=0 ; i<n ; i++){
		
		cout << "---Enter details of product " << i+1 << "---" << endl;
		
		cout << "Enter name:";
		cin >> products[i].name;
		
		cout << "Enter code:";
		cin >> products[i].code;
		
		cout << "Enter price:";
		cin >> products[i].price;
		cout << " \n";
	}
	
	cout << "\n---<><>< Products Details ><><>---\n";
    for (int i = 0; i < n; i++) {
    	
        cout << "\nProduct " << i + 1 << endl;
        
        cout << "Name: " << products[i].name << endl;
        cout << "Code: " << products[i].code << endl;
        cout << "Price: " << products[i].price << endl;
    }

    delete[] products;
}