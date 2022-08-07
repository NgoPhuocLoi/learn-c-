#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void inputVector(vector<int> &);
void outputVector(const vector<int> &);

int main() {
	vector<int> a(3);
	vector<int> b(10);
	inputVector(a);
	outputVector(a);
	try{
		cout << "Attempt to display a.at(5)\n";
		cout << a.at(5);
	}catch(out_of_range &a){
		cerr << "Error\n" << a.what() ;
	}
	
	a.push_back(123);
	outputVector(a);
	cout <<  "\nRun";
}

void inputVector(vector<int> &a){
	for(int &item : a){
		cin >> item;
	}
}

void outputVector(const vector<int> &a){
	for(int item : a){
		cout << item << " ";
	}
	cout << endl;
}
