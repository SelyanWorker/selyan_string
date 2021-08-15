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
    :   m_stringLength(0),
        m_bufferSize(0)
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

    String::String(String &&other) noexcept
    {
        m_stringLength = other.m_stringLength;
        m_bufferSize = other.m_bufferSize;
        m_c_str = other.m_c_str;

        other.m_stringLength = 0;
        other.m_bufferSize = 0;
        other.m_c_str = nullptr;
    }

    String::~String()
    {
        delete[] m_c_str;
    }

    String& String::operator=(const char *c_string)
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

        return *this;
    }

    String& String::operator=(const String &other)
    {
        if(&other == this)
            return *this;

        m_stringLength = other.m_stringLength;
        m_bufferSize = other.m_bufferSize;

        delete[] m_c_str;
        m_c_str = new char[m_bufferSize];

        std::strcpy(m_c_str, other.m_c_str);

        return *this;
    }

    String& String::operator=(String &&other) noexcept
    {
        m_stringLength = other.m_stringLength;
        m_bufferSize = other.m_bufferSize;
        m_c_str = other.m_c_str;

        other.m_stringLength = 0;
        other.m_bufferSize = 0;
        other.m_c_str = nullptr;

        return *this;
    }

    char &String::operator[](size_t index)
    {
        if (index >= m_stringLength)
            throw std::out_of_range("selyan::String out of range in operator[]");

        return m_c_str[index];
    }

    char String::operator[](size_t index) const
    {
        if (index >= m_stringLength)
            throw std::out_of_range("selyan::String out of range in operator[]");

        return m_c_str[index];
    }

    String &String::operator+=(const String &other)
    {
        if (other.empty())
            return *this;

        size_t newLength = m_stringLength + other.m_stringLength;
        if (newLength > m_bufferSize)
        {
            m_bufferSize = newLength;
            auto oldCStr = m_c_str;

            m_c_str = new char[m_bufferSize];

            std::strncpy(m_c_str, oldCStr, m_stringLength);
            std::strncat(m_c_str, other.m_c_str, other.length());

            m_stringLength = newLength;

            delete[] oldCStr;
            return *this;
        }

        m_stringLength = newLength;
        std::strncat(m_c_str, other.m_c_str, other.length());
        return *this;
    }
}
