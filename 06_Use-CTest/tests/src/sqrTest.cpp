
#include "sqr.hpp"
#include "catch.hpp"

TEST_CASE("Main Test", "[TEST]")
{
    SECTION("Square Test")
    {
        REQUIRE(4 == sqr(2));
        REQUIRE(9 == sqr(3));
    }
}