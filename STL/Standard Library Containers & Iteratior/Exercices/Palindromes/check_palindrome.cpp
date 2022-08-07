#include <iostream>
#include <vector>

using namespace std;

template <typename T> bool isPalindrome(vector<T> input){
	int n = input.size();
	for(int i = 0; i < n / 2; i++){
		if(input[i] != input[n - i - 1])
			return false;
	}
	return true;
}

int main(){
	vector<int> a = {1,3,2,1};
	cout << isPalindrome(a);
	cout << "\nRun";
}
