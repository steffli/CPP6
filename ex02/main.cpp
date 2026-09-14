#include  "A.hpp"
#include  "B.hpp"
#include  "C.hpp"
#include  "Base.hpp"

Base* generate(void){
    int random_N = rand();
    if (random_N % 3 == 0)
        return new A;
    else if (random_N % 3 == 1)
        return new B;
    else
        return new C;
}

void identify(Base *p){
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p){
    try{
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(std::exception &e){
        std::cout << "Could not cast A. Error: " << e.what() << std::endl;
    }
    try{
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch(std::exception &e){
        std::cout << "Could not cast B. Error: " << e.what() << std::endl;
    }
    try{
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch(std::exception &e){
        std::cout << "Could not cast C. Error: " << e.what() << std::endl;
    }
}

int main(void)
{
    srand(time(NULL));
    for (int i = 0; i < 9; i++)
    {
        std::cout << "--- Round " << i << " ---" << std::endl;
        Base *b = generate();
        Base &ref = *b;
        std::cout << "pointer identify: ";
        identify(b);
        std::cout << "reference identify:" << std::endl;
        identify(ref);
        delete(b);
    }
    return 0;
}