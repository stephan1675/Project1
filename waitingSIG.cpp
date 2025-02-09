#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <memory>
#include <chrono>
#include <thread>

#include "Func1.hpp"


int main(int argc, char* argv[]){
    for (int i = 1; i < argc; i++) //wird nicht wirlich gebraucht, da signal in eine schlaufe fallen wird, somit ist mehr als ein
                                    //argument zwecklos...
    {
        std::string arg=argv[i];
        waitForSignal(arg);
    }
    


}