
#include <iostream>
#include "ThreadPool.h"
#include <functional>

void print1() { std::cout << "Nikita\n";

 std::cout << std::this_thread::get_id() << std::endl;
}

void print2() { std::cout << "Roman\n";

 std::cout << std::this_thread::get_id() << std::endl;
}

void print3() { std::cout << "Victor\n";

 std::cout << std::this_thread::get_id() << std::endl;
}



int main() { 
	
	ThreadPool obj(3);
    std::thread one([&obj]() {
      obj.submit(print1);
      
    });

    std::thread two([&obj]() {
      obj.submit(print2);
    });

    std::thread three([&obj]() {
      obj.submit(print3);
    });
    ;
    one.join();
    two.join();
    three.join();
    obj.start();
}

