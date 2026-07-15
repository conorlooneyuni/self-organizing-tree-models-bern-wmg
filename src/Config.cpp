#include "Config.hpp"

#include <string>
#include <iostream>
#include <fstream>

std::map<std::string, std::string> Config::configPairs; 

int Config::loadConfig(std::string filePath) {
    configPairs = std::map<std::string, std::string> {};
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error could not open config" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.size() < 3) {
            continue;
        }
        if (line.at(0) == '/') {
            continue;
        }
        std::cout << "Line in file " << line << std::endl;
        size_t delimPos = line.find("=");
        std::cout << delimPos << std::endl;
        if (delimPos == std::string::npos) {
            continue;
        }
        std::string key = line.substr(0, line.find("="));
        std::string value = line.substr(line.find("=") + 1);
        std::cout << key << " " << value << std::endl;
        configPairs[key] = value;
    }

    std::cout << "Retunring" << std::endl;

    file.close();

    return 0;
}

std::string Config::getValueWithDefault(std::string key, std::string defaultValue) {
    try {
        std::string value = configPairs.at(key);
        return value;
    } catch (std::out_of_range) {
        return defaultValue;
    }
}

std::string Config::getValue(std::string key) {
    return getValueWithDefault(key, "");
}