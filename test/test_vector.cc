#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include "../include/Vector.h"
#include "../include/Algorithm.h"

TEST_CASE("vector_test_element_access")
{
    learncpp::vector<int> vec{1, 2, 3};
    REQUIRE_THROWS_AS(vec.at(-1), std::out_of_range);
    CHECK(1 == vec.at(0));
    CHECK(2 == vec.at(1));
    CHECK(3 == vec.at(2));
    REQUIRE_THROWS_AS(vec.at(3), std::out_of_range);

    CHECK(1 == vec[0]);
    CHECK(2 == vec[1]);
    CHECK(3 == vec[2]);

    CHECK(1 == vec.front());
    CHECK(3 == vec.back());

    int* data = vec.data();
    CHECK(1 == data[0]);
    CHECK(2 == data[1]);
    CHECK(3 == data[2]);
}

TEST_CASE("vector_test_iterators")
{
    learncpp::vector<int> vec{1, 2, 3};

    int i = 1;
    for(const auto& val : vec)
    {
        CHECK(i == val);
        ++i;
    }

    CHECK(vec.begin() != vec.end());
    vec.clear();
    CHECK(vec.begin() == vec.end());

    vec.shrink_to_fit();
    CHECK(vec.begin() == vec.end());

    vec.push_back(1);
    CHECK(vec.begin() != vec.end());
}

TEST_CASE("vector_test_capacity")
{
    learncpp::vector<int> vec{1, 2, 3};
    CHECK(3 == vec.size());
    CHECK(3 == vec.capacity());

    vec.clear();
    CHECK(0 == vec.size());
    CHECK(3 == vec.capacity());

    vec.shrink_to_fit();
    CHECK(0 == vec.size());
    CHECK(0 == vec.capacity());
}

/**
 * @brief Test PushBack and PopBack
 * 
 */
TEST_CASE("vector_test_modifiers1")
{
    learncpp::vector<int> vec;
    CHECK(0 == vec.size());
    CHECK(0 == vec.capacity());

    vec.push_back(1);
    CHECK(1 == vec.size());
    CHECK(1 == vec.capacity());

    vec.pop_back();
    CHECK(0 == vec.size());
    CHECK(1 == vec.capacity());

    int val = 42;
    vec.push_back(val);
    CHECK(1 == vec.size());
    CHECK(1 == vec.capacity());
    CHECK(42 == vec[0]);

    vec.resize(2);
    CHECK(2 == vec.size());
    CHECK(2 == vec.capacity());
    CHECK(42 == vec[0]);
    CHECK(0 == vec[1]);
}

/**
 * @brief Test: Emplace, EmplaceBack, Insert
 * 
 */
TEST_CASE("vector_test_modifiers2")
{
    learncpp::vector<int> vec;
    
}

TEST_CASE("vector_test_algorithms")
{
    learncpp::vector<double> vec{1, 2, 3};

    CHECK(6.0 == learncpp::sum(vec));
    CHECK(2.0 == learncpp::mean(vec));
    Approx target_variance = Approx(0.6666666666666666).epsilon(1e-6);
    CHECK(target_variance == learncpp::variance(vec));
    Approx target_std = Approx(0.816496580927726).epsilon(1e-6);
    CHECK(target_std == learncpp::stddev(vec));
}