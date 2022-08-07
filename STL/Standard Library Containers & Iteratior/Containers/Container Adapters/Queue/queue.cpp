#include <iostream>
#include <queue>

using namespace std;

int main(){
	queue<double> values; // default implemented with deque (can use list)
	values.push(1.2);
	values.push(2.8);
	values.push(8.15);
	
	cout << "Queue: ";
	while(!values.empty()){
		cout << values.front() << " ";
		values.pop();
	}
	
	cout << "\nRun";
}
