#include <iostream>
#include <string>

using namespace std;

int main(){
	string s1("Happy ");
	string s2("Birthday");
	s1 += s2;
	string s3;
	cout << s1.substr(2,5);
}
