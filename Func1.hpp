#include <iostream>

/**
 * @brief reads in a text as a complete string
 * 
 * @param text where to store
 * @param readInFile what to store
 */
void readIn(std::string& text, const std::string& readInFile);


/**
 * @brief This function reads in lines and saves them line per line in a string vector
 * 
 * @param lines where to store
 * @param readInFile what to store
 * @return int how many lines or -1 if error
 */
int saveLines( std::vector<std::string>& lines, const std::string& readInFile);


/**
 * @brief This function saves a dynamic vector line by line to a file
 * 
 * @param lines     what to save    
 * @param where     where to save
 * @return int      how many elements were saved
 */
int saveVector(std::vector<std::string>& lines, const std::string& where);


/**
 * @brief This function enables to work with the terminal. It also saves the output from the system into a dynamic vector
 * 
 * @param command   What to excecute
 * @param lines     Dynamic vector to save the return value from the system
 * @return int      How many lines did the system return
 */
int execRead(std::string& command, std::vector<std::string>& lines);


/**
 * @brief This function print all elements from the dynamic vector
 * 
 * @param dynamic the vector
 */
void printVector (std::vector<std::string> dynamic);


/**
 * @brief This function saves a dynamic vector line by line to a file in appendix mode
 * 
 * @param lines     what to save    
 * @param where     where to save
 * @return int      how many elements were saved
 */
int saveVectorA(std::vector<std::string>& lines, const std::string& where);
