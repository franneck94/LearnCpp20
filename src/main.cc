#include <type_traits>
#include <iostream>
#include <vector>

#include "../include/Vector.h"

int main()
{
    learncpp::vector<int> vec1{1, 2, 3};
    learncpp::vector<int> vec2{10, 10, 10};
    
    const auto it = vec1.begin();
    vec1.insert(it, vec2.begin(), vec2.end());

    for(const auto& val : vec1)
    {
        std::cout << val << std::endl;
    }

}