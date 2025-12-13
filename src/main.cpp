#include <iostream>
#include "token.hpp"
#include "lexer.hpp"

int main() {
  Token tok{
    TokenKind::Number,
      "123",
      SourceLoc{1, 1, 0},
      SourceLoc{1, 4, 3}
  };

  Lexer lexer{"123 123 123"};
  std::vector<Token> tokens = lexer.lex();

  for (auto& token : tokens) {
    std::cout << token.to_string() << std::endl;
  }

  


  return 0;
}
