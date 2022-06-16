#include <iostream>
#include <array>

using namespace std;


int main(){
	array<int, 4> a = {1,4,5,3};
	for(int item : a){
		cout << item <<  endl;
	}
	
	for(int &item : a){
		item += 2;
	}
	
	for(int item : a){
		cout << item <<  endl;
	}
}


