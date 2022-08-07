#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool myPred(char c){
	return c != '.' && c != '(' && c != ')'&& 
			c != '!' && c != ':' && c != ';' && c != ':' && c != ',';
}

int main(){
	string originalString = "able() !!was i.. ere i;; s,,aw elba";
	string newString;

	copy_if(originalString.begin(), originalString.end(), back_inserter(newString), myPred);

	string revserString(newString);
	reverse(revserString.begin(), revserString.end());
	cout << "new string: " << newString << endl;
	if(equal(newString.begin(), newString.end(), revserString.begin())){
		cout << "YES";
	}else{
		cout << "NO";
	}
	
}
