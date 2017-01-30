#include <siminusminus/containers/inmutablestring.hpp>
#include <gmock/gmock.h>

using namespace ::testing;
using namespace ::cmm::containers;

/////////////////
// Initialization
/////////////////

TEST(initialization, voidConstructor)
{
	InmutableString str1;
	EXPECT_TRUE(str1 == "");
}

TEST(initialization, constructWithCString)
{
	InmutableString str("Hello");
	EXPECT_TRUE(str == "Hello");
}

TEST(initialization, constructWithInmutableString)
{
	InmutableString str("Hello");
	InmutableString str1 = str;
	EXPECT_TRUE(str1 == "Hello");
}

TEST(initialization, stdStringObject)
{
	InmutableString str("Hello");
	std::string string("Hello");
	EXPECT_TRUE(str.toString() == string);
}

////////////
// Operators
////////////

TEST(operators, assignmentOperator)
{
	InmutableString str("Hello");
	InmutableString str1;
	str1 = str;
	EXPECT_TRUE(str1 == "Hello");
}

TEST(operators, concatTwoVoidString)
{
	InmutableString str;
	InmutableString str1;
	InmutableString str2;
	str = str1 + str2; 
	EXPECT_TRUE(str2 == "");
}

TEST(operators, concatVoidString)
{
	InmutableString str;
	InmutableString str1("Hello");
	InmutableString str2;
	str2 = str + str1; 
	EXPECT_TRUE(str2 == "Hello");
}

TEST(operators, concatStringVoid)
{
	InmutableString str("Hello");
	InmutableString str1;
	InmutableString str2;
	str2 = str + str1; 
	EXPECT_TRUE(str2 == "Hello");
}

TEST(operators, concatStringString)
{
	InmutableString str("Hello ");
	InmutableString str1("World");
	InmutableString str2;
	str2 = str + str1; 
	EXPECT_TRUE(str2 == "Hello World");
}

TEST(operators, getNElement)
{
	InmutableString str("Hello");
	EXPECT_TRUE(str[0] == 'H' &&
		        str[1] == 'e' &&
		        str[2] == 'l' &&
		        str[3] == 'l' &&
		        str[4] == 'o');
}

TEST(operators, isEqual)
{
	InmutableString str1("HelloWorld");
	InmutableString str2("HelloWorld");
	EXPECT_TRUE(str1 == str2);
}

TEST(operators, greatherThan)
{
	InmutableString str1("Hello World");
	InmutableString str2("HelloWorld");
	EXPECT_TRUE(str1 > str2);
}

TEST(operators, lessThan)
{
	InmutableString str1("HelloWorld");
	InmutableString str2("Hello World");
	EXPECT_TRUE(str1 < str2);
}

