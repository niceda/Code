#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int p1, p2;
      for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
          if(nums[i] + nums[j] == target)
            p1 = i; p2 = j;
      }
    }
    return vector<int>{p1 , p2};
    }
};
