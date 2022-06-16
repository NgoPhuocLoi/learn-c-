#include <iostream>
#include <string>
class CreateAndDestroy{
	public:
		CreateAndDestroy(int id, std::string msg) // constructor
			: id(id), message(msg)
		{
			std::cout << "Object " << id << " constructor runs " << message << std::endl;
		}
		
		~CreateAndDestroy() // destructor
		{
			std::cout << "Object " << id << " destructor runs " << message << std::endl;
		}	
	private:
		int id;
		std::string message;
};
