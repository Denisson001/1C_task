#include "parser.h"

std::vector<std::string> Parser::ParseText(const std::string &text) {
  std::vector<std::string> words;
  std::string current_word;

  for (char symbol : text) {
    if (symbol == ' ') {
      PushWord(words, current_word);
    } else {
      current_word += symbol;
    }
  }
  PushWord(words, current_word);

  return words;
}

void Parser::PushWord(std::vector<std::string> &words, std::string &word) {
  if (!word.empty()) {
    words.emplace_back(std::move(word));
  }
}