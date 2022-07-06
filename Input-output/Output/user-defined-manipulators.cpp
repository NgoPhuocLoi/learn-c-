#include <iostream>
#include <iomanip>
using namespace std;

ostream& bell(ostream& output){
    return output << '\a';
}

ostream& carriageReturn(ostream& output){
    return output << '\r';
}

ostream& endLine(ostream& output){
    return output << '\n' << flush;
}

ostream& tab(ostream& output){
    return output << '\t';
}

int main(){
    cout << "Testing the tab manipulator: " << endLine
        << 'a' << tab << 'b' <<tab << 'c' << endLine;

    cout << "Tesing carriageReturn and bell manipulators: "
        << endLine << "...........";

    cout << bell;

    cout << carriageReturn << "===============\n\n";

    cout << 9.991 << endl;
    cout << showpoint << 9.991 << endl;

    int number = 123;
    cout.fill('.');
    cout << setw(10) << number << endl;
    cout << left << setw(10) << number << endl;
    cout << showpos << internal << setw(10) << number;
}
