#include "lexer.hpp"

Lexer::Lexer(std::string_view input)
  : input(input), curr_loc{}
{}


std::vector<Token> Lexer::lex() {

  std::vector<Token> tokens;

  while (!is_eof()) {
    skip_whitespace();
    if (is_eof()) break;

    SourceLoc start = curr_loc;
    char c = peek();

    // 1 - Number
    if (std::isdigit(static_cast<unsigned char>(c))) {
      tokens.push_back(lex_number());
      continue;
    }
    
    // 2 - Symbols
    TokenKind kind = TokenKind::Invalid;
    switch(c) {
      case '+': kind = TokenKind::Plus; break;
      case '-': kind = TokenKind::Minus; break;
      default: break;
    }
    
    advance();
    SourceLoc end = curr_loc;
    std::string lexeme(
      input.substr(start.offset, end.offset - start.offset)
    );

    tokens.push_back(Token{
      kind,
      std::move(lexeme),
      start,
      end
    });


  }

  tokens.push_back(Token{
    TokenKind::End,
    "",
    curr_loc,
    curr_loc
  });

  return tokens;

}


char Lexer::advance() {

  if (is_eof())
    return '\0';

  char c = input[curr_loc.offset];
  curr_loc.offset++;

  if (c == '\n') {
    curr_loc.line++;
    curr_loc.col = 1;
  } else {
    curr_loc.col++;
  }

  return c;
}


char Lexer::peek() const {
  if (curr_loc.offset >= input.size()) return '\0';
  return input[curr_loc.offset];
}



void Lexer::skip_whitespace() {
  while (!is_eof() && std::isspace(static_cast<unsigned char>(peek()))) {
    advance();
  }
}


bool Lexer::is_eof() const {
  return curr_loc.offset >= input.size();
}


Token Lexer::lex_number() {
  SourceLoc start = curr_loc;

  while (!is_eof() && 
      std::isdigit(static_cast<unsigned char>(peek()))) {
    advance();
  }

  SourceLoc end = curr_loc;

  std::string lexeme(
    input.substr(start.offset, end.offset - start.offset)
  );

  return Token{
    TokenKind::Number,
      std::move(lexeme),
      start,
      end
  };
}
