#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <memory>
#include <chrono>
#include <thread>

#include "Func1.hpp"

/**
 * @brief This program enables a conversation inbetween chatbots
 * 
 * @return int 
 */
int main(){

    std::string conversation = "conversation.txt";
    std::string theme = "happy";
    std::string charClass = "warlock";
    std::string api_key = std::getenv("TOGETHER_API_KEY") ? std::getenv("TOGETHER_API_KEY") : "";
    std::string user_message = "Das ist aber schön zu hören";
    std::string command = "curl -X POST \"https://api.together.xyz/v1/chat/completions\" "
        "-H \"Authorization: Bearer " + api_key + "\" "
        "-H \"Content-Type: application/json\" "
        "-d '{"
        "\"model\": \"meta-llama/Llama-3.3-70B-Instruct-Turbo-Free\","
        "\"messages\": [{\"role\": \"user\", \"content\": \"" + user_message + "\"}]"
        "}'| jq -r '.choices[0].message.content'";

    std::vector<std::string>chat;
    
    int many=0;

//set the theme of the conversation

//set the charakters

//start the conversation

many=execRead(command, chat);
many=saveVectorA(chat, conversation);


}