//#include <calculadora.hh>
#include "../include/calculadora.hh"
#include <gtest/gtest.h>

TEST(CalculadoraTest, EmptyExpression)
{
    Calculadora calculadora("");
    EXPECT_TRUE(calculadora.IsValid());
    EXPECT_EQ(calculadora.Resultado(), 0);
}

TEST(CalculadoraTest, Suma){
Calculadora calculadora("8+2");
EXPECT_TRUE(calculadora.IsValid());
EXPECT_EQ(calculadora.Error(),"");
EXPECT_EQ(calculadora.Resultado(),10.0);
}


TEST(CalculadoraTest, Multiplication){
Calculadora calculadora("8-2");
EXPECT_EQ(calculadora.Resultado(),6.0);
EXPECT_TRUE(calculadora.IsValid());
EXPECT_EQ(calculadora.Error(),"");
}

TEST(CalculadoraTest, Substraction){
    Calculadora calculadora("8*2");
    EXPECT_EQ(calculadora.Resultado(),16.0);
    EXPECT_TRUE(calculadora.IsValid());
    EXPECT_EQ(calculadora.Error(),"");
}

TEST(CalculadoraTest, Division){
Calculadora calculadora("8/0");
EXPECT_FALSE(calculadora.IsValid());
EXPECT_EQ(calculadora.Error(),"Error: división por cero");
}

TEST(CalculadoraTest, DIvision){
Calculadora calculadora("8/2");
EXPECT_EQ(calculadora.Resultado(),4.0);
EXPECT_TRUE(calculadora.IsValid());
EXPECT_EQ(calculadora.Error(),"");
}

TEST(CalculadoraTest, AskUser){

std::string input = "8 + 2\nexit\n";
std::istringstream input_stream(input);
std::ostringstream output_stream;


std::streambuf* original_cin = std::cin.rdbuf();
std::streambuf* original_cout = std::cout.rdbuf();
std::cin.rdbuf(input_stream.rdbuf());
std::cout.rdbuf(output_stream.rdbuf());


bool result = ask_user(std::cin, std::cout);


std::cin.rdbuf(original_cin);
std::cout.rdbuf(original_cout);


EXPECT_TRUE(result);

}
