#include <iostream>
#include <trie/trie.h>


int main()
{
    trie::MapT<trie::TestTag, trie::MapSize::Full> map;
    map.Insert("class",5,trie::TestTag::Unknown);

    std::cout << "Hellow dude)" << std::endl;

    return 0;
}
