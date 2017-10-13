#pragma once

#include <memory>


namespace trie
{

enum TestTag
{
    Unknown
};


enum class MapSize
{
    Full = 256,
    Half = 16,
    Fourth = 4,
    Eighth = 2
};


template<typename TagT, MapSize SIZE>
class MapT;


template<typename TagT, MapSize SIZE>
using MapTPtr = std::shared_ptr<MapT<TagT,SIZE>>;


template<MapSize PART>
struct Indexer;


template<>
struct Indexer<MapSize::Full>
{
    union
    {
        char m_char;
        uint8_t m_index;
    };

    template<typename TagT>
    MapTPtr<TagT, MapSize::Full> InsertChar(MapTPtr<TagT, MapSize::Full> ptr, char c, TagT tag)
    {
        Indexer<MapSize::Full> bits{c};
        return ptr->InsertIndex(bits.m_index, tag);
    }

};

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

template<typename TagT, MapSize SIZE>
class MapT : public std::enable_shared_from_this<MapT<TagT, SIZE>>
{
    using Self_t = MapT<TagT, SIZE>;
    using Ptr_t = MapTPtr<TagT, SIZE>;

    friend struct Indexer<SIZE>;

    MapTPtr<TagT, SIZE> m_map[static_cast<size_t>(SIZE)];
    TagT m_tag{TagT::Unknown};


    Ptr_t InsertIndex(uint8_t index, TagT tag)
    {
        if(!m_map[index])
            m_map[index] = std::make_shared<Self_t>();

        if(m_map[index]->m_tag == TagT::Unknown)
        {
            if(tag != TagT::Unknown)
                m_map[index]->m_tag = tag;
        }
        else
        {
            if(tag != TagT::Unknown)
                throw "Rewrithing tag.";
        }

        return m_map[index];
    }

public:

    void Insert(const char* str, size_t size, TagT tag)
    {
        Ptr_t ptr(this);

        for(size_t n = 0; n < size ; n++)
        {
            Indexer<SIZE> bits;

            if(n == size-1)
                ptr = bits.InsertChar(ptr, str[n], tag);
            else
                ptr = bits.InsertChar(ptr, str[n], TagT::Unknown);
        }
    }
};

}
