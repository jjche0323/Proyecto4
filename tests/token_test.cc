//
// Created by justin on 11/12/2023.
//
#include "token.hh"
#include <gtest/gtest.h>
TEST(TokenTest, TokenOperador){
    TokenOperador tokenOperador1 (9,8,'-');
    EXPECT_EQ(tokenOperador1.operador(),'-');
    EXPECT_TRUE(tokenOperador1.IsOperator());
    EXPECT_FALSE(tokenOperador1.IsNumber());
    EXPECT_FALSE(tokenOperador1.IsRightParenthesis());
    EXPECT_FALSE(tokenOperador1.IsLeftParenthesis());
    EXPECT_EQ(tokenOperador1.GetPrecedence(),1);
}

TEST(TokenTest, Div){
    TokenOperador tokenOperador(0,0,'/');
    EXPECT_TRUE(tokenOperador.IsOperator());
    EXPECT_FALSE(tokenOperador.IsNumber());
    EXPECT_FALSE(tokenOperador.IsRightParenthesis());
    EXPECT_FALSE(tokenOperador.IsLeftParenthesis());
    EXPECT_EQ(tokenOperador.GetPrecedence(),2);
}

TEST(TokenTest, Beginend){
    TokenOperador tokenOperador(6,10,'*');
    EXPECT_EQ(tokenOperador.inicio(),6);
    EXPECT_EQ(tokenOperador.fin(),10);

}

TEST(TokenTest, UnknowOperador){
    TokenOperador tokenOperador('$');
    EXCPECT_EQ(tokenOperador.GetPrecedence(),0);
}

TEST(TokenTest, Mul){
TokenOperador tokenOperador(0,0,'*');
EXPECT_TRUE(tokenOperador.IsOperator());
EXPECT_FALSE(tokenOperador.IsNumber());
EXPECT_FALSE(tokenOperador.IsRightParenthesis());
EXPECT_FALSE(tokenOperador.IsLeftParenthesis());
EXPECT_EQ(tokenOperador.GetPrecedence(),2);
}

TEST(TokenTest, Num){
TokennNumero tokenNumero(0,0,8.0);
EXPECT_FALSE(tokenNumero.IsOperator());
EXPECT_TRUE(tokenNumero.IsNumber());
EXPECT_FALSE(tokenNumero.IsRightParenthesis());
EXPECT_EQ(tokenNumero.IsLeftParenthesis());

}
