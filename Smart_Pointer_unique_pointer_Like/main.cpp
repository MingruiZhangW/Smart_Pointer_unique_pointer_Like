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
	}
	std::cin.get();
}