#pragma once

#include <map>
#include <string>

class Config {
public:
  static int loadConfig(std::string file);
  static std::string getValueWithDefault(std::string key, std::string defaultValue);
  static std::string getValue(std::string key);
private:
  static std::map<std::string, std::string> configPairs;
};
