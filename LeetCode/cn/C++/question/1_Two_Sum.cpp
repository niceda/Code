// @algorithm @lc id=1 lang=cpp
// @title two-sum

#include "../algm/algm.h"
// @test([2,7,11,15],9)=[0,1]
// @test([3,2,4],6)=[1,2]
// @test([3,3],6)=[0,1]
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
      for (int i = 0; i < nums.size(); i++) {
          for (int j = i + 1; j < nums.size(); j++) {
              if (nums[i] + nums[j] == target)
                return {i, j};
          }
      }
      return vector<int>();
  }
};