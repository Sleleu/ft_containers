// inserting into a vector
#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"

using namespace ft;

int main ()
{
  vector<int> myvector (3,100);
  vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 ); // 1 insert

 myvector.insert (it,2,300); // 2 insert

  // "it" no longer valid, get a new one:
   it = myvector.begin();

  vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}