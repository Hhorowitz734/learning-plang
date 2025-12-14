#include <iostream>
#include "token.hpp"
#include "lexer.hpp"

int main() {

  Lexer lexer{"123 123 123 + - +"};
  std::vector<Token> tokens = lexer.lex();

  for (auto& token : tokens) {
    std::cout << token.to_string() << std::endl;
  }

  


  return 0;
}
