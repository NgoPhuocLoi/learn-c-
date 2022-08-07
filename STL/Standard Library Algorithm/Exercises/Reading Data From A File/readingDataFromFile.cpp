#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>

using namespace std;

int main(){
	ifstream file("data.txt", ios::in);
	vector<int> values;
	
	copy(istream_iterator<int>(file), istream_iterator<int>(), back_inserter(values));
	
	for(int items: values){
		cout << items << " ";
	}
	
}
