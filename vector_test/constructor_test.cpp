#include <iostream>
#include "vector.hpp"
#include "iterator.hpp"
 
template<typename T>
std::ostream& operator<<(std::ostream& s, const ft::vector<T>& v) 
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v)
    {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}
 
int main() 
{
    ft::vector<std::string> words1;
	words1.push_back("the");
	words1.push_back("frogurt");
	words1.push_back("is");
	words1.push_back("also");
	words1.push_back("cursed");
    std::cout << "words1: " << words1 << '\n';
 
    // words2 == words1
    ft::vector<std::string> words2(words1.begin(), words1.end());
    std::cout << "words2: " << words2 << '\n';
 
    // words3 == words1
    ft::vector<std::string> words3(words1);
     std::cout << "words3: " << words3 << '\n';
 
    // // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
   ft::vector<std::string> words4(5, "Mo");
   std::cout << "words4: " << words4 << '\n';
}