#include <array>

#include "src/sorter_tester.cpp"

int main()
{
  std::array<int, 10> my_numbers{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
 
  std::sort(my_numbers.begin(), my_numbers.end());
  std::sort(my_numbers.begin(), my_numbers.end(), std::greater<int>());
  std::sort(my_numbers.begin(), my_numbers.end(), std::less<int>());
  std::sort(my_numbers.begin(), my_numbers.end(), [](int a, int b)
            { return a > b; });
  std::sort(my_numbers.begin(), my_numbers.end(), [](int a, int b)
            { return a < b; });
 
  struct
  {
    bool operator()(int a, int b) const { return a < b; }
  } custom_less;
 
  std::sort(my_numbers.begin(), my_numbers.end(), custom_less);
 
  struct
  {
    bool operator()(int a, int b) const { return a > b; }
  } custom_greater;
 
  std::sort(my_numbers.begin(), my_numbers.end(), custom_greater);

  sorter_tester::run_all_tests();
}
