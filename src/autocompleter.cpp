#include "autocompleter.h"

Autocompleter::Autocompleter() {
  last_trie_position_ = trie_.GetFakeNode();
}

void Autocompleter::AddWord(const std::string &word) {
  trie_.AddWord(word);
}

std::string Autocompleter::CompleteWord(const std::string &word) {
  last_trie_position_ = trie_.GetRoot();
  last_word_ = "";
  return AppendWord(word);
}

std::string Autocompleter::AppendWord(const std::string &word) {
  last_trie_position_ = trie_.ApplyWord(last_trie_position_, word);
  last_word_ += word;
  return last_word_ + trie_.GetBestSuffix(last_trie_position_);
}