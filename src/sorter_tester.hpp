#pragma once

#include <iostream>
#include <array>
#include <algorithm>

class sorter_tester
{
public:
    static void print_array(const std::array<int, 10>& arr, const std::string& title)
    {
        std::cout << title << ": ";
        for (int n : arr) std::cout << n << " ";
        std::cout << std::endl << std::endl;
    }

    static void reset(std::array<int, 10>& arr)
    {
        arr = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    }

    static void run_all_tests()
    {
        std::array<int, 10> arr;

        reset(arr);
        std::sort(arr.begin(), arr.end());
        print_array(arr, "No third argument");

        reset(arr);
        std::sort(arr.begin(), arr.end(), std::greater<int>());
        print_array(arr, "The less function built into C++");

        reset(arr);
        std::sort(arr.begin(), arr.end(), std::less<int>());
        print_array(arr, "The greater function built into C++");

        reset(arr);
        std::sort(arr.begin(), arr.end(), [](int a, int b){ return a > b; });
        print_array(arr, "A lambda comparing two integer arguments with cases for greater than");

        reset(arr);
        std::sort(arr.begin(), arr.end(), [](int a, int b){ return a < b; });
        print_array(arr, "A lambda comparing two integer arguments with cases for less than");

        reset(arr);

        struct less
        {
            bool operator()(int a, int b) const
            {
                return a < b;
            }
        };

        std::sort(arr.begin(), arr.end(), less());
        print_array(arr, "A custom struct comparing two integer arguments with case for greater than");


        reset(arr);

        struct greater
        {
            bool operator()(int a, int b) const
            {
                return a > b;
            }
        };

    std::sort(arr.begin(), arr.end(), greater());
    print_array(arr, "A custom struct comparing two integer arguments with case for less than");

    }
};
