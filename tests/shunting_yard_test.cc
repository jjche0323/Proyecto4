#include <gtest/gtest.h>
#include <shunting_yard.hh>

class MockTokenizer : public ITokenizer {
private:
    std::queue<Token*> tokens;

public:
    MockTokenizer(const std::vector<Token*>& tokens)
    {
        for (auto token : tokens) {
            this->tokens.push(token);
        }
    }

    virtual bool HasNext() const override
    {
        return !tokens.empty();
    }

    virtual Token* Next() override
    {
        Token* token = tokens.front();
        tokens.pop();
        return token;
    }
};

TEST(ShuntingYardTest, EmptyExpression)
{
    MockTokenizer tokenizer({});
    ShuntingYard shunting_yard(tokenizer);
    std::queue<Token*> postfijo = shunting_yard.ConvertirAPostfijo();

    EXPECT_TRUE(postfijo.empty());
}

TEST(ShuntingYardTest, Number){
    std::vector<Token*> tokens ={
            new TokenNumero(0,0,3.0),
            }
            MockTokenizer tokenizer1(Tokens);
            ShuntingYard shuntingYard(tokenizer);

            std::queue<Token*> postfijo = shuntingYard.ConvertirAPostfijo();

            ASSERTEQ(postfijo.size(),1);
            EXPECT_TRUE(postfijo.front()->IsOperator());
}

TEST(ShuntingYardTest, Add){
    vector<Token*> tokens = {
            new TokenOperador(0,0,'+');
    };

    MockTokenizer tokenizer2(tokens);
    ShuntingYard shuntingYard1(tokenizer2);
    queue<Token*> postfijo = shuntingYard1.ConvertirAPosfijo();
    ASSERT_EQ(posfijo.size(),1);
    EXPECT_TRUE(postfijo.front()->IsOperator());
}


TEST(ShuntingYardTest, Mult){
    vector<Token*> tokens ={
            new TokenOperador(0,0,'*');
    }
ockTokenizer tokenizer2(tokens);
ShuntingYard shuntingYard1(tokenizer2);
queue<Token*> postfijo = shuntingYard1.ConvertirAPosfijo();
ASSERT_EQ(posfijo.size(),1);
EXPECT_TRUE(postfijo.front()->IsOperator());

}

TEST(ShuntingYardTest, Sub){
vector<Token*> tokens ={
        new TokenOperador(0,0,'-');
}
ockTokenizer tokenizer2(tokens);
ShuntingYard shuntingYard1(tokenizer2);
queue<Token*> postfijo = shuntingYard1.ConvertirAPosfijo();
ASSERT_EQ(posfijo.size(),1);
EXPECT_TRUE(postfijo.front()->IsOperator());

}

TEST(ShuntingYardTest, Div){
vector<Token*> tokens ={
        new TokenOperador(0,0,'/');
}
ockTokenizer tokenizer2(tokens);
ShuntingYard shuntingYard1(tokenizer2);
queue<Token*> postfijo = shuntingYard1.ConvertirAPosfijo();
ASSERT_EQ(posfijo.size(),1);
EXPECT_TRUE(postfijo.front()->IsOperator());

}

TEST(ShuntingYardTest, LeftBracket){
vector<Token*> tokens ={
        new TokenOperador(0,0,'(');
}
ockTokenizer tokenizer2(tokens);
ShuntingYard shuntingYard1(tokenizer2);
queue<Token*> postfijo = shuntingYard1.ConvertirAPosfijo();
ASSERT_EQ(posfijo.size(),1);
EXPECT_TRUE(postfijo.front()->IsOperator());

}



TEST(ShuntingYardTest, RBracket){
vector<Token*> tokens ={
        new TokenOperador(0,0,')');
}
ockTokenizer tokenizer2(tokens);
ShuntingYard shuntingYard1(tokenizer2);
queue<Token*> postfijo = shuntingYard1.ConvertirAPosfijo();
ASSERT_EQ(posfijo.size(),1);
EXPECT_TRUE(postfijo.front()->IsOperator());

}

TEST(ShuntingYardTest, BracketHandL){
    std::vector<Token*> tokens={
        new TokenOperador(0,0,'('),
        new TokenNumero(0,0,50.0),
        new TokenOperador(0,0,')'),
    }
    MockTokenizer tokenizer3(tokens);
    ShuntingYard shuntingYard2(tokenizer);
    std::queue<Token*> postfijo = shuntingYard3.ConvertirAPostfijo();
    ASSERT_EQ(postfijo.size(),3);
    EXPECT_TRUE(postfijo.front()->IsNumber());
    postfijo.pop();
    EXPECT_TRUE(postfijo.front()->IsOperator());

}

TEST(ShuntingYardTest, SingleB){
vector<Token*> tokens ={
        new TokenOperador(0,0,')';
}
ockTokenizer tokenizer2(tokens);
ShuntingYard shuntingYard1(tokenizer2);
try{
    std::queue<Token*> posfijo = shuntingYard1.ConvertirAPosfijo();
    FAIL()<< "Expected exception not thrown";
}catch (const std::runtime_error& e){
    EXPECT_STREQ("Problema con los paréntesis", e.what());
}

}

