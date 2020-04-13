#pragma once

#include "trie.h"

class Autocompleter {
public:
  Autocompleter();
  void AddWord(const std::string& word);
  std::string CompleteWord(const std::string& word);
  std::string AppendWord(const std::string& word);

private:
  Trie trie_;
  size_t last_trie_position_;
  std::string last_word_;
};