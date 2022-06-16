#include <iostream>
#include <array>
#include <algorithm> // contains sort and binary_search

using namespace std;


int main(){
	const int size = 4;
	array<string, size> a= {"red", "blue", "yellow", "green"};
	
	for(string item: a){
		cout << item << " " ;
	}
	cout << endl;
	
	sort(a.begin(), a.end()); // a.begin() = &a[0] ; a.end() = &a[size]
	for(string item: a){
		cout << item << " " ;
	}
	cout << endl;
	
	bool found = binary_search(a.begin(), a.end(), "reda");
	
	cout << (found ? "YES" : "NO");
	
	int x[5] = {9,6,3,10,2};
	for(int item : x){
		cout << item << " ";
	}
	sort(begin(x), end(x));
	for(int item : x){
		cout << item << " ";
	}
}


