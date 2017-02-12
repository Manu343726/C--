#include <siminusminus/containers/inmutablestring.hpp>
#include <gmock/gmock.h>

using namespace ::testing;
using namespace ::cmm::containers;
using namespace ::cmm::utils;

///////////////////
// InmutableString
///////////////////

TEST(InmutableString_initialization, voidConstructor)
{
    InmutableString str1;
    EXPECT_EQ(str1, "");
}

TEST(InmutableString_initialization, constructWithCString)
{
    InmutableString str("Hello");
    EXPECT_EQ(str, "Hello");
}

TEST(InmutableString_initialization, moveContructor)
{
    InmutableString str1 ("Hello");
    InmutableString str2 ("World");
    InmutableString str = str1 + str2;
    EXPECT_EQ(str, "HelloWorld");
}

TEST(InmutableString_initialization, constructWithInmutableString)
{
    InmutableString str("Hello");
    InmutableString str1 = str;
    EXPECT_EQ(str1, "Hello");
}

TEST(InmutableString_initialization, stdStringObject)
{
    InmutableString str("Hello");
    std::string string("Hello");
    EXPECT_EQ(str.toString(), string);
}

TEST(InmutableString_operators, assignmentOperator)
{
    InmutableString str("Hello");
    InmutableString str1;
    str1 = str;
    EXPECT_EQ(str1, "Hello");
}

TEST(InmutableString_operators, moveAssignmentOperator)
{
    InmutableString str("Hello");
    InmutableString str1(" C--");
    InmutableString str2;
    str2 = str + str1;
    EXPECT_EQ(str2, "Hello C--");
}

TEST(InmutableString_operators, concatTwoVoidString)
{
    InmutableString str;
    InmutableString str1;
    InmutableString str2;
    str = str1 + str2; 
    EXPECT_EQ(str2, "");
}

TEST(InmutableString_operators, concatVoidString)
{
    InmutableString str;
    InmutableString str1("Hello");
    InmutableString str2;
    str2 = str + str1; 
    EXPECT_EQ(str2, "Hello");
}

TEST(InmutableString_operators, concatStringVoid)
{
    InmutableString str("Hello");
    InmutableString str1;
    InmutableString str2;
    str2 = str + str1; 
    EXPECT_EQ(str2, "Hello");
}

TEST(InmutableString_operators, concatStringString)
{
    InmutableString str("Hello ");
    InmutableString str1("World");
    InmutableString str2;
    str2 = str + str1; 
    EXPECT_EQ(str2, "Hello World");
}

TEST(InmutableString_operators, getNElement)
{
    InmutableString str("Hello");
    EXPECT_EQ(str[0], 'H');
    EXPECT_EQ(str[1], 'e');
    EXPECT_EQ(str[2], 'l');
    EXPECT_EQ(str[3], 'l');
    EXPECT_EQ(str[4], 'o');
}

TEST(InmutableString_operators, isEqual)
{
    InmutableString str1("HelloWorld");
    InmutableString str2("HelloWorld");
    EXPECT_EQ(str1, str2);
}

TEST(InmutableString_operators, greaterThan)
{
    InmutableString str1("dabc");
    InmutableString str2("cbda");
    EXPECT_GT(str1, str2);
}

TEST(InmutableString_operators, lessThan)
{
    InmutableString str1("acdb");
    InmutableString str2("cdab");
    EXPECT_LT(str1, str2);
}

TEST(InmutableString_operators, lessOrEqualThan)
{
    InmutableString str1("abcd");
    InmutableString str2("abcd");
    InmutableString str3("dbcd");
    EXPECT_LE(str1, str2);
    EXPECT_LE(str1, str3);
}

TEST(InmutableString_operators, greaterOrEqualThan)
{
    InmutableString str1("abcd");
    InmutableString str2("abcd");
    InmutableString str3("aacd");
    EXPECT_GE(str1, str2);
    EXPECT_GE(str1, str3);
}

////////////////////////////////////////
// InmutableIterator & Inmutable Viewer
////////////////////////////////////////

TEST(InmutableStringIterator_increment, preincrement)
{
    InmutableString istring("Hello");

    InmutableIterator<char> iitbegin (istring[0]);
    InmutableIterator<char> iitend (istring[6]);// [0 --> H, ... ,
                                                // 4 --> o, 
                                                // 5 --> '\0', 
                                                // 6 --> Represent the iterator end]
    InmutableViewer<char> viewer (iitbegin, iitend);

    auto it = viewer.begin();
    size_t pos = 0;

    while (it != viewer.end())
    {
        EXPECT_EQ(istring[pos], *it);
        InmutableIterator<char> itaux(++it);
        DebugUtilities::log("Pos " + std::to_string(pos) + "  -> " + *itaux);
        ++pos;
    }
}

TEST(InmutableStringIterator_increment, postincrement)
{
    InmutableString istring("Hello");

    InmutableIterator<char> iitbegin (istring[0]);
    InmutableIterator<char> iitend (istring[6]);// [0 --> H, ... ,
                                                // 4 --> o, 
                                                // 5 --> '\0', 
                                                // 6 --> Represent the iterator end]
    InmutableViewer<char> viewer (iitbegin, iitend);

    auto it = viewer.begin();
    size_t pos = 0;

    while (it != viewer.end())
    {
        EXPECT_EQ(istring[pos], *it);
        InmutableIterator<char> itaux(it++);
        DebugUtilities::log("Pos " + std::to_string(pos) + "  -> " + *itaux);
        ++pos;
    }
}

TEST(InmutableStringIterator_operators, equalOrNotEqual)
{
    InmutableString istring("Testing this stuff");
    InmutableIterator<char> istringit1 (istring[0]);
    InmutableIterator<char> istringit2 (istring[0]);

    EXPECT_EQ(*istringit1, *istringit2);

    ++istringit1;
    EXPECT_NE(*istringit1, *istringit2);

    ++istringit2;
    EXPECT_EQ(*istringit1, *istringit2);
}