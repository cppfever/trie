#include <iostream>
#include <gtest/gtest.h>
#include <trie/trie.h>


using namespace trie;
using CppLexerData = LexerData<CppLexerTag>;


class Foo
{
public:
    Foo()
        : i(0)
    {
        std::cout << "CONSTRUCTED" << std::endl;
    }
    ~Foo()
    {
        std::cout << "DESTRUCTED" << std::endl;
    }
    int i;
};

class TestFoo : public ::testing::Test
{
protected:
    void SetUp()
    {
        foo = new Foo;
        foo->i = 5;
    }
    void TearDown()
    {
        delete foo;
    }
    Foo *foo;
};

TEST_F(TestFoo, test1)
{
    ASSERT_EQ(foo->i, 5);
    foo->i = 10;
}

TEST_F(TestFoo, test2)
{
    ASSERT_EQ(foo->i, 5);
}

