#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "reverse_iterator.hpp"
 
int main()
{
    std::vector<int> v {0, 1, 2, 3, 4};
    auto rv = ft::reverse_iterator<int> {v.rbegin()};
    std::cout << *(++rv) << ' '; // 3
    std::cout << *(--rv) << ' '; // 4
    std::cout << *(rv + 3) << ' '; // 1
    rv += 3;
    std::cout << rv[0] << ' '; // 1
    rv -= 3;
    std::cout << rv[0] << '\n'; // 4
 
    std::list<int> l {5, 6, 7, 8};
    auto rl = ft::reverse_iterator<int> {l.rbegin()};
    std::cout << *(++rl) << ' '; // OK: 3
    std::cout << *(--rl) << ' '; // OK: 4
    // The following statements raise compilation error because the
    // underlying iterator does not model the random access iterator:
//  *(rl + 3) = 13;
//  rl += 3;
//  rl -= 3;
}