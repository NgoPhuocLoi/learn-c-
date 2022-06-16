#include <iostream>
#include <array>

using namespace std;

const size_t rows = 2;
const size_t cols = 3;

void output(const array<array<int , cols>, rows> &a){
	for(const auto &rows: a){ // typeof(rows) = array<int, cols>
		for(const int &e: rows){
			cout << e << " ";
		}
		cout << endl;
	}
}

void output2(const array<array<int , cols>, rows> &a){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	array<array<int, cols>, rows> arr1 = {1,2,3,4,5,6};
	array<array<int, cols>, rows> arr2 = {1,2,3,4,5,0};
	
	output(arr1);
}


