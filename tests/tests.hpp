#include <iostream>
#include <gtest/gtest.h>
#include <trie/trie.h>


using namespace trie;
using CppLexerData = LexerData<CppLexerTag>;

class Insert : public ::testing::Test {
public:
    Insert() { }
    ~Insert() { }
    void SetUp() override { }
    void TearDown() override { }

protected:

};
/*
TEST_F(TestSerialization, DateJson) {
    Date d1(1988, 8, 5);
    rapidjson::Document json = d1.toJSON();
    Date d2 = Date::fromJSON(json);
    ASSERT_EQ(d1, d2);
}

TEST_F(TestSerialization, UserJson) {
    User u1(123, "Alex", 79161234567, Date(1988, 8, 5));
    rapidjson::Document json = u1.toJSON();
    User u2 = User::fromJSON(json);
    ASSERT_EQ(u1, u2);
}
*/
