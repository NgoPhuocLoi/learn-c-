#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

template <typename T> void pushElements(T &stackRef){
	for(int i = 0; i < 10; i++){
		stackRef.push(i);
		cout << stackRef.top() <<" ";
	}
}

template <typename T> void popElements(T &stackRef){
	while(!stackRef.empty()){
		cout << stackRef.top() << " ";
		stackRef.pop();
	}
}

int main(){
	stack<int> intDequeStack; // by default
	stack<int, vector<int>> intVectorStack; // stack with underlying vector
	stack<int, list<int>> intListStack; // stack with underlying list
	
	cout <<"Pushing into intDequeStack: ";
	pushElements(intDequeStack);
	cout <<"\nPushing into intVectorStack: ";
	pushElements(intVectorStack);
	cout <<"\nPushing into intListStack: ";
	pushElements(intListStack);
	
	intDequeStack.emplace(111);
	
	cout <<"\n\nPopping from intDequeStack: ";
	popElements(intDequeStack);
	cout <<"\nPopping from intVectorStack: ";
	popElements(intVectorStack);
	cout <<"\nPopping from intListStack: ";
	popElements(intListStack);
	cout << "\nRun";
}
