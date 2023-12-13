
#include <gtest/gtest.h>
#include <tokenizer.hh>

TEST(TokenizerTest, EmptyString)
{
    Tokenizer tokenizer("");
    EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, Num)
{
Tokenizer tokenizer("80");
EXPECT_TRUE(tokenizer.HasNext());
Token* token = tokenizer.Next();
ASSERT_TRUE(token != nullptr);
EXPECT_TRUE(token->IsNumber());
EXPECT_EQ(token->inicio(), 0);
EXPECT_EQ(token->fin(), 1);
delete token;
EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, Subs)
{
Tokenizer tokenizer("-");
EXPECT_TRUE(tokenizer.HasNext());
Token* token = tokenizer.Next();
ASSERT_TRUE(token != nullptr);
EXPECT_TRUE(token->IsOperator());
EXPECT_EQ(token->inicio(), 0);
EXPECT_EQ(token->fin(), 1);
delete token;
EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, Sum)
{
Tokenizer tokenizer("+");
EXPECT_TRUE(tokenizer.HasNext());
Token* token = tokenizer.Next();
ASSERT_TRUE(token != nullptr);
EXPECT_TRUE(token->IsOperator());
EXPECT_EQ(token->inicio(), 0);
EXPECT_EQ(token->fin(), 1);
delete token;
EXPECT_FALSE(tokenizer.HasNext());
}


TEST(TokenizerTest, Div)
{
Tokenizer tokenizer("/");
EXPECT_TRUE(tokenizer.HasNext());
Token* token = tokenizer.Next();
ASSERT_TRUE(token != nullptr);
EXPECT_TRUE(token->IsOperator());
EXPECT_EQ(token->inicio(), 0);
EXPECT_EQ(token->fin(), 1);
delete token;
EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, Mult)
{
Tokenizer tokenizer("*");
EXPECT_TRUE(tokenizer.HasNext());
Token* token = tokenizer.Next();
ASSERT_TRUE(token != nullptr);
EXPECT_TRUE(token->IsOperator());
EXPECT_EQ(token->inicio(), 0);
EXPECT_EQ(token->fin(), 1);
delete token;
EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, LeftBrack)
{
Tokenizer tokenizer("(");
EXPECT_TRUE(tokenizer.HasNext());
Token* token = tokenizer.Next();
ASSERT_TRUE(token != nullptr);
EXPECT_TRUE(token->IsOperator());
EXPECT_EQ(token->inicio(), 0);
EXPECT_EQ(token->fin(), 1);
delete token;
EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, RigthBrack)
{
Tokenizer tokenizer(")");
EXPECT_TRUE(tokenizer.HasNext());
Token* token = tokenizer.Next();
ASSERT_TRUE(token != nullptr);
EXPECT_TRUE(token->IsOperator());
EXPECT_EQ(token->inicio(), 0);
EXPECT_EQ(token->fin(), 1);
delete token;
EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, AvoidEsp)
{
Tokenizer tokenizer("  8");
EXPECT_TRUE(tokenizer.HasNext());
Token* token = tokenizer.Next();
ASSERT_TRUE(token != nullptr);
EXPECT_TRUE(token->IsNumber());
EXPECT_EQ(token->inicio(), 0);
EXPECT_EQ(token->fin(), 4);
delete token;
EXPECT_FALSE(tokenizer.HasNext());
EXPECT_EQ(tokenizer.Next(), nullptr);
}

TEST(TokenizerTest, Fill){
    Tokenizer tokenizer2("2");
while(tokenizer2.HasNext){
    delete tokenizer2.Next();
}
EXPECT_FALSE(tokenizer2.HastNext());
EXPECT_EQ(tokenizer2.NEXT(), nullptr);
}
TEST(TokenizerTest, InvalidEntry){
    Tokenizer tokenizer1("asf%");
    EXPECT_THROW({
        while(tokenizer1.HasNext()){
            Token * token1= tokenizer1.Next();
            delete token;

        }
    }, std::runtime_error)

}


TEST(TokenizerTest, decimals){
    Tokenizer tokenizer1("5.9.6");
    EXPECT_THROW({
        Token * token1 = tokenizer1.Next();
        delete token;

    }, std::runtime_error);
}

