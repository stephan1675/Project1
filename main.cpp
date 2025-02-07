#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <memory>

#include "Func1.hpp"


int main(){

//read in the whole text and save as one string
std::string text;
readIn(text, "Data1.txt");
std::cout<< text; //show the text

//read in the file and saves it line by line (lines.push_back(line); to add line to lines)
std::vector<std::string> lines; //dynamic vector
int count= saveLines( lines, "Data1.txt");

printVector(lines);

lines.push_back("Ich schreib was Neues rein");
std::cout<<saveVector(lines, "newData")<<" lines have been saved\n";



std::string command = "lsb_release -a"; //what command to exec
std::cout<<execRead(command, lines)<<" lines have been retured for the command "<<command<<"\n";

printVector(lines);


    return 0;
}