#include <iostream>
#include <stdexcept>
#include <initializer_list>

#ifndef ARRAY
#define ARRAY 1

class Array {
	friend std::istream &operator>>(std::istream &, Array &);
	friend std::ostream &operator<<(std::ostream &, Array &);
	public:
		explicit Array(int i = 10); // default constructor
		Array(const Array &); //copy constructor
		Array(std::initializer_list<int>); // list initialization
		~Array(); // destructor
		unsigned int getSize() const;
		
		const Array& operator=(const Array &); // asignment operator
		bool operator==(const Array &) const;	// equality operator
		bool operator!=(const Array &) const; //inequality operator
		int& operator[](int);
		int operator[](int) const;

	private:
		unsigned int size;
		int *ptr;
};

// Definitions
Array::Array(int arraySize)
	:size(arraySize > 0 ? arraySize :
		throw std::invalid_argument("Array size must be greater than 0!")),
	 ptr(new int[size])
{
	for(int i = 0; i < size; i++){
		ptr[i] = 0;
	}
}

Array::Array(const Array &arrToCopy)
	:size(arrToCopy.size), ptr(new int[size])
{
	for(int i = 0; i < size; i++){
		ptr[i] = arrToCopy.ptr[i];
	}
}

Array::Array(std::initializer_list<int > list)
	:size(list.size()), ptr(new int[size])
{
	unsigned int i = 0;
	for(int item: list){
		ptr[i++] = item;
	}
}

Array::~Array(){
	delete [] ptr;
}

unsigned int Array::getSize() const {
	return size;
}

const Array& Array::operator=(const Array &right){
	if(&right != this) //avoid sefl-asignment
	{
		delete [] ptr;
		size = right.size;
		ptr = new int[right.size];
		for(int i = 0; i < size; i++){
			ptr[i] = right.ptr[i];
		}
	}
	return *this;
}

bool Array::operator==(const Array &right) const{
	if(size != right.size)
		return false;
	for(int i = 0; i < size; i++){
		if(ptr[i] != right.ptr[i])
			return false;
	}
	return true;
}

bool Array::operator!=(const Array &right) const{
	return !(*this == right);
}

int& Array::operator[](int idx){
	std::cout << "not const\n";
	if(idx <0 || idx >= size)
		throw std::out_of_range("Subscript out of range!");
	
	return ptr[idx];
}

int Array::operator[](int idx) const {
	std::cout << "const\n";
	if(idx <0 || idx >= size)
		throw std::out_of_range("Subscript out of range!");
	
	return ptr[idx];
}

std::istream& operator>>(std::istream &input, Array &a){
	for(int i = 0; i < a.size; i++){
		input >> a.ptr[i];
	}
	return input;
}

std::ostream &operator<<(std::ostream &output, Array &a){
	for(int i = 0; i < a.size; i++){
		output << a.ptr[i] << "  ";
	}
	output << std::endl;
	return output;
}

#endif



