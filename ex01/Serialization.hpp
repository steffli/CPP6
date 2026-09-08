#pragma once

#include <string>
#include <iostream>
#include <stdint.h>


struct Data{
	std::string name;
	int age;
};

class Serializer{

	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer& operator= (const Serializer& copy);
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};
