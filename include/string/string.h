#pragma once

#include <cstring>
#include <iterator>

namespace selyan
{

    class String
    {
    public:
        using char_type = char;
        using iterator_type = std::iterator<std::random_access_iterator_tag, char_type>;

    public:
        String(const char* c_string = nullptr);

        String(const String& other);

        String(String&& other);

        ~String();

        void operator=(const char* c_string);

        void operator=(const String& other);

        void operator=(String&& other);

        char& operator[](size_t index);

        iterator_type begin();

        iterator_type end();

    private:
        size_t m_bufferSize;
        size_t m_stringLength;
        char* m_c_str;
    };
}