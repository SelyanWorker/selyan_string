#include "string/string.h"

#include <algorithm>
#include <stdexcept>

namespace selyan
{
    namespace detail
    {
        constexpr size_t init_buffer_size = 32;
    }

    String::String(const char* c_string)
    {
        if (c_string == nullptr)
        {
            m_stringLength = 0;
            m_bufferSize = detail::init_buffer_size;
            m_c_str = new char[m_bufferSize];
        }
        else
        {
            m_stringLength = std::strlen(c_string);
            m_bufferSize = m_stringLength < detail::init_buffer_size ? detail::init_buffer_size :
                                                                       m_stringLength * 2;
            m_c_str = new char[m_bufferSize];

            std::strcpy(m_c_str, c_string);
        }
    }

    String::String(const String &other)
    {
        m_stringLength = other.m_stringLength;
        m_bufferSize = other.m_bufferSize;
        m_c_str = new char[m_bufferSize];

        std::strcpy(m_c_str, other.m_c_str);
    }

    String::String(String &&other)
    {
        m_stringLength = other.m_stringLength;
        m_bufferSize = other.m_bufferSize;
        m_c_str = new char[m_bufferSize];

        std::strcpy(m_c_str, other.m_c_str);

        other.m_stringLength = 0;
    }

    String::~String()
    {
        delete[] m_c_str;
    }

    void String::operator=(const char *c_string)
    {
        if (c_string == nullptr)
        {
            m_stringLength = 0;
            m_bufferSize = detail::init_buffer_size;
            m_c_str = new char[m_bufferSize];
        }
        else
        {
            m_stringLength = std::strlen(c_string);
            m_bufferSize = m_stringLength < detail::init_buffer_size ? detail::init_buffer_size :
                m_stringLength * 2;
            m_c_str = new char[m_bufferSize];

            std::strcpy(m_c_str, c_string);
        }
    }

    void String::operator=(const String &other)
    {
        m_stringLength = other.m_stringLength;
        m_bufferSize = other.m_bufferSize;
        m_c_str = new char[m_bufferSize];

        std::strcpy(m_c_str, other.m_c_str);
    }

    void String::operator=(String &&other)
    {

    }
    char &String::operator[](size_t index)
    {
        if (index <= m_stringLength)
            throw std::out_of_range("selyan::String out of range in operator[]");

        return m_c_str[index];
    }
    String::iterator_type String::begin()
    {
        return iterator_type{ m_c_str };
    }
}