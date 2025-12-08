#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/sorter_tester.cpp"

TEST_CASE("check if std::sort with no comparator sorts ascending") {
    std::array<int, 10> arr;
    sorter_tester::reset(arr);

    std::sort(arr.begin(), arr.end());

    std::array<int, 10> compare_array = {0,1,2,3,4,5,6,7,8,9};
    REQUIRE(arr == compare_array);
}

TEST_CASE("check if std::greater sorts descending") {
    std::array<int, 10> arr;
    sorter_tester::reset(arr);

    std::sort(arr.begin(), arr.end(), std::greater<int>());

    std::array<int, 10> compare_array = {9,8,7,6,5,4,3,2,1,0};
    REQUIRE(arr == compare_array);
}

TEST_CASE("check if std::less sorts ascending") {
    std::array<int, 10> arr;
    sorter_tester::reset(arr);

    std::sort(arr.begin(), arr.end(), std::less<int>());

    std::array<int, 10> compare_array = {0,1,2,3,4,5,6,7,8,9};
    REQUIRE(arr == compare_array);
}

TEST_CASE("check if lambda a > b sorts descending") {
    std::array<int, 10> arr;
    sorter_tester::reset(arr);

    std::sort(arr.begin(), arr.end(),
              [](int a, int b){ return a > b; });

    std::array<int, 10> compare_array = {9,8,7,6,5,4,3,2,1,0};
    REQUIRE(arr == compare_array);
}

TEST_CASE("check if lambda a < b sorts ascending") {
    std::array<int, 10> arr;
    sorter_tester::reset(arr);

    std::sort(arr.begin(), arr.end(),
              [](int a, int b){ return a < b; });

    std::array<int, 10> compare_array = {0,1,2,3,4,5,6,7,8,9};
    REQUIRE(arr == compare_array);
}

TEST_CASE("check if custom struct less sorts ascending") {
    std::array<int, 10> arr;
    sorter_tester::reset(arr);

    struct Less {
        bool operator()(int a, int b) const { return a < b; }
    };

    std::sort(arr.begin(), arr.end(), Less());

    std::array<int, 10> compare_array = {0,1,2,3,4,5,6,7,8,9};
    REQUIRE(arr == compare_array);
}

TEST_CASE("check if custom struct greater sorts descending") {
    std::array<int, 10> arr;
    sorter_tester::reset(arr);

    struct Greater {
        bool operator()(int a, int b) const { return a > b; }
    };

    std::sort(arr.begin(), arr.end(), Greater());

    std::array<int, 10> compare_array = {9,8,7,6,5,4,3,2,1,0};
    REQUIRE(arr == compare_array);
}
