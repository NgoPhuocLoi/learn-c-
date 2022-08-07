#include <iostream>
#include <queue>

using namespace std;

int main(){
	priority_queue<double> values; // default implemented with vector
	values.push(1.2);
	values.push(2.8);
	values.push(8.15);
	
	cout << "Queue: ";
	while(!values.empty()){
		cout << values.top() << " ";
		values.pop();
	}
	
	cout << "\nRun";
}
