#pragma once

#include <string>
#include <vector>

class Parser {
public:
  std::vector<std::string> ParseText(const std::string &text);

private:
  void PushWord(std::vector<std::string> &words, std::string &word);
};