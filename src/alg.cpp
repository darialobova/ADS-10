// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string perm = tree[n - 1];
  std::vector<char> g;
  for (int x = 0; x < perm.length(); x++) {
    g.push_back(perm[x]);
  }
  return g;
}
