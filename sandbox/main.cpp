#include "string/string.h"

#include <iostream>
#include <vector>
#include <algorithm>

bool customCompare(const selyan::String& left, const selyan::String& right)
{
    size_t minLength = std::min(left.length(), right.length());
    for (size_t i = 0; i < minLength; ++i)
    {
        auto leftLowerChar = std::tolower(left[i]);
        auto rightLowerChar = std::tolower(right[i]);

        if (leftLowerChar == rightLowerChar)
            continue;

        return leftLowerChar < rightLowerChar;
    }

    return left.length() < right.length();
}

int main()
{
    std::cout << "Input string count:";

    int stringCount = 0;
    std::cin >> stringCount;

    std::cout << "Input strings: \n";
    std::vector<selyan::String> strings;
    for(auto i = 0; i <= stringCount; ++i)
    {
        std::string input;
        std::getline(std::cin, input, '\n');
        strings.emplace_back(input.c_str());
    }

    std::sort(strings.begin(), strings.end(), customCompare);

    std::cout << "Output strings: " << std::endl;
    std::reverse(strings.begin(), strings.end());
    for(auto string : strings)
        std::cout << string.c_str() << std::endl;

    return 0;
}
