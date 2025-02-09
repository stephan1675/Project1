#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <memory>
#include <chrono>
#include <thread>

#include "Func1.hpp"


int main(){

std::string prices = "prices.txt";
std::string data = "data2.txt";
std::string tempData = "tempData.txt";

//read in the whole text and save as one string
std::string text;
readIn(text, "Data1.txt");
std::cout<< text; //show the text

//read in the file and saves it line by line (lines.push_back(line); to add line to lines)
std::vector<std::string> lines; //dynamic vector
int count= saveLines( lines, "Data1.txt");

printVector(lines);

lines.push_back("Ich schreib was Neues rein");
std::cout<<saveVector(lines, data)<<" lines have been saved\n";



std::string command = "lsb_release -a"; //what command to exec
std::string bitcoinPrice = "curl -s \"https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=usd\" | jq '.bitcoin.usd'";
std::cout<<execRead(command, lines)<<" lines have been retured from the command "<<command<<"\n";
printVector(lines);
//bitcoinprice on coingecko and saving it in loop 1 hour
while (1)
{
    


std::cout<<execRead(bitcoinPrice, lines)<<" lines have been retured from the command "<<command<<"\n";
printVector(lines);
std::cout<<saveVectorA(lines, prices)<<" lines have been saved\n";

std::this_thread::sleep_for(std::chrono::hours(1));
}

    return 0;
}