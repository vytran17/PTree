// Copyright Vy Tran 2024

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "PTree.hpp"

int main(int argc, char* argv[]) {
  double L = 0.0;
  int N = 0;

  L = atol(argv[1]);
  N = atoi(argv[2]);

  PTree tree(L, N);
  return 0;
}
