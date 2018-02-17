//
// Created by mwypych on 01.06.17.
//


#include <ArabicRoman.h>
#include <gtest/gtest.h>

TEST(ArabicRomanTests, IShouldBe1)
{
    EXPECT_EQ(1, RomanToArabic("I"));
}
TEST(ArabicRomanTests, FiftyShouldBeL)
{
    EXPECT_EQ(50, RomanToArabic("L"));

}
TEST(ArabicRomanTests, Thousand589ShouldBeMDLXXXIX)
{
    EXPECT_EQ(1589, RomanToArabic("MDLXXXIX"));
}
