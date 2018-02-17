//
// Created by mwypych on 01.06.17.
//

#include <ArabicRoman.h>
#include <gtest/gtest.h>

TEST(ArabicRomanTests, OneShouldBeI)
{
    EXPECT_EQ("I", ArabicToRoman(1));
}
TEST(ArabicRomanTests, FiftyShouldBeL)
{
    EXPECT_EQ("L", ArabicToRoman(50));

}
TEST(ArabicRomanTests, Thousand589ShouldBeMDLXXXIX)
{
    EXPECT_EQ("MDLXXXIX", ArabicToRoman(1589));
}

TEST(ArabicRomanTests, NegativeNumber) {
    EXPECT_THROW(ArabicToRoman(-3), Negative);
}
