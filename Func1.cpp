#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <memory>


/**
 * @brief reads in a text as a complete string
 * 
 * @param text where to store
 * @param readInFile what to store
 */

void readIn(std::string& text, const std::string& readInFile){

    std::ifstream file(readInFile);
    if (!file)
    {
        std::cerr << "Fehler beim Öffnen der Datei:\n" << readInFile << std::endl;
        return;
    }
    
    std::string line;
    while (std::getline(file, line))
    {
        text += line + "\n"; //for each line \n
    }
}

/**
 * @brief This function reads in lines and saves them line per line in a string vector
 * 
 * @param lines where to store
 * @param readInFile what to store
 * @return int how many lines or -1 if error
 */
int saveLines( std::vector<std::string>& lines, const std::string& readInFile){

    int count=0;
    std::ifstream file(readInFile);
    if(!file){
        std::cerr << "Fehler beim Öffnen der Datei:\n"  << readInFile <<std::endl;
        return -1;
    }
    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
        count++;
    }
    return count;
    
}


/**
 * @brief This function saves a dynamic vector line by line to a file
 * 
 * @param lines     what to save    
 * @param where     where to save
 * @return int      how many elements were saved
 */
int saveVector(std::vector<std::string>& lines, const std::string& where){
    int count=0;
    std::ofstream file(where);
    if(!file){
        std::cerr << "Fehler beim Öffnen der Datei:\n"  << where <<std::endl;
        return -1;
    }
    for (const auto& line : lines)
    {
        file << line << '\n';
        count++;
    }
    return count;

}


/**
 * @brief This function enables to work with the terminal. It also saves the output from the system into a dynamic vector
 * 
 * @param command   What to excecute
 * @param lines     Dynamic vector to save the return value from the system
 * @return int      How many lines did the system return
 */
int execRead(std::string& command, std::vector<std::string>& lines){

lines.clear();

std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(),"r"),pclose); //smart pointer pipe & command excec
    if (!pipe) {
        std::cerr << "Fehler: Konnte den Befehl nicht ausführen!\n";
        return -1;
    }

    char buffer[128]; //temp buffer for the lines
    int count = 0;
    while (fgets(buffer, sizeof(buffer), pipe.get())) 
    {
        lines.push_back(buffer);  // add line to the dynamic vector
        count++;
    }

    return count; 
}

/**
 * @brief This function print all elements from the dynamic vector
 * 
 * @param dynamic the vector
 */
void printVector (std::vector<std::string> dynamic){

    for (const auto& line: dynamic) //show each return line
{
    std::cout<<line<< std::endl;
}
}
