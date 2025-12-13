#include "token.hpp"

std::string Token::to_string() const {
  return std::string(::to_string(kind)) +
    " '" + lexeme + "'";
}
