/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

 //Example test
TEST(GuesserTest, basic_test)
{
	Guesser guess("Hello World!");
	bool val = guess.match("Hello World!");
    ASSERT_EQ(true, val);
}

TEST(GuesserTest, distance_of_one_test)
{
	Guesser guess("Hello World!");
	bool val = guess.match("Hello World!!");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, distance_of_oneV1_test)
{
	Guesser guess("Hello World!");
	bool val = guess.match("HellO World!!");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, distance_of_two_test)
{
	Guesser guess("Hello World!");
	bool val = guess.match("Hello World!$#");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, distance_of_twoV1_test)
{
	Guesser guess("Hello World!");
	bool val = guess.match("HelLo World!$#");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, lowerCase_test)
{
	Guesser guess("Hello World!");
	bool val = guess.match("hello World!");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, distance_test)
{
	Guesser guess("Hello World!");
	bool val = guess.match("Heznillo World!");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, distance_lock_test)
{
	Guesser guess("Hello World!");
	guess.match("Heznillo World!");
	bool val = guess.match("Hello World!");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, remaining_test)
{
	Guesser guess("Hello World!");
	guess.match("Heznillo World!");
	guess.match("Vishruth");
	guess.match("Chico state");
	bool val = guess.match("Hello World!");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, long_random_test)
{
	Guesser guess("Hello World!");
	bool val = guess.match("random length of a sentence which is very long. This line is a random test");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, empty_guess_test)
{
	Guesser guess("Hello World!");
	bool val = guess.match("");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, exhaust_reamining_test)
{
	Guesser guess("Hello World!");
	guess.match("Heznillo World!");
	guess.match("Vishruth");
	guess.match("Chico state");
	guess.match("United states of America");
	unsigned int val = guess.remaining();
    ASSERT_EQ(2, val);
}

TEST(GuesserTest, exhaust_test_applySecret)
{
	Guesser guess("Hello World!");
	guess.match("Hello world!");
	guess.match("Hello WOrld!");
	guess.match("Hello World$");
	guess.match("Hello World!");
	unsigned int val = guess.remaining();
    ASSERT_EQ(0, val);
}

TEST(GuesserTest, basic_len32_plus_test)
{
	Guesser guess("This is a beautiful day at chico. The winter has just ended and spring has begun");
	bool val = guess.match("Hello World!");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, guess_len32_plus_test)
{
	Guesser guess("This is a beautiful day at chico. The winter has just ended and spring has begun");
	bool val = guess.match("This is a beautiful day at chico. The winter has just ended and spring has begun and some extra words.");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, empty_string_test)
{
	Guesser guess("");
	bool val = guess.match("Hello World!");
    ASSERT_EQ(false, val);
}

TEST(GuesserTest, empty_stringV2_test)
{
	Guesser guess("");
	bool val = guess.match("");
    ASSERT_EQ(true, val);
}

TEST(GuesserTest, reset_remaining_test)
{
	Guesser guess("Hello World!");
	guess.match("Hello World!");
	guess.match("Hello World!");
	guess.match("Hello World!");
	guess.match("Hello World!");
	guess.match("Hello World!");
	guess.match("Hello World!");
	int val = guess.remaining();
    ASSERT_EQ(3, val);
}