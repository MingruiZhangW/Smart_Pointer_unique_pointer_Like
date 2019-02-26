#include "Smart_ptr_Ming.h"
#include <memory> // for std::unique_ptr

class Fraction;

class Resourse
{
public:
	Resourse() { std::cout << "Rescourse is created" << std::endl; }
	~Resourse() { std::cout << "Rescourse is released" << std::endl; }
};

class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << "/" << f1.m_denominator;
		return out;
	}
};


int main(void) {

	{
		//Mysmart_ptr<Resourse> ptr_test(new Resourse);

		Mysmart_ptr<int> ptr_test(new int(5));
		std::cout << std::move(ptr_test) << std::endl;
		//-> so better to able the copy operator
		if (ptr_test.isNull()) { std::cout << 1000 << std::endl; }

		//Move constructor

		//Mysmart_ptr<Resourse> ptr_test_two(std::move(ptr_test));
		
		//Move assignment operator

		//Mysmart_ptr<Resourse> ptr_test_two;
		//ptr_test_two = std::move(ptr_test);

		//deleted copy constructor
		//Mysmart_ptr<Resourse> ptr_test_two(ptr_test);

		//---------------------------------------------------------------------------------------------------
		// Create a single dynamically allocated Fraction with numerator 3 and denominator 5
		std::unique_ptr<Fraction> f1 = std::make_unique<Fraction>(3, 5);
		std::cout << *f1 << '\n';

		// Create a dynamically allocated array of Fractions of length 4
		// We can also use automatic type deduction to good effect here
		auto f2 = std::make_unique<Fraction[]>(4);
		std::cout << f2[0] << '\n';

	}
	std::cin.get();
}