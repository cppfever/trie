#include <iostream>
#include <trie/trie.h>


int main()
{
    trie::MapT<trie::DefaultTag, trie::Part::Full> map;
    map.Insert("class",5,trie::DefaultTag::Unknown);

    std::cout << "Hellow dude)" << std::endl;

    return 0;
}
