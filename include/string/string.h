#pragma once

#include <cstring>
#include <algorithm>
#include <cctype>

namespace selyan
{
    class String
    {
    public:
        String(const char* c_string = nullptr);

        String(const String& other);

        String(String&& other) noexcept;

        ~String();

        bool empty() const
        {
            return m_stringLength == 0;
        }

        size_t length() const
        {
            return m_stringLength;
        }

        const char* c_str() const
        {
            return m_c_str;
        }

        String& operator=(const char* c_string);

        String& operator=(const String& other);

        String& operator=(String&& other) noexcept;

        char& operator[](size_t index);

        char operator[](size_t index) const;

        String& operator+=(const String& other);

    private:
        size_t m_bufferSize;
        size_t m_stringLength;
        char* m_c_str;
    };

    inline bool operator==(const String& left, const String& right)
    {
        if (left.length() != right.length())
            return false;

        for(size_t i = 0; i < left.length(); ++i)
        {
            if (left[i] != right[i])
                return false;
        }

        return true;
    }

    inline bool operator!=(const String& left, const String& right)
    {
        return !(left == right);
    }

    inline String operator+(const String& left, const String& right)
    {
        String result{ left };
        return result += right;
    }

    inline bool operator<(const String& left, const String& right)
    {
        size_t minLength = std::min(left.length(), right.length());
        for(size_t i = 0; i < minLength; ++i)
        {
            if (left[i] == right[i])
                continue;

            return left[i] < right[i];
        }

        return left.length() < right.length();
    }

}

