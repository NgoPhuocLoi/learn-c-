#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	string s = "able was i ere i saw elba";
	string revserString(s);
	reverse(revserString.begin(), revserString.end());
	
	if(equal(s.begin(), s.end(), revserString.begin())){
		cout << "YES";
	}else{
		cout << "NO";
	}
	
}
