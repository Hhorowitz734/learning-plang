#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>

// Location in source file
struct SourceLoc {
  uint32_t line = 1;
  uint32_t col = 1;
  size_t offset = 0;
};


// Possible kind of token
enum class TokenKind {
  End,
  Invalid,

  Number,

  Plus, Minus, Star, Slash,
  LParen, RParen
};


struct Token {

  TokenKind kind;         // token kind
  std::string lexeme;     // lexeme
  SourceLoc start;        // location of start
  SourceLoc end;          // location of end


  std::string to_string() const;

};


inline std::string_view to_string(TokenKind k) {
  switch (k) {
    case TokenKind::End:     return "End";
    case TokenKind::Invalid: return "Invalid";
    case TokenKind::Number:  return "Number";
    case TokenKind::Plus:    return "Plus";
    case TokenKind::Minus:   return "Minus";
    case TokenKind::Star:    return "Star";
    case TokenKind::Slash:   return "Slash";
    case TokenKind::LParen:  return "LParen";
    case TokenKind::RParen:  return "RParen";
  }
  return "Unknown";
}

#endif
