#include <iostream>
#include <map>

using namespace std;

int main(){
	map<int, double, less<int>> pairs;
	
	// insert eight value_type objects in pairs
	pairs.insert( make_pair( 15, 2.7 ) );
	pairs.insert( make_pair( 30, 111.11 ) );
	pairs.insert( make_pair( 5, 1010.1 ) );
	pairs.insert( make_pair( 10, 22.22 ) );
	pairs.insert( make_pair( 25, 33.333 ) );
	pairs.insert( make_pair( 5, 77.54 ) ); // dup ignored
	pairs.insert( make_pair( 20, 9.345 ) );
	pairs.insert( make_pair( 15, 99.3 ) ); // dup ignored
	
	cout << "pairs contains:\nKey\tValue\n";
	for(auto item: pairs){
		cout << item.first <<"\t" << item.second << endl;
	}
	
	pairs[25] = 999.99;
	pairs[40] = 12.345;
	
	cout << "\nAfter subscript opearations, pairs contains:\nKey\tValue\n";
	for(auto item: pairs){
		cout << item.first <<"\t" << item.second << endl;
	}
	
	
}
