#include <iostream>
#include <trie/trie.h>


using namespace trie;
using CppLexerData = LexerData<CppLexerTag>;

int main()
{

    Map<CppLexerData, MapSize::Full> map(nullptr, -1, CppLexerData("class", CppLexerTag::Class));
    map.Insert("class",5,CppLexerData("class",CppLexerTag::Class));

    std::cout << "Hellow dude)" << std::endl;

    return 0;
}
