#include <string>

using std::string;

#ifndef PERSON
#define PERSON 1


class Person{
  public:
    Person(int = 0, const string & = "unassigned", const string & = "",int = 0);
    const Person& operator=(const Person &);

    void setId(int);
    int getId() const;

    void setFirstName(const string &);
    string getFirstName()const;

    void setLastName(const string &);
    string getLastName()const;

    void setAge(int);
    int getAge() const;

  private:
    char lastName[15], firstName[10];
    int id, age;
};

// definnitions
Person::Person(int idValue, const string &first, const string &last, int age)
  :id(idValue), age(age)
{
  setFirstName(first);
  setLastName(last);
}

const Person& Person::operator=(const Person &right){
  if(&right != this){
    this->setId(right.getId());
    this->setFirstName(right.getFirstName());
    this->setLastName(right.getLastName());
    this->setAge(right.getAge());
  }
  return *this;
}

void Person::setId(int idValue){
  id = idValue;
}
int Person::getId() const {
  return id;
}

void Person::setFirstName(const string &first){
  int length = first.size();
  length = length < 10 ? length : 9;
  first.copy(firstName, length);
  firstName[length]= '\0';
}
string Person::getFirstName() const {
  return firstName;
}

void Person::setLastName(const string &last){
  int length = last.size();
  length = length < 10 ? length : 9;
  last.copy(lastName, length);
  lastName[length] = '\0';
}
string Person::getLastName() const {
  return lastName;
}

void Person::setAge(int ageValue){
  age = ageValue;
}
int Person::getAge() const {
  return age;
}

#endif
