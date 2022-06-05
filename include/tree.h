// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

class Tree {
 private:
  struct Node {
    char value;
    std::vector<Node*> leaf;
  };
  Node* root;
  std::string p[30] = { "" };
  void buildTree(Node*, std::vector<char>);
  void permutation(Node*, std::string);

 public:
  explicit Tree(std::vector<char> v) {
    root = new Node;
    root -> value = 'x';
    buildTree(root, v);
    permutation(root, "");
  }
  std::string gPermut(int i) const {
    return p[x - 1];
  }
};

void Tree::buildTree(Node* root, std::vector<char> link) {
  if (!link.size()) {
    return;
  }
  if (root->value != 'x') {
    for (std::vector<char>::iterator t = link.begin(); t != link.end(); ++t) {
      if (*t == root->value) {
        link.erase(t);
        break;
      }
    }
  }
  for (int temp = 0; temp < link.size(); ++temp) {
    root->leaf.push_back(new Node);
  }
  for (int temp = 0; temp < root->leaf.size(); ++temp) {
    root->leaf[temp]->value = link[temp];
  }
  for (int temp = 0; temp < root->leaf.size(); ++temp) {
    buildTree(root->leaf[temp], link);
  }
}

void Tree::permutation(Node* root, std::string symbol) {
  if (!root->symbol.size()) {
    symbol += root->value;
    int z = 0;
    while (true) {
      if (p[z] == "") {
        p[z] = symbol;
        break;
      } else {
        ++z;
      }
    }
    return;
  }
  if (root->value != 'x') {
    symbol += root->value;
  }
  for (int x = 0; x < root->symbol.size(); ++x) {
    permutation(root->symbol[x], symbol);
  }
}

#endif  // INCLUDE_TREE_H_
