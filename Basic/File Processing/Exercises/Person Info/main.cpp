#include "Person.h"
#include <iostream>
#include <fstream>
#include <iomanip>

enum Choices {LIST = 1, NEW, UPDATE, DELETE, RESET, END};

using namespace std;
int getChoice();
void initFile(fstream &);
void outputPerson(const Person &);
Person findPerson(fstream &, int);
void listCurrentPeople(fstream &);
void createPerson(fstream &);
void updatePerson(fstream &);
void deletePerson(fstream &);

int main(){
  fstream inOutInfoFile("nameage.dat", ios::out |ios::in | ios::binary);
  int choice = getChoice();
  while(choice != END){
    switch(choice){
      case LIST:
        listCurrentPeople(inOutInfoFile);
        break;
      case NEW:
        createPerson(inOutInfoFile);
        break;
      case UPDATE:
        updatePerson(inOutInfoFile);
        break;
      case DELETE:
        deletePerson(inOutInfoFile);
        break;
      case RESET:
        initFile(inOutInfoFile);
        cout << "File reseted!\n";
        break;
      default:
        cerr << "Invalid choice. Try again!\n";
    }
    choice = getChoice();
  }
  cout << "\nRun";
}

void initFile(fstream &outputFile){
  outputFile.clear();
  outputFile.seekp(0);
  Person person;
  for(int i = 0; i < 100; i++){
    outputFile.write(reinterpret_cast<const char*>(&person), sizeof(Person));
  }
}

void outputPerson(const Person &person){
  cout << person.getId() << " "
      << person.getFirstName() << " "
      << person.getLastName() << " "
      << person.getAge() << endl;
}
Person findPerson(fstream &file, int id){
  Person person;
  file.clear();
  file.seekg((id - 1)*sizeof(Person));
  file.read(reinterpret_cast<char*>(&person), sizeof(Person));
  return person;  
}

int getChoice(){
  int choice;
  cout << "\nEnter your choice:\n"
      << "1. List current person in list\n"
      << "2. Create new person\n"
      << "3. Update a person\n"
      << "4. Delete a person\n"
      << "5. Reset the list\n"
      << "6. End program\n? ";
  cin >> choice;
  return choice;
}
void listCurrentPeople(fstream &inputFile){
  inputFile.clear();
  inputFile.seekg(0);
  Person person;
  bool hasPeople = false;
  while(!inputFile.eof()){
    inputFile.read(reinterpret_cast<char*>(&person), sizeof(Person));
    if(person.getAge() != 0){
      outputPerson(person);
      hasPeople = true;
    }
  }
  if(!hasPeople)
      cout << "No has any people in list\n";
}
void createPerson(fstream &outputFile){
  int id, age;
  string firstName, lastName;
  Person person;

  cout << "Enter person's id (1 - 100): ";
  cin >> id;
  person = findPerson(outputFile, id);
  if(person.getId() == 0){
    cout << "Enter firstname, lastname, age of person:\n? ";
    cin >> setw(10) >> firstName >> setw(15) >> lastName >> age;
    person.setId(id);
    person.setFirstName(firstName);
    person.setLastName(lastName);
    person.setAge(age);

    outputFile.seekp((id-1)*sizeof(Person));
    outputFile.write(reinterpret_cast<const char*>(&person), sizeof(Person));
  }else{
    cerr << "Person'id is exist. Try again!\n";
  }
}
void updatePerson(fstream &file){
  int id;
  cout << "Enter the person's id to update: ";
  cin >> id;
  Person person(20, "Loi", "Ngo", 18) ;
  Person person2;
  
  person = findPerson(file, id);
  if(person.getId() != 0){
    int newAge;
    string newFirst, newLast;

    cout << "Enter new firstname, lastname, age to update (enter -1 to unchange):\n? ";
    cin >> newFirst >> newLast >> newAge;

    if(newAge != -1){
      person.setAge(newAge);
    }
    if(newFirst.compare("-1") != 0){
      person.setFirstName(newFirst);
    }
    if(newLast.compare("-1") != 0){
      person.setLastName(newLast);
    }

    file.seekp((id -1)* sizeof(Person));
    file.write(reinterpret_cast<const char*>(&person), sizeof(Person));
    
  }else{
    cerr << "Person not found!\n";
  }
}
void deletePerson(fstream &file){
  int id;
  cout << "Enter the person's id to delete: ";
  cin >> id;
  Person person = findPerson(file, id);
  if(person.getId() != 0){
    Person blankPerson;
    file.clear();
    file.seekp((id -1)*sizeof(Person));
    file.write(reinterpret_cast<const char*>(&blankPerson), sizeof(Person));
    cout << "Deleted successfully!\n";
  }else{
    cerr << "Person not found!\n";
  }
}
