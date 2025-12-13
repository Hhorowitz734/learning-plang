#include <gtest/gtest.h>
#include <string>
#include "lexer.hpp"
#include "token.hpp"

TEST(Lexer, LexesSingleNumber) {
  std::string src = "123";
  Lexer lexer(src);

  auto tokens = lexer.lex();

  // Expect: Number("123"), End
  ASSERT_EQ(tokens.size(), 2u);

  EXPECT_EQ(tokens[0].kind, TokenKind::Number);
  EXPECT_EQ(tokens[0].lexeme, "123");

  EXPECT_EQ(tokens[1].kind, TokenKind::End);
}

TEST(Lexer, SkipsWhitespace) {
  std::string src = "   \n\t  456  ";
  Lexer lexer(src);

  auto tokens = lexer.lex();

  ASSERT_EQ(tokens.size(), 2u);
  EXPECT_EQ(tokens[0].kind, TokenKind::Number);
  EXPECT_EQ(tokens[0].lexeme, "456");
  EXPECT_EQ(tokens[1].kind, TokenKind::End);
}


