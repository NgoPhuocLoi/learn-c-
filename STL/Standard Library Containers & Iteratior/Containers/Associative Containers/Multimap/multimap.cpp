#include <iostream>
#include <map>

using namespace std;

int main(){
	multimap<int, double, less<int>> pairs;
	// can initialize by :
	// multimap<int, double, less<int>> pairs = {{1, 1.5}, {4, 5.6}};
	
	cout << "There are currently " << pairs.count(15) 
		<< " pairs with key 15 in the multimap\n";
	
	// 3 ways to insert, 1 is C++11
	pairs.insert({15, 7.6});
	pairs.insert(make_pair(15, 11.3));
	pairs.emplace(15, 30.1);
	
	cout << "After inserted, there are " << pairs.count(15) 
		<< " pairs with key 15 in the multimap\n";
	
	// insert five value_type objects in pairs
	pairs.insert( make_pair( 30, 111.11 ) );
	pairs.insert( make_pair( 10, 22.22 ) );
	pairs.insert( make_pair( 25, 33.333 ) );
	pairs.insert( make_pair( 20, 9.345 ) );
	pairs.insert( make_pair( 5, 77.54 ) );

	cout << "\nMultimap contains:\nKey\tValue\n";
	
	for(auto item: pairs){
		// auto = pair<int, double>
		cout << item.first<< "\t" << item.second << "\n";
	}
	
	// find in multimap
	cout << "\nFind in multimap";
	auto result = pairs.find(15);
	if(result != pairs.end()){
		cout << "\nFound: " << result->second;
	}else{
		cout << "\nNot found";
	}
	
	// equal_range in multimap
	cout << "\n\nequal_range in multimap\n";
	auto p = pairs.equal_range(15);
	
	if(p.first != pairs.end()){
		cout << "Found: \n";
		for(auto i = p.first; i != p.second; ++i){
			cout << i->first <<" : " << i->second << endl;
		}
	}else{
		cout << "Not found";
	}
	

	cout << "\nRun";
}
