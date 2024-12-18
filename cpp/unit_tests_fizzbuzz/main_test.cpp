#include <gtest/gtest.h>
#include "functions.cpp"
 
TEST(FizzBuzzTest, DivisibleBy3) {
    EXPECT_EQ(FizzBuzz(3), "Fizz");
    EXPECT_EQ(FizzBuzz(6), "Fizz");
}
 
TEST(FizzBuzzTest, DivisibleBy5) {
    EXPECT_EQ(FizzBuzz(5), "Buzz");
    EXPECT_EQ(FizzBuzz(10), "Buzz");
}
 
TEST(FizzBuzzTest, DivisibleBy3And5) {
    EXPECT_EQ(FizzBuzz(15), "FizzBuzz");
    EXPECT_EQ(FizzBuzz(30), "FizzBuzz");
}
 
TEST(FizzBuzzTest, NotDivisibleBy3Or5) {
    EXPECT_EQ(FizzBuzz(1), "1");
    EXPECT_EQ(FizzBuzz(7), "7");
}
 
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}