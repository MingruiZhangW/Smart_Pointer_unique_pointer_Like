#include "Smart_ptr_Ming.h"

class Resourse
{
public:
	Resourse() { std::cout << "Rescourse is created" << std::endl; }
	~Resourse() { std::cout << "Rescourse is released" << std::endl; }
};


int main(void) {

	{
		Mysmart_ptr<Resourse> ptr_test(new Resourse);

		ptr_test = std::move(ptr_test);

		//Move constructor

		//Mysmart_ptr<Resourse> ptr_test_two(std::move(ptr_test));
		
		//Move assignment operator

		//Mysmart_ptr<Resourse> ptr_test_two;
		//ptr_test_two = std::move(ptr_test);

		//deleted copy constructor
		//Mysmart_ptr<Resourse> ptr_test_two(ptr_test);
	}
	std::cin.get();
}