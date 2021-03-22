/*
 * Description:
 * Given a none-empty array of integers, every element apears twice except one.
 * Find that single one
 */
#include <vector>
#include <numeric>
#include <iostream>
class Solution {
public:
   int singleNumber(std::vector<int>& nums);

};

int Solution::singleNumber(std::vector<int>& nums)
{
   return std::accumulate(nums.cbegin(), nums.cend(),
                          0, std::bit_xor<int>());
}


int main()
{
   Solution mySolution;
   std::vector<int> ivec;

   ivec.push_back(2);
   ivec.push_back(2);
   ivec.push_back(1);
   int res = mySolution.singleNumber(ivec);
   std::cout << "First result: " << res << std::endl;

   ivec.clear();

   ivec.push_back(4);
   ivec.push_back(1);
   ivec.push_back(1);
   ivec.push_back(2);
   ivec.push_back(2);
   res = mySolution.singleNumber(ivec);
   std::cout << "Second result: " << res << std::endl;

   return 0;   
}
