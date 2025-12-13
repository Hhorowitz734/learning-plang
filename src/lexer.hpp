#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string_view>
#include "token.hpp"

class Lexer {

public:

  explicit Lexer(std::string_view input);

  std::vector<Token> lex();


private:

  // Code control
  void skip_whitespace();
  bool is_eof() const;
  char peek() const;
  char advance();
  
  // Lexing cases 
  Token lex_number();
  
  // Input + location
  std::string_view input;
  SourceLoc curr_loc;

};



#endif
