#pragma once

#include <exception>
#include <string>
#include <vector>


namespace trie
{

enum CppLexerTag
{
    Unknown,
    If,
    Break,
    Return,
    Virtual,
    Class
};//enum LexerTag


struct TrieData
{
    virtual bool IsEmpty() = 0;
};//struct TrieData


template<typename TAG>
struct LexerData
{
    LexerData() : m_empty(true)
    {}

    LexerData(const std::string& lexeme, TAG tag) : m_empty(false), m_lexeme(lexeme), m_tag(tag)
    {}

    bool IsEmpty() const
    {
        return m_empty;
    }

    std::string Lexeme() const
    {
        return m_lexeme;
    }

    TAG Tag() const
    {
        return m_tag;
    }

private:

    bool m_empty;
    std::string m_lexeme;
    TAG m_tag;
};//struct LexerData


enum class MapSize : size_t
{
    Full = 256,
    Half = 16,
    Fourth = 4,
    Eighth = 2,
};//enum class MapSize


template<typename DATA, MapSize SIZE>
class Map;


template<MapSize SIZE>
struct Indexer;

template<>
struct Indexer<MapSize::Full>
{
    template<typename DATA>
    using Map_t = Map<DATA, MapSize::Full>;

    template<typename DATA>
    Map_t<DATA>* InsertChar(char _c, Map_t<DATA>* ptr, const DATA& data)
    {
        union
        {
            char c;
            uint8_t index;
        };

        c = _c;
        return ptr->InsertIndex(index, data);
    }

};//struct Indexer;

/*
template<>
struct Bits<Part::Half>
{
    union
    {
        char m_char;

        struct
        {
            uint8_t m_p1 : 4;
            uint8_t m_p2 : 4;
        };
    };
};
*/


template<typename DATA, MapSize SIZE>
class Map
{
public:

    using Map_t = Map<DATA, SIZE>;
    using Map_p = Map<DATA, SIZE>*;
    friend struct Indexer<SIZE>;

    Map() : m_parent(nullptr), m_index(-1)
    {}

    Map(Map_p parent, size_t index, const DATA& data) : m_parent(parent),m_index(index)
    {
        if(m_parent && !data.IsEmpty())
            m_data.push_back(data);
    }

    ~Map()
    {
        Clear();
    }

    //Insert characters from string.
    //On last character insert 'data' object, on other epmty DATA object.
    void Insert(const char* str, size_t size, const DATA& data)
    {
        Map_p ptr = this;//Begin from that map object

        for(size_t n = 0; n < size ; n++)
        {
            Indexer<SIZE> indexer;//Static dispatcher

            if(n == size-1)
                ptr = indexer.InsertChar(str[n], ptr, data);//Last character
            else
                ptr = indexer.InsertChar(str[n], ptr, DATA());//Insert empty data
        }
    }

    std::vector<DATA>& Data() const
    {
        return m_data;
    }

    void Clear()
    {
        for(Map_p map : m_map)
        {
            if(map)
            {
                map->Clear();
                delete map;
            }
        }
    }

private:

    Map_p InsertIndex(uint8_t index, const DATA& data)
    {
        if(!m_map[index])
            m_map[index] = new Map_t(this, index, data);

        return m_map[index];
    }


    Map_p m_parent;
    size_t m_index;
    Map_p m_map[static_cast<size_t>(SIZE)] = {0};
    std::vector<DATA> m_data;
};


}//namespace trie
