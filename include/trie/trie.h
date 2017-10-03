#pragma once

#include <memory>
//#include <shared_ptr>

namespace trie
{

enum DefaultTag
{
    Unknown
};

enum class Part : std::uint32_t
{
    Full = 256,
    Half = 16,
    Fourth = 4,
    Eighth = 2
};

template<typename CharT, typename TagT, Part SIZE>
class MapT : public std::enable_shared_from_this<MapT<CharT, TagT, SIZE>>
{
    using Self_t = MapT<CharT, TagT, SIZE>;
    using Ptr_t = std::shared_ptr<Self_t>;

    //static constexpr std::uint32_t s_size = static_cast<std::uint32_t>(SIZE);
    Ptr_t m_map[static_cast<std::uint32_t>(SIZE)];
    TagT m_tag = TagT::Unknown;

    Ptr_t InsertChar(CharT c)
    {
        if(!m_map[c])
            m_map[c] = std::make_shared<Self_t>();

        return m_map[c];
    }

public:

    void Insert(const CharT* str, size_t size)
    {
        for(auto n = 0; n < size ; n++)
        {
            InsertChar(str[n]);
        }
    }
};

}
