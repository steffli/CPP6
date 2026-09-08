#include "Serialization.hpp"

int main(void)
{
	Data d;
	d.name = "Stephan";
	d.age = 42;

	uintptr_t raw = Serializer::serialize(&d);
	Data *back = Serializer::deserialize(raw);

	std::cout << "original     : " << &d << std::endl;
	std::cout << "serialized   : " << raw << std::endl;
	std::cout << "deserialized : " << back << std::endl;
	std::cout << "same pointer : " << (back == &d ? "yes" : "no") << std::endl;
	std::cout << "name via ptr : " << back->name << std::endl;
	std::cout << "age via ptr  : " << back->age << std::endl;

	// modify through the deserialized pointer
	back->age = 99;
	std::cout << "\nage after back->age = 99 : " << d.age << std::endl;

	// heap round-trip
	Data *heap = new Data();
	heap->name = "Heap";
	heap->age = 7;
	Data *heapBack = Serializer::deserialize(Serializer::serialize(heap));
	std::cout << "\nheap orig : " << heap << std::endl;
	std::cout << "heap back : " << heapBack << std::endl;
	std::cout << "same      : " << (heapBack == heap ? "yes" : "no") << std::endl;
	delete heapBack;

	// NULL round-trip
	Data *nullBack = Serializer::deserialize(Serializer::serialize(NULL));
	std::cout << "\nserialize(NULL)   : " << Serializer::serialize(NULL) << std::endl;
	std::cout << "deserialize back  : " << nullBack << std::endl;

	// two different objects give different raw values
	Data a, b;
	std::cout << "\n&a          : " << &a << std::endl;
	std::cout << "&b          : " << &b << std::endl;
	std::cout << "raw of a    : " << Serializer::serialize(&a) << std::endl;
	std::cout << "raw of b    : " << Serializer::serialize(&b) << std::endl;
	std::cout << "same raw    : " << (Serializer::serialize(&a) == Serializer::serialize(&b) ? "yes" : "no") << std::endl;

	return 0;
}
