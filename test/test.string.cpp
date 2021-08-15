#include "string/string.h"

#include <gtest/gtest.h>

TEST(StringTests, IsEmpty)
{
    selyan::String str{  };
    EXPECT_TRUE(str.empty());
}

TEST(StringTests, GetLength)
{
    constexpr char sample[] = "Hello world";

    selyan::String str =  sample;

    EXPECT_EQ(str.length(), sizeof(sample) - 1);
}

TEST(StringTests, EqualStrings_empty)
{
    selyan::String str_0{  };
    selyan::String str_1{  };

    EXPECT_EQ(str_0, str_1);
}

TEST(StringTests, EqualStrings)
{
    selyan::String str_0{ "Hello world" };
    selyan::String str_1{ "Hello world!" };

    EXPECT_NE(str_0, str_1);
}

TEST(StringTests, InternalAddOperator)
{
    selyan::String str_0{ "Hello " };
    selyan::String str_1{ "world!" };

    str_0 += str_1;

    EXPECT_EQ(str_0, "Hello world!");
}

TEST(StringTests, ExternalAddOperator)
{
    selyan::String str_0{ "Hello " };
    selyan::String str_1{ "world!" };

    auto addResult = str_0 + str_1;

    EXPECT_EQ(addResult, "Hello world!");
}

TEST(StringTests, SortResult)
{
    const char* sample[] = { "D", "ZZ", "ABCD", "BCD", "ABCDF"   };
    std::vector<std::string> stdStrings{ sample[0], sample[1], sample[2], sample[3], sample[4] };
    std::vector<selyan::String> selyanStrings{ sample[0], sample[1], sample[2], sample[3], sample[4] };

    std::sort(stdStrings.begin(), stdStrings.end());
    std::sort(selyanStrings.begin(), selyanStrings.end());

    for(size_t i = 0; i < stdStrings.size(); ++i)
        EXPECT_EQ(stdStrings[i], std::string{ selyanStrings[i].c_str() });
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
