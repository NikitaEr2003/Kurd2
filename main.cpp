
#include <iostream>
#include "ThreadPool.h"
#include <functional>

void print1() { std::cout << "Nikita\n"; }

void print2() { std::cout << "Roman\n"; }

void print3() { std::cout << "Victor\n"; }



int main() { 
	
	ThreadPool obj(3);
    obj.submit(print1);
    obj.submit(print2);
    obj.submit(print3);
    obj.start();
}

