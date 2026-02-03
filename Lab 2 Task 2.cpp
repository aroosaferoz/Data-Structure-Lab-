#include <iostream>
using namespace std;

void swapFunction(int *a,int *b){
	int tem=*a; //tem=temporary variable for swapping
	*a=*b; 
	*b=tem;
}

int main (){
    int x=20;
    int y=30;
    
    cout<<"Before Swapping:"<<endl;
    cout<<"x="<<x<<" y="<<y<<endl;
    
    swapFunction(&x,&y);
    
    cout<<"After Swapping:"<<endl;
    cout<<"x="<<x<<" y="<<y<<endl;
    
    return 0;
}