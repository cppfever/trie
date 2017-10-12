#pragma once

#include <memory>


namespace trie
{

enum DefaultTag
{
    Unknown
};

enum class Part : size_t
{
    Full = 256,
    Half = 16,
    Fourth = 4,
    Eighth = 2
};


template<trie::Part PART>
struct Bits;


template<>
struct Bits<Part::Full>
{
    union
    {
        char m_char;
        uint8_t m_p1;
    };
};


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


template<typename TagT, Part SIZE>
class MapT;

template<typename TagT, Part SIZE>
using MapTPtr = std::shared_ptr<MapT<TagT,SIZE>>;

template<typename TagT, Part SIZE>
MapTPtr<TagT, SIZE> InsertChar(MapTPtr<TagT, SIZE> ptr,char c, TagT tag);

template<typename TagT>
auto InsertChar(MapTPtr<TagT, Part::Full> ptr, char c, TagT tag)
{
    Bits<Part::Full> bits{c};
    uint8_t index = bits.m_p1;
    auto result = std::make_shared<MapTPtr<TagT, Part::Full>>();
    ptr->m_map[index] = result;

    return result;
}

template<typename TagT, Part SIZE>
class MapT : public std::enable_shared_from_this<MapT<TagT, SIZE>>
{
    using Self_t = MapT<TagT, SIZE>;
    using Ptr_t = std::shared_ptr<Self_t>;

    friend Ptr_t trie::InsertChar<TagT, SIZE>(Ptr_t ptr, char c, TagT);

    Ptr_t m_map[static_cast<size_t>(SIZE)];
    TagT m_tag{TagT::Unknown};

    Ptr_t InsertChar(char c, TagT tag)
    {/*
        size_t index = static_cast<size_t>(c);

        if(!m_map[index])
            m_map[index] = trie::InsertChar(this, c, tag);//std::make_shared<Self_t>();

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

        return m_map[index];*/
        Ptr_t ptr(this);

        return ptr;
    }

public:

    void Insert(const char* str, size_t size, TagT tag)
    {
        Ptr_t ptr(this);

        for(size_t n = 0; n < size ; n++)
        {
            if(n == size-1)
                trie::InsertChar<TagT, SIZE>(ptr, str[n], tag);
            else
                ptr = trie::InsertChar<TagT, SIZE>(ptr, str[n], TagT::Unknown);
        }
    }
};

}
