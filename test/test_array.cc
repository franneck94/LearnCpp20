#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include "../include/Array.h"

TEST_CASE("array_test_element_access")
{
    learncpp::array<int, 3> arr{1, 2, 3};
    REQUIRE_THROWS_AS(arr.at(-1), std::out_of_range);
    CHECK(1 == arr.at(0));
    CHECK(2 == arr.at(1));
    CHECK(3 == arr.at(2));
    REQUIRE_THROWS_AS(arr.at(3), std::out_of_range);

    CHECK(1 == arr[0]);
    CHECK(2 == arr[1]);
    CHECK(3 == arr[2]);

    CHECK(1 == arr.front());
    CHECK(3 == arr.back());

    int* data = arr.data();
    CHECK(1 == data[0]);
    CHECK(2 == data[1]);
    CHECK(3 == data[2]);
}

TEST_CASE("array_test_iterators")
{
    learncpp::array<int, 3> arr{1, 2, 3};

    int i = 1;
    for(const auto& val : arr)
    {
        CHECK(i == val);
        ++i;
    }
}

TEST_CASE("array_test_capacity")
{
    learncpp::array<int, 3> arr{1, 2, 3};

    CHECK(3 == arr.size());
    CHECK(false == arr.empty());
}

TEST_CASE("array_test_modifiers")
{
    learncpp::array<int, 3> arr{1, 2, 3};
    arr.fill(42);

    CHECK(42 == arr[0]);
    CHECK(42 == arr[1]);
    CHECK(42 == arr[2]);
}