#pragma once

#include <map>
#include <vector>

struct Node {
  Node();
  void UpdateBestSymbol(char symbol, size_t count);

  std::map<char, size_t> children;
  size_t word_count;

  char best_symbol;
  size_t best_count;
};

class Trie {
public:
  Trie();
  void AddWord(const std::string &word);
  size_t GetRoot() const;
  size_t GetFakeNode() const;
  size_t ApplyWord(size_t node_index, const std::string& word);
  std::string GetBestSuffix(size_t node_index);

private:
  void AddSymbol(size_t node_index, size_t symbol_index, const std::string &word);
  size_t CreateNewNode();

private:
  static const size_t fake_node_ = -1;
  size_t root_;
  std::vector<Node> nodes_;
};