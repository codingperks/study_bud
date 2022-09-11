//
// Created by Ryan Perkins on 11/09/2022.
//

#include "utilities.h"
#include "requirements.h"

int integerHandling(int input, int target = 0, const std::string& status = "", signed int increment = 0){
    while (std::cin.fail() || input > target || input <= 0) { // Integer error handling
        std::cout << "Error, selection out of range!" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << status;
        std::cin >> input;
    }
    return input + increment;
}

bool forbiddenChar(const std::string& entry){ // return true if no forbidden characters found in string, return false otherwise
    if (entry.find('<') != std::string::npos) {
        std::cout << "Error: filename contains forbidden character '<'\n";
        return true;
    }
    if (entry.find('>') != std::string::npos) {
        std::cout << "Error: filename contains forbidden character '>'\n";
        return true;
    }
    if (entry.find(':') != std::string::npos) {
        std::cout << "Error: filename contains forbidden character ':'\n";
        return true;
    }
    if (entry.find('\"') != std::string::npos) {
        std::cout << "Error: filename contains forbidden character '\"'\n";
        return true;
    }
    if (entry.find('/') != std::string::npos) {
        std::cout << "Error: filename contains forbidden character '/'\n";
        return true;
    }
    if (entry.find('\\') != std::string::npos) {
        std::cout << "Error: filename contains forbidden character '\\'\n";
        return true;
    }
    if (entry.find('|') != std::string::npos) {
        std::cout << "Error: filename contains forbidden character '|'\n";
        return true;
    }
    if (entry.find('?') != std::string::npos) {
        std::cout << "Error: filename contains forbidden character '?'\n";
        return true;
    }
    if (entry.find('*') != std::string::npos) {
        std::cout << "Error: filename contains forbidden character '*'\n";
        return true;
    }
        return false;
}

bool checkStringLength(const std::string& entry, int target){
    if (entry.length() <= target){
        return false;
    }
    else{
        std::cout << "Filename exceeds 31 characters, please shorten.\n";
        return true;
    }
}