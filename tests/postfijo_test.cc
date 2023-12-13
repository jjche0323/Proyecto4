//
// Created by Administrador on 11/12/2023.
//
#include <gtest/gtest.h>
#include <postfijo.hh>


TEST(PostfijoTest, Number)
{
/
TokenNumero* numberToken = new TokenNumero(0, 0, 50.0);


std::queue<Token*> queue;
queueWithNumber.push(numberToken);


Postfijo postfijo(queue);


EXPECT_TRUE(postfijo.IsValid());
EXPECT_EQ(postfijo.Resultado(), 42.0);
EXPECT_EQ(postfijo.Error(), "");
}

TEST(PostfijoTest, DivZero)
{
// Crear tokens para 5.0 y 0.0 (divisor cero)
TokenNumero* num5 = new TokenNumero(0, 0, 8.0);
TokenNumero* num0 = new TokenNumero(0, 0, 0.0);
TokenOperador* divideOperator = new TokenOperador(0, 0, '/');


std::queue<Token*> queueDivZero;
queueForDivisionByZero.push(num5);
queueForDivisionByZero.push(num0);
queueForDivisionByZero.push(divideOperator);
Postfijo postfijo(queueDivZero);


EXPECT_FALSE(postfijo.IsValid());
EXPECT_EQ(postfijo.Resultado(), 0.0);
EXPECT_EQ(postfijo.Error(), "Error: división por cero");
}


TEST(PostfijoTest, Add)
{
TokenNumero* num5 = new TokenNumero(0, 0, 15.0);
TokenNumero* num3 = new TokenNumero(0, 0, 22.0);
TokenOperador* plusOperator = new TokenOperador(0, 0, '+');
std::queue<Token*> queueAdd;
queueAdd.push(num15);
queueAdd.push(num22);
queueAdd.push(plusOperator);


Postfijo postfijo(queueAdd);
EXPECT_TRUE(postfijo.IsValid());
EXPECT_EQ(postfijo.Resultado(), 37.0);
EXPECT_EQ(postfijo.Error(), "");
}



TEST(PostfijoTest, WrongOperands)
{
TokenNumero* num5 = new TokenNumero(0, 0, 5.0);
TokenOperador* plusOperator = new TokenOperador(0, 0, '+');

std::queue<Token*> queueWrOperands;
queueForMissingOperands.push(num5);
queueForMissingOperands.push(plusOperator);

Postfijo postfijo(queueWrOperands);

EXPECT_FALSE(postfijo.IsValid());
EXPECT_EQ(postfijo.Resultado(), 0.0);
EXPECT_EQ(postfijo.Error(), "Error: faltan operandos");
}


TEST(PostfijoTest, Subst)
{

TokenNumero* num5 = new TokenNumero(0, 0, 8.0);
TokenNumero* num3 = new TokenNumero(0, 0, 2.0);
TokenOperador* plusOperator = new TokenOperador(0, 0, '-');
std::queue<Token*> queueSubstract;
queueSubstract.push(num8);
queueSubstract.push(num2);
queueSubstract.push(plusOperator);
Postfijo postfijo(queueSubstract);
EXPECT_TRUE(postfijo.IsValid());
EXPECT_EQ(postfijo.Resultado(), 6.0);
EXPECT_EQ(postfijo.Error(), "");
}

TEST(PostfijoTest, Multiply)
{
TokenNumero* num5 = new TokenNumero(0, 0, 10.0);
TokenNumero* num3 = new TokenNumero(0, 0, 4.0);
TokenOperador* plusOperator = new TokenOperador(0, 0, '*');


std::queue<Token*> queueMultiply;
queueMultiply.push(num10);
queueMultiply.push(num4);
queueMultiply.push(plusOperator);
Postfijo postfijo(queueMultiply);
EXPECT_TRUE(postfijo.IsValid());
EXPECT_EQ(postfijo.Resultado(), 40.0);
EXPECT_EQ(postfijo.Error(), "");
}

TEST(PostfijoTest, Division)
{

TokenNumero* num5 = new TokenNumero(0, 0, 8.0);
TokenNumero* num3 = new TokenNumero(0, 0, 2.0);
TokenOperador* plusOperator = new TokenOperador(0, 0, '/');
std::queue<Token*> queueDiv;
queueDiv.push(num8);
queueDiv.push(num2);
queueDiv.push(plusOperator);
Postfijo postfijo(queueDiv);
EXPECT_TRUE(postfijo.IsValid());
EXPECT_EQ(postfijo.Resultado(), 4.0);
EXPECT_EQ(postfijo.Error(), "");
}
