#include <iostream>
using namespace std;

int main (){
	int arr[5]={2,4,6,8,10};
	int *ptr=arr;
	
	while(*ptr!='\0'){
		cout<<*ptr<<endl;
		ptr++;
	}
}