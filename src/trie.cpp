#include "trie.h"

Node::Node() : word_count(0), best_symbol(0), best_count(0) {}

void Node::UpdateBestSymbol(char symbol, size_t count) {
  if (count > best_count) {
    best_symbol = symbol;
    best_count = count;
  }
}

Trie::Trie() { root_ = CreateNewNode(); }

size_t Trie::GetRoot() const { return root_; }

size_t Trie::GetFakeNode() const { return fake_node_; }

size_t Trie::CreateNewNode() {
  nodes_.emplace_back();
  return nodes_.size() - 1;
}

void Trie::AddWord(const std::string &word) { AddSymbol(root_, 0, word); }

void Trie::AddSymbol(size_t node_index, size_t symbol_index,
                     const std::string &word) {
  if (symbol_index == word.size()) {
    ++nodes_[node_index].word_count;
    nodes_[node_index].UpdateBestSymbol(0, nodes_[node_index].word_count);
  } else {
    auto symbol = word[symbol_index];
    if (nodes_[node_index].children.find(symbol) ==
        nodes_[node_index].children.end()) {
      nodes_[node_index].children[symbol] = CreateNewNode();
    }
    auto child_node = nodes_[node_index].children[symbol];
    AddSymbol(child_node, symbol_index + 1, word);
    nodes_[node_index].UpdateBestSymbol(symbol, nodes_[child_node].best_count);
  }
}

size_t Trie::ApplyWord(size_t node_index, const std::string &word) {
  if (node_index == fake_node_) {
    return fake_node_;
  }

  for (auto symbol : word) {
    auto &node_children = nodes_[node_index].children;
    if (node_children.find(symbol) == node_children.end()) {
      return fake_node_;
    }
    node_index = node_children[symbol];
  }

  return node_index;
}

std::string Trie::GetBestSuffix(size_t node_index) {
  if (node_index == fake_node_) {
    return "";
  }
  std::string best_suffix;

  while (true) {
    const auto current_symbol = nodes_[node_index].best_symbol;
    if (current_symbol != 0) {
      best_suffix += current_symbol;
      node_index = nodes_[node_index].children[current_symbol];
    } else {
      break;
    }
  }

  return best_suffix;
}