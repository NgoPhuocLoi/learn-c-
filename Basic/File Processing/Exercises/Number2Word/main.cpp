#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void output(ostream &output, vector<char> A){
  for(int i = 0; i < A.size(); i++){
    output << A.at(i);
  }
  output << endl;
}


vector<vector<char> > sets = {
  {'0'},
  {'1'},
  {'A', 'B', 'C'},
  {'D', 'E', 'F'},
  {'G', 'H', 'I'},
  {'J', 'K', 'L'},
  {'M', 'N', 'O'},
  {'P', 'Q', 'R', 'S'},
  {'T', 'U', 'V'},
  {'W', 'X', 'Y', 'Z'}
};

vector<int> num2vector(int n){
  vector<int> list;
  while(n!= 0){
    list.push_back(n%10);
    n /= 10;
  }
  return list;
}

void Num2Word(int i, vector<int> list, ostream &outputStream){
  static int count = 1;
  static vector<char> A;
  A.resize(list.size());
  int k = list[list.size() - i - 1];
  for(int j = 0; j < sets[k].size(); j++){
    A[i] = sets[k][j];
    if(i == list.size() -1){
      outputStream <<count++ << " : ";
      output(outputStream, A);
    }else{
      Num2Word(i+1, list, outputStream);
    }
  }
}

int main(){
  ofstream outputFile("phoneNum2Word.txt", ios::out);
  int n;
  cout << "Enter your phone number ( 7 digits ): ";
  cin >> n;
  vector<int> list = num2vector(n);
  Num2Word(0, list, outputFile);
}
